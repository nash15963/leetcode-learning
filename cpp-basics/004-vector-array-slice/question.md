# 004 · vector、陣列與切片 — 練習題

> 先讀 notes.md。完成後執行 `make run Q=004`，全部 PASS 即完成。

所有函式都在 `main.cpp` 裡，只要把 `// TODO: 實作` 換成你的程式碼即可，`main()` 裡的測試不用改。

---

## Task A：vector 基本操作（★）

1. `keepEvens`：用 `push_back` 收集所有偶數（包含負數與 0），保持原本順序。
2. `withIndex`：用 `emplace_back` 產生 `{index, 值}` 的 pair 列表。
3. `popUntil`：把 `st` 當成堆疊（stack），從尾端一直 `pop_back`，直到 `back() == target` 為止
   （`target` 本身保留）；如果 pop 到空了就停。回傳總共 pop 掉幾個元素。

```cpp
vector<int> keepEvens(const vector<int>& nums);
vector<pair<int, int>> withIndex(const vector<int>& nums);
int popUntil(vector<int>& st, int target);
```

範例：

```
keepEvens({1, 2, -3, -4, 0, 7})       → {2, -4, 0}
withIndex({7, 8, 9})                  → {{0, 7}, {1, 8}, {2, 9}}
st = {1, 2, 3, 4, 5}; popUntil(st, 3) → 回傳 2，st == {1, 2, 3}
st = {1, 2};          popUntil(st, 9) → 回傳 2，st == {}
```

練到的概念：`push_back`、`emplace_back`、`back`、`pop_back`、`empty`、負數取餘數

提示：`-3 % 2` 在 C++ 是 `-1`。對空的 vector 呼叫 `back()` 是未定義行為，條件要先檢查 `empty()`。

---

## Task B：size_t 倒序迴圈陷阱（★★）

`v.size()` 的型別是**無號整數** `size_t`，`0 - 1` 不會變成 `-1`，而是變成一個超大的數。

1. `lastIndexOf`：從後面往前找，回傳 `target` 最後一次出現的 index，找不到回傳 `-1`。
2. `countAdjacentEqual`：回傳有幾個 `i` 滿足 `v[i] == v[i + 1]`。

```cpp
int lastIndexOf(const vector<int>& v, int target);
int countAdjacentEqual(const vector<int>& v);
```

範例：

```
lastIndexOf({1, 2, 3, 2, 1}, 2)      → 3
lastIndexOf({}, 1)                   → -1
countAdjacentEqual({1, 1, 2, 2, 2, 3}) → 3
countAdjacentEqual({})               → 0
```

練到的概念：`size_t` 下溢（underflow）、`(int)v.size()` 轉型、`i + 1 < v.size()` 的安全寫法

提示：試試看寫 `for (size_t i = v.size() - 1; i >= 0; i--)`，跑一次看 sanitizer 會說什麼，再修正它。

---

## Task C：切片與拼接（★★）

C++ 沒有 Python 的 `v[i:j]`，要用 iterator 範圍建構一個新的 vector。

1. `slice`：回傳 `v[i..j)`（左閉右開）的複製，保證 `0 <= i <= j <= v.size()`。
2. `rotateRight`：回傳把 `v` 向右旋轉 `k` 步的結果（`k >= 0`，可能比長度大）。

```cpp
vector<int> slice(const vector<int>& v, int i, int j);
vector<int> rotateRight(const vector<int>& v, int k);
```

範例：

```
slice({10, 20, 30, 40, 50}, 1, 4)        → {20, 30, 40}
slice({10, 20, 30}, 2, 2)                → {}
rotateRight({1, 2, 3, 4, 5, 6, 7}, 3)    → {5, 6, 7, 1, 2, 3, 4}
rotateRight({1, 2}, 5)                   → {2, 1}
rotateRight({}, 3)                       → {}
```

練到的概念：`vector<int>(v.begin() + i, v.begin() + j)`、`insert(res.end(), b.begin(), b.end())` 拼接、`k %= n`

提示：向右轉 `k` 步 = 「最後 `k` 個」接上「前面 `n - k` 個」。`n == 0` 時 `k % n` 是除以零。

---

## Task D：2D vector（★★）

1. `makeGrid`：回傳 `rows × cols`、每格都是 `val` 的 2D vector。
2. `transpose`：回傳矩陣的轉置：原本 row `r`、column `c` 的元素，放到結果的 row `c`、column `r`。
   矩陣可能不是正方形，也可能是空的。

```cpp
vector<vector<int>> makeGrid(int rows, int cols, int val);
vector<vector<int>> transpose(const vector<vector<int>>& m);
```

範例：

```
makeGrid(2, 3, 7)                  → {{7, 7, 7}, {7, 7, 7}}
transpose({{1, 2, 3}, {4, 5, 6}})  → {{1, 4}, {2, 5}, {3, 6}}
transpose({})                      → {}
```

練到的概念：`vector<vector<int>> g(rows, vector<int>(cols, val))`、`m.size()` 是 row 數、`m[0].size()` 是 column 數、巢狀迴圈

提示：結果的大小是 `cols × rows`，先建好再填值。讀 `m[0]` 之前要確認 `m` 不是空的。

---

## Task E：前綴和區間查詢（★★★）

前綴和（prefix sum）讓「區間總和」查詢從 O(n) 變成 O(1)。

1. `buildPrefix`：回傳長度 `n + 1` 的陣列，`pre[0] = 0`、`pre[i + 1] = pre[i] + nums[i]`。
2. `rangeSum`：用前綴和回傳 `nums[l] + ... + nums[r]`（閉區間）。
3. `answerQueries`：每個 query 是 `{l, r}`，回傳每個閉區間的總和。

```cpp
vector<long long> buildPrefix(const vector<int>& nums);
long long rangeSum(const vector<long long>& pre, int l, int r);
vector<long long> answerQueries(const vector<int>& nums, const vector<pair<int, int>>& queries);
```

範例：

```
buildPrefix({1, 2, 3, 4})                                 → {0, 1, 3, 6, 10}
buildPrefix({})                                           → {0}
rangeSum({0, 1, 3, 6, 10}, 1, 2)                          → 5（2 + 3）
answerQueries({-2, 0, 3, -5, 2, -1}, {{0, 2}, {2, 5}, {0, 5}}) → {1, -1, -3}
answerQueries({2000000000, 2000000000, 2000000000}, {{0, 2}}) → {6000000000}
```

練到的概念：前綴和、長度 `n + 1` 的 off-by-one、`long long` 防溢位、`for (auto [l, r] : queries)`

提示：`rangeSum(pre, l, r) = pre[r + 1] - pre[l]`。前綴和本身要用 `long long` 累加。

---

## 完成檢查

- [ ] `make run Q=004` 全部 PASS
- [ ] 輸出中沒有 `runtime error:` 或 `AddressSanitizer` 等 sanitizer 錯誤
- [ ] 能說出每個 Task 用到的概念（例如：為什麼 `for (size_t i = v.size() - 1; i >= 0; i--)` 會出事？）
