# 007 · 堆疊、佇列、雙端佇列、優先佇列 — 練習題

> 先讀 notes.md。完成後執行 `make run Q=007`，全部 PASS 即完成。

所有函式都在 `main.cpp` 裡，把 `// TODO: 實作` 換成你的程式碼即可。每個 Task 請使用標題指定的容器。

---

## Task A：stack 基本 — 退格字串（★）

```cpp
string applyBackspace(const string& s);
```

`'#'` 代表退格：刪掉前一個還沒被刪的字元；如果前面沒有字元可刪就忽略。回傳處理後的字串。

範例：

```
"ab#c"   → "ac"
"abc##"  → "a"
"a##b"   → "b"     （第二個 # 前面已經沒字元了，忽略）
"###"    → ""
```

練到的概念：`stack<char>` 的 `push` / `top` / `pop` / `empty`、pop 之前先檢查是否為空、從 stack 取出的順序是反的

提示：把 stack 倒出來組字串時，順序會顛倒，記得處理。

---

## Task B：stack — 後序運算式計算機（RPN）（★★）

```cpp
int evalRPN(const vector<string>& tokens);
```

後序運算式（Reverse Polish Notation）：運算子寫在兩個運算元後面。遇到數字就 push，遇到運算子就 pop 兩個數字計算後再 push 回去。運算子只有 `+ - * /`，除法向 0 取整（C++ 的 `/` 本來就是這樣）。輸入保證合法。

範例：

```
{"2", "1", "+", "3", "*"}     → 9     （(2 + 1) * 3）
{"4", "13", "5", "/", "+"}    → 6     （4 + 13 / 5）
{"5", "3", "-"}               → 2     （不是 -2）
{"7", "-2", "/"}              → -3    （"-2" 是數字，不是運算子）
{"42"}                        → 42
```

練到的概念：`stack<int>`、`stoi` 字串轉整數、字串比對、運算元的 pop 順序

---

## Task C：queue 模擬（★★）

```cpp
int hotPotato(int n, int k);
vector<int> recentCounts(const vector<int>& times, int window);
```

- `hotPotato`：編號 1～n 的人依序圍成一圈，從排頭開始數 1、2、…、k，**數到 k 的人出局**，下一個人重新從 1 開始數。回傳最後留下的人的編號。
- `recentCounts`：`times` 是遞增的請求時間。對每個時間 `t`，回傳時間落在 `[t - window, t]` 內的請求數量（包含 `t` 自己）。

範例：

```
hotPotato(5, 2)  → 3     （出局順序：2, 4, 1, 5，剩下 3）
hotPotato(6, 1)  → 6
hotPotato(1, 3)  → 1
recentCounts({1, 100, 3001, 3002}, 3000)  → {1, 2, 3, 3}
recentCounts({1, 2, 10, 11, 12}, 2)       → {1, 2, 1, 2, 3}
```

練到的概念：`queue<int>` 的 `push` / `front` / `pop`、「front 拿出來再 push 到後面」模擬繞圈、從前端丟掉過期資料

---

## Task D：deque — 滑動視窗最大值（★★★）

```cpp
vector<int> maxSlidingWindow(const vector<int>& nums, int k);
```

長度為 k 的視窗由左往右一次滑一格，回傳每個視窗中的最大值。保證 `1 <= k <= nums.size()`。要求 O(n)：每個元素最多進出 deque 一次。

範例：

```
nums = {1, 3, -1, -3, 5, 3, 6, 7}, k = 3  → {3, 3, 5, 5, 6, 7}
nums = {9, 8, 7, 6, 5},             k = 2  → {9, 8, 7, 6}
nums = {2, 2, 2, 2},                k = 2  → {2, 2, 2}
```

練到的概念：`deque` 兩端操作（`push_back` / `pop_back` / `pop_front` / `front` / `back`）、單調佇列、在 deque 裡存索引

提示：維持 deque 中「索引對應的值」由前到後遞減；新元素進來前，把後面比它小（或相等）的都 pop 掉；最前面的索引滑出視窗時也要 pop 掉。

---

## Task E：priority_queue — 最大堆積、最小堆積、自訂比較（★★★）

```cpp
int lastStoneWeight(const vector<int>& stones);
int kthLargest(const vector<int>& nums, int k);
vector<int> topKFrequent(const vector<int>& nums, int k);
```

- `lastStoneWeight`：每回合拿出**最重的兩顆**石頭 `x <= y` 互撞：相等就都消失，否則把 `y - x` 放回去。回傳最後剩下的那顆石頭重量；全部消失回傳 0。（max-heap）
- `kthLargest`：回傳第 k 大的元素，重複值也算。請用**大小維持在 k 的 min-heap**，不要整個排序。
- `topKFrequent`：回傳出現頻率最高的 k 個值，**頻率高的在前；頻率相同時，數值小的在前**。保證 k 不超過不同值的個數。

範例：

```
lastStoneWeight {2, 7, 4, 1, 8, 1}                → 1
lastStoneWeight {2, 2}                            → 0
kthLargest      {3, 2, 1, 5, 6, 4}, k = 2         → 5
kthLargest      {3, 2, 3, 1, 2, 4, 5, 5, 6}, k = 4 → 4
topKFrequent    {1, 1, 1, 2, 2, 3}, k = 2         → {1, 2}
topKFrequent    {4, 4, 5, 5, 6, 6, 6, 7}, k = 3   → {6, 4, 5}   （4 和 5 都出現 2 次，4 較小排前面）
```

練到的概念：`priority_queue<int>`（max-heap）、`priority_queue<int, vector<int>, greater<int>>`（min-heap）、`pair` 放進 heap、lambda + `decltype` 自訂比較

提示：`topKFrequent` 先用 `unordered_map` 統計次數（006），再把 `(頻率, 數值)` 放進 heap。想清楚 comparator 回傳 `true` 代表誰「比較晚」被 pop。

---

## 完成檢查

- [ ] `make run Q=007` 全部 PASS
- [ ] 沒有任何 sanitizer 錯誤訊息（`runtime error` / `AddressSanitizer`）
- [ ] 能說出每個 Task 用到的概念（特別是：為什麼 `greater<int>` 讓 priority_queue 變成 min-heap？deque 裡為什麼存索引？）
