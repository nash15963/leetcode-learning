# 010 · 指標與 Linked List

## 這一課學什麼

- 自己定義 `ListNode`（`val` / `next` + 建構子），這就是 LeetCode 給你的那個 struct
- 指標基本功：`&` 取位址、`*` 解參考、`->` 透過指標存取成員、`nullptr`
- `new` 建立節點、`delete` 釋放節點；用 ASan 抓 use-after-free，用 `leaks` 抓記憶體洩漏
- 走訪、`vector` ↔ linked list 互轉、快慢指標找中點
- head 可能改變時的三種處理：回傳新 head、`ListNode*&`、**dummy head**

## 語法速查

```cpp
struct ListNode {
    int val;
    ListNode* next;                          // 指向下一個節點的指標
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
};

// ---- 指標基本功 ----
ListNode n(5);           // n 是物件（在 stack 上）
ListNode* p = &n;        // p 存的是 n 的位址
p->val = 6;              // 等同 (*p).val = 6
ListNode* q = nullptr;   // 「不指向任何東西」；不能 q->val

// ---- new / delete ----
ListNode* h = new ListNode(1, new ListNode(2));  // 在 heap 上建立，函式結束後還在
delete h->next;          // 每個 new 都要剛好對應一個 delete
delete h;

// ---- 走訪（const ListNode*：只讀不改）----
for (const ListNode* cur = head; cur != nullptr; cur = cur->next) {
    cout << cur->val << " ";
}

// ---- 一邊走一邊 delete：先存 next 再 delete ----
while (head != nullptr) {
    ListNode* nxt = head->next;
    delete head;
    head = nxt;
}

// ---- 快慢指標：fast 一次兩步、slow 一次一步 ----
ListNode* slow = head;
ListNode* fast = head;
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
}   // 結束時 slow 在中點

// ---- dummy head：讓「刪 / 插 head」跟其他節點一樣處理 ----
ListNode dummy(0, head);      // dummy 在 stack 上，函式結束自動消失
ListNode* prev = &dummy;
// ... 操作 prev->next ...
return dummy.next;            // 真正的新 head

// ---- 想在函式裡「改掉呼叫端的 head」→ 傳指標的參考 ----
void pushFront(ListNode*& head, int v) { head = new ListNode(v, head); }
```

### 圖解：pushFront(head, 0)

```
之前：
  head
   |
   v
 +---+---+     +---+---+     +---+------+
 | 1 | *-+---->| 2 | *-+---->| 3 | null |
 +---+---+     +---+---+     +---+------+
  val next

之後（新節點的 next 指向舊 head，再讓 head 指向新節點）：
  head
   |
   v
 +---+---+     +---+---+     +---+---+     +---+------+
 | 0 | *-+---->| 1 | *-+---->| 2 | *-+---->| 3 | null |
 +---+---+     +---+---+     +---+---+     +---+------+
```

### 檢查記憶體洩漏（macOS）

macOS arm64 上的 ASan **沒有** leak detection，忘記 `delete` 不會有任何訊息。另外編一份**不加 sanitizer** 的版本給 `leaks` 檢查：

```bash
clang++ -std=c++20 -g -O0 -Iinclude cpp-basics/010-pointer-linkedlist/main.cpp -o tmp/build/010-leaks
leaks -q --atExit -- tmp/build/010-leaks
```

- 沒洩漏：最後會看到 `Process 12345: 0 leaks for 0 total leaked bytes.`
- 有洩漏：`3 leaks for 48 total leaked bytes.`，下面的 `STACK OF ...` 會指出是哪一行 `new` 出來的（例如 `buildList(...) main.cpp:57`）
- ⚠️ 不能直接拿 `make run` 編出來的 ASan 版本跑 `leaks`：ASan 換掉了 malloc，`leaks` 永遠回報 0 leaks（假陰性）
- 開頭的 `Process ... is not debuggable` 可以忽略

`main.cpp` 的測試則用另一招：`ListNode` 裡有一個 `inline static int alive`（所有節點共用的一個計數器），建構子 `+1`、解構子 `-1`。全部 delete 乾淨的話，它會回到 0。

## 常見坑

1. **對 `nullptr` 用 `->`**：UBSan 印 `runtime error: member access within null pointer of type 'ListNode'`，接著 ASan `SEGV`

   ```cpp
   while (cur->next != nullptr) { ... }      // ❌ cur 本身是 nullptr 時直接炸
   while (cur != nullptr) { ... }            // ✅ 先確認 cur 不是 nullptr
   ```

2. **delete 之後還在用（use-after-free）**：ASan 印 `heap-use-after-free`

   ```cpp
   delete cur; cur = cur->next;                          // ❌ cur 已經被釋放
   ListNode* nxt = cur->next; delete cur; cur = nxt;     // ✅ 先存 next
   ```

3. **忘記 delete 被移除的節點** → 記憶體洩漏（ASan 在 macOS 抓不到，要用 `leaks`）

   ```cpp
   prev->next = prev->next->next;                                       // ❌ 被跳過的節點沒人管了
   ListNode* d = prev->next; prev->next = d->next; delete d;            // ✅
   ```

4. **head 被換掉，但呼叫端不知道**

   ```cpp
   void pushFront(ListNode* head, int v) { head = new ListNode(v, head); }   // ❌ 改到的是複本
   void pushFront(ListNode*& head, int v) { head = new ListNode(v, head); }  // ✅ 或回傳新 head
   ```

5. **一行宣告兩個指標**

   ```cpp
   ListNode* a, b;        // ❌ b 是 ListNode 物件，不是指標
   ListNode *a, *b;       // ✅ 或分兩行寫
   ```

6. **回傳 stack 物件的位址 / delete stack 物件**

   ```cpp
   ListNode node(5); return &node;      // ❌ 函式結束 node 就消失了（dangling pointer）
   ListNode dummy; delete &dummy;       // ❌ ASan：attempting free on address which was not malloc()-ed
   return new ListNode(5);              // ✅ 要活到函式外面的節點用 new
   ```

7. **快慢指標的迴圈條件只檢查一半**

   ```cpp
   while (fast->next != nullptr)                        // ❌ fast 可能已經是 nullptr
   while (fast != nullptr && fast->next != nullptr)     // ✅ && 會短路，順序不能反
   ```

## 在 LeetCode 會怎麼用

- LeetCode 已經幫你定義好 `ListNode`，函式簽名長得像 `ListNode* f(ListNode* head)`，**回傳新的 head**。
- 只要「head 可能被刪掉 / 換掉」就先開 `ListNode dummy(0, head);`，最後 `return dummy.next;`，幾乎不用寫特殊判斷。
- 快慢指標：找中點、判斷有沒有環、找倒數第 k 個節點都用得到。
- LeetCode 的評測不檢查記憶體洩漏，很多人不 delete；但在本機練習時養成 delete 的習慣，面試會加分。

## 參考

- [Pointer declaration](https://en.cppreference.com/w/cpp/language/pointer)
- [Member access operators（`.` 與 `->`）](https://en.cppreference.com/w/cpp/language/operator_member_access)
- [new expression](https://en.cppreference.com/w/cpp/language/new) / [delete expression](https://en.cppreference.com/w/cpp/language/delete)
- [nullptr](https://en.cppreference.com/w/cpp/language/nullptr)
- [Reference declaration（`ListNode*&`）](https://en.cppreference.com/w/cpp/language/reference)
- [Static members（`inline static`）](https://en.cppreference.com/w/cpp/language/static)
- [AddressSanitizer](https://clang.llvm.org/docs/AddressSanitizer.html)
