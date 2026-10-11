# 002 · 函式、參考與指標 — 練習題

> 先讀 notes.md。完成後執行 `make run Q=002`，全部 PASS 即完成。

所有函式都在 `main.cpp` 裡，只要把 `// TODO: 實作` 換成你的程式碼即可，`main()` 裡的測試不用改。

---

## Task A：swap 兩種寫法（★）

寫兩個交換兩個整數的函式：一個用參考（reference）、一個用指標（pointer）。
（標準函式庫有 `std::swap`，這裡請自己寫，體會兩種寫法的差別。）

```cpp
void swapByRef(int& a, int& b);
void swapByPtr(int* a, int* b);
```

範例：

```
int a = 1, b = 2;   swapByRef(a, b);     → a == 2, b == 1
int a = -5, b = 42; swapByPtr(&a, &b);   → a == 42, b == -5
vector<int> v = {1, 2, 3}; swapByRef(v[0], v[2]); → v == {3, 2, 1}
```

練到的概念：`int&` 參考、`int*` 指標、`&x` 取位址、`*p` 解參考（dereference）

提示：想想如果參數寫成 `void swapByValue(int a, int b)`，為什麼呼叫端的值不會變？

---

## Task B：三種傳參方式（★）

同樣是傳 `vector<int>`，寫三個用不同方式接參數的函式：

1. `countGreater`：只讀不改 → `const vector<int>&`，回傳大於 `k` 的元素個數。
2. `addToAll`：要改呼叫端的 vector → `vector<int>&`，每個元素加上 `delta`。
3. `addedCopy`：傳值（複製一份）→ `vector<int>`，回傳每個元素加上 `delta` 的**新** vector，
   呼叫端原本的 vector 不能被改到。

```cpp
int countGreater(const vector<int>& nums, int k);
void addToAll(vector<int>& nums, int delta);
vector<int> addedCopy(vector<int> nums, int delta);
```

範例：

```
countGreater({1, 5, 3, 7}, 3)  → 2
v = {1, 2, 3}; addToAll(v, 10) → v == {11, 12, 13}
v = {1, 2, 3}; w = addedCopy(v, 5) → w == {6, 7, 8}，v 仍然是 {1, 2, 3}
```

練到的概念：pass by value / reference / const reference、range-for 的 `int x` vs `int& x`

---

## Task C：回傳 pair + structured binding（★★）

函式只能回傳一個值，想回傳兩個值時最常用 `pair`。

1. `minMax`：回傳 `{最小值, 最大值}`（`nums` 至少有一個元素）。
2. `firstLast`：回傳 `target` 第一次和最後一次出現的 index，找不到回傳 `{-1, -1}`。

```cpp
pair<int, int> minMax(const vector<int>& nums);
pair<int, int> firstLast(const vector<int>& nums, int target);
```

範例：

```
auto [lo, hi] = minMax({3, 1, 4, 1, 5, 9, 2, 6});  → lo == 1, hi == 9
minMax({-7})                                       → {-7, -7}
firstLast({5, 7, 7, 8, 8, 10}, 8)                  → {3, 4}
firstLast({}, 3)                                   → {-1, -1}
```

練到的概念：`pair<int, int>`、`return {a, b};`、`auto [a, b] = ...`（structured binding）

提示：最小值、最大值的初始值用 `nums[0]` 最安全。

---

## Task D：overload 與預設引數（★★）

1. 寫三個都叫 `maxOf` 的函式（overload），分別處理「兩個數」、「三個數」、「一個 vector」。
   三個數的版本可以呼叫兩個數的版本。
2. `repeatStr`：把 `s` 重複 `times` 次、中間用 `sep` 隔開。`times` 預設 2、`sep` 預設空字串。

```cpp
int maxOf(int a, int b);
int maxOf(int a, int b, int c);
int maxOf(const vector<int>& nums);
string repeatStr(const string& s, int times = 2, const string& sep = "");
```

範例：

```
maxOf(3, 7)              → 7
maxOf(-4, -9, -2)        → -2
maxOf({-5, -3, -8})      → -3
repeatStr("ab")          → "abab"
repeatStr("ab", 3)       → "ababab"
repeatStr("ab", 3, "-")  → "ab-ab-ab"
```

練到的概念：函式多載（overload）、預設引數（default argument）、全負數時的初始值陷阱

---

## Task E：指標走訪陣列與 nullptr（★★★）

用指標走訪一段 C-style 陣列。範圍採「左閉右開」`[first, last)`：`last` 指向最後一個元素的
**下一格**（STL 的 `begin()` / `end()` 也是這個規則）。

1. `sumRange`：加總 `[first, last)` 的元素。
2. `findPtr`：回傳指向第一個等於 `target` 元素的指標，找不到回傳 `nullptr`。
3. `valueOr`：`p` 不是 `nullptr` 就回傳 `*p`，否則回傳 `fallback`。

```cpp
int sumRange(const int* first, const int* last);
const int* findPtr(const int* first, const int* last, int target);
int valueOr(const int* p, int fallback);
```

範例（`int arr[] = {4, 8, 15, 16, 23, 42};`）：

```
sumRange(arr, arr + 6)                     → 108
sumRange(arr + 1, arr + 3)                 → 23（8 + 15）
sumRange(arr, arr)                         → 0（空範圍）
findPtr(arr, arr + 6, 16)                  → arr + 3
valueOr(findPtr(arr, arr + 6, 99), -1)     → -1
```

練到的概念：指標加減（pointer arithmetic）、`p++`、`*p`、`nullptr`、`const int*`、左閉右開範圍

提示：迴圈條件寫 `p != last`。對 `nullptr` 解參考會直接讓程式崩潰（sanitizer 會報錯）。

---

## 完成檢查

- [ ] `make run Q=002` 全部 PASS
- [ ] 輸出中沒有 `runtime error:` 或 `AddressSanitizer` 等 sanitizer 錯誤
- [ ] 能說出每個 Task 用到的概念（例如：什麼時候用 `const vector<int>&`、什麼時候用 `vector<int>&`？）
