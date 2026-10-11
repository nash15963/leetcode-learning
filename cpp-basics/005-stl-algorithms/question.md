# 005 · STL 演算法 — 練習題

> 先讀 notes.md。完成後執行 `make run Q=005`，全部 PASS 即完成。

所有函式都在 `main.cpp` 裡，把 `// TODO: 實作` 換成你的程式碼即可。這一課的重點是**直接呼叫 STL**，盡量不要自己手寫迴圈。

---

## Task A：排序與反轉（★）

實作三個函式：

```cpp
void sortAscending(vector<int>& nums);   // 原地由小到大
void sortDescending(vector<int>& nums);  // 原地由大到小，使用 greater<int>()
string reversedString(string s);         // 回傳反轉後的字串
```

範例：

```
sortAscending  {5, 2, 9, 1, 5}  → {1, 2, 5, 5, 9}
sortDescending {5, 2, 9, 1, 5}  → {9, 5, 5, 2, 1}
reversedString "hello"          → "olleh"
```

練到的概念：`sort`、`greater<int>()`、`reverse`、`begin()` / `end()` 區間、傳參考 vs 傳值

---

## Task B：加總與 0LL 陷阱（★）

```cpp
long long sumAll(const vector<int>& nums);      // 總和
long long productAll(const vector<int>& nums);  // 乘積，空陣列回傳 1
```

範例：

```
sumAll     {1, 2, 3, 4}            → 10
sumAll     {INT_MAX, INT_MAX}      → 4294967294
productAll {100000, 100000}        → 10000000000
productAll {}                      → 1
```

練到的概念：`accumulate`、初始值決定累加型別、`multiplies<long long>()`

提示：先故意寫 `accumulate(..., 0)` 跑一次，看看 sanitizer 印出什麼訊息，再修正它。

---

## Task C：最大／最小值與索引（★★）

```cpp
int indexOfMax(const vector<int>& nums);   // 最大值「第一次出現」的索引，空陣列回傳 -1
int indexOfMin(const vector<int>& nums);   // 最小值「第一次出現」的索引，空陣列回傳 -1
int maxMinusMin(const vector<int>& nums);  // 最大值 - 最小值，空陣列回傳 0
```

範例：

```
indexOfMax  {3, 9, 2, 9}   → 1     （有兩個 9，取第一個）
indexOfMin  {7, -2, 8, -2} → 1
maxMinusMin {3, 9, 1, 7}   → 8
maxMinusMin {}             → 0
```

練到的概念：`max_element` / `min_element` 回傳 iterator、`*it` 取值、`distance` 或 `it - begin()` 換索引、空容器檢查

---

## Task D：在排序好的陣列上二分搜尋（★★）

輸入的 `sorted` 保證已經由小到大排序。

```cpp
int countOccurrences(const vector<int>& sorted, int target);  // target 出現幾次
int insertPosition(const vector<int>& sorted, int target);    // 第一個 >= target 的索引
int countInRange(const vector<int>& sorted, int lo, int hi);  // 落在 [lo, hi] 的個數
```

範例：

```
countOccurrences {1, 2, 2, 2, 3, 5}, target = 2   → 3
countOccurrences {1, 2, 2, 2, 3, 5}, target = 4   → 0
insertPosition   {1, 3, 5, 6},       target = 7   → 4   （插在最後面）
countInRange     {1, 2, 2, 3, 5, 8}, lo=2, hi=5   → 4   （2, 2, 3, 5）
```

練到的概念：`lower_bound`（第一個 `>=`）、`upper_bound`（第一個 `>`）、兩個 iterator 相減得到個數

提示：每個函式都可以只用 1～2 行完成，不需要自己寫 `while (l < r)`。

---

## Task E：去重（unique + erase）（★★★）

```cpp
void removeAdjacentDuplicates(vector<int>& nums);  // 只移除「相鄰」的重複，不要排序
void sortAndDedupe(vector<int>& nums);             // 排序後移除所有重複
int kthSmallestDistinct(vector<int> nums, int k);  // 第 k 小的「不同值」（k 從 1 開始），不足回傳 -1
```

範例：

```
removeAdjacentDuplicates {1, 1, 2, 2, 1, 1}       → {1, 2, 1}
sortAndDedupe            {3, 1, 3, 2, 1}          → {1, 2, 3}
kthSmallestDistinct      {5, 3, 3, 1, 5, 2}, k=2  → 2    （不同值依序為 1, 2, 3, 5）
kthSmallestDistinct      {5, 3, 3, 1, 5, 2}, k=5  → -1
```

練到的概念：`unique` 只搬移不刪除、erase-unique 慣用寫法、先 `sort` 才能完整去重、索引邊界檢查

提示：`kthSmallestDistinct` 的參數是傳值（複製一份），所以你可以放心排序它，不會影響呼叫端。

---

## 完成檢查

- [ ] `make run Q=005` 全部 PASS
- [ ] 沒有任何 sanitizer 錯誤訊息（`runtime error` / `AddressSanitizer`）
- [ ] 能說出每個 Task 用到的概念（特別是：為什麼 `0LL`？為什麼 `unique` 後還要 `erase`？）
