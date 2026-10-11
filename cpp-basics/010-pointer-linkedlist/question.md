# 010 · 指標與 Linked List — 練習題

> 先讀 notes.md。完成後執行 `make run Q=010`，全部 PASS 即完成。

所有程式碼都在 `main.cpp` 裡，把 `// TODO: 實作` 換成你的程式碼即可。這一題**不使用** `lc/structures.hpp`，`ListNode` 由你自己完成。

⚠️ 請**照順序**做：Task B 的 `buildList` / `toVector` / `freeList` 會被後面所有測試使用，B 沒過的話 C～E 也不會過。

`ListNode::alive` 是測試用的計數器（建構子 +1、解構子 -1），測試靠它檢查「有沒有多 new」和「有沒有 delete 乾淨」。**不要刪掉建構子裡的 `alive++`。**

---

## Task A：ListNode 建構子與走訪（★）

完成兩個建構子（預設建構子已完成，當作範例），以及兩個走訪函式：

```cpp
ListNode(int x);                         // val = x, next = nullptr
ListNode(int x, ListNode* nxt);          // val = x, next = nxt

int length(const ListNode* head);        // 串列長度，head 可能是 nullptr
ListNode* findFirst(ListNode* head, int target);  // 第一個 val == target 的節點，找不到回傳 nullptr
```

範例：

```
ListNode c(3); ListNode b(2, &c); ListNode a(1, &b);    // a → b → c → nullptr
length(&a)          → 3
length(nullptr)     → 0
findFirst(&a, 2)    → &b      （回傳的是「那個節點的位址」，不是新節點）
findFirst(&a, 9)    → nullptr
```

練到的概念：member initializer list、`&` 取位址、`->`、`nullptr`、`for (p = head; p != nullptr; p = p->next)` 走訪、`const ListNode*`

---

## Task B：vector ↔ linked list，以及 delete（★★）

```cpp
ListNode* buildList(const vector<int>& vals);  // 用 new 依序建立節點，空 vector 回傳 nullptr
vector<int> toVector(const ListNode* head);    // 依序收集 val
void freeList(ListNode* head);                 // delete 每一個節點
```

範例：

```
buildList({1, 2, 3})             → 1 → 2 → 3 → nullptr     （alive = 3）
toVector(1 → 2 → 3)              → {1, 2, 3}
freeList(head)                   → alive 回到 0
buildList({})                    → nullptr
```

練到的概念：`new`、`delete`、維護 `head` 和 `tail` 兩個指標、「先存 next 再 delete」

提示：`buildList` 要讓順序和 `vals` 一樣（不是反過來）。想一想：每次都把新節點接在哪裡？需要記住哪個節點？

---

## Task C：快慢指標找中點（★★）

```cpp
ListNode* middleNode(ListNode* head);   // 偶數長度回傳「第二個」中間節點；空串列回傳 nullptr
```

範例：

```
1 → 2 → 3 → 4 → 5        → 節點 3（toVector 結果是 {3, 4, 5}）
1 → 2 → 3 → 4 → 5 → 6    → 節點 4
1 → 2                    → 節點 2
nullptr                  → nullptr
```

練到的概念：快慢指標（fast 一次走兩步、slow 一次走一步）、`&&` 短路求值、回傳「原本串列中的節點」而不是 new 一個

提示：只走一趟，不要先算長度。迴圈條件寫錯的話 sanitizer 會告訴你。

---

## Task D：插入節點（head 會變怎麼辦？）（★★）

```cpp
void pushFront(ListNode*& head, int val);             // 插在最前面，直接改呼叫端的 head
ListNode* insertAt(ListNode* head, int pos, int val); // 讓 val 成為第 pos 個節點（0-based），回傳新 head
```

`insertAt` 規則：`pos == 長度` → 接在最後；`pos < 0` 或 `pos > 長度` → 不插入（也**不能 new**），原樣回傳。

範例：

```
h = nullptr; pushFront(h, 3); pushFront(h, 2); pushFront(h, 1);   → 1 → 2 → 3
insertAt(1 → 2 → 3, 0, 0)       → 0 → 1 → 2 → 3       （head 換人了）
insertAt(0 → 1 → 2 → 3, 2, 9)   → 0 → 1 → 9 → 2 → 3
insertAt(..., 7, 8)             → 不變（超出範圍）
insertAt(nullptr, 0, 5)         → 5
```

練到的概念：`ListNode*&`（指標的參考）vs 回傳新 head、找到「插入位置的前一個節點」、邊界檢查

提示：`pos == 0` 跟其他位置的差別在於「前一個節點不存在」。Task E 會介紹一個讓這種情況消失的技巧，你也可以先用在這裡。

---

## Task E：dummy head — 刪除所有指定值（★★★）

LeetCode 203。刪掉所有 `val == target` 的節點，**被刪掉的節點要 `delete`**，回傳新的 head。

```cpp
ListNode* removeElements(ListNode* head, int target);
```

範例：

```
1 → 2 → 6 → 3 → 4 → 5 → 6,  target = 6   → 1 → 2 → 3 → 4 → 5   （alive = 5）
1 → 1 → 2 → 1 → 3,          target = 1   → 2 → 3
7 → 7 → 7 → 7,              target = 7   → nullptr
nullptr,                    target = 1   → nullptr
```

練到的概念：dummy head（`ListNode dummy(0, head);` 放在 stack 上）、用 `prev->next` 操作、刪除時「先接好再 delete」、use-after-free

提示：用 dummy 之後，「刪 head」和「刪中間」就是同一件事。刪掉一個節點之後，`prev` 要不要往前走？想想連續兩個都要刪的情況。

---

## 完成檢查

- [ ] `make run Q=010` 全部 PASS
- [ ] 沒有任何 sanitizer 錯誤訊息（`runtime error` / `AddressSanitizer`）
- [ ] 用 `leaks` 確認沒有洩漏（指令見 notes.md「檢查記憶體洩漏」，要看到 `0 leaks for 0 total leaked bytes`）
- [ ] 能說出每個 Task 用到的概念（特別是：`.` 和 `->` 差在哪？為什麼 `pushFront` 要用 `ListNode*&`？dummy head 解決了什麼問題？）
