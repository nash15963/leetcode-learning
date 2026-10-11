# 012 · 數字範圍、取模、位元運算與函式模板 — 練習題

> 先讀 notes.md。完成後執行 `make run Q=012`，全部 PASS 即完成。

所有函式都在 `main.cpp` 裡，把 `// TODO: 實作` 換成你的程式碼即可。`main.cpp` 開頭已經定義好 `const int MOD = 1e9 + 7;`。

這一課很多錯誤**不會讓測試 FAIL，而是讓 sanitizer 印出 `runtime error: signed integer overflow`**。看到這種訊息就代表有溢位，要修到完全沒有為止。

---

## Task A：整數範圍與安全中點（★）

```cpp
int safeMid(int l, int r);         // 0 <= l <= r <= INT_MAX，回傳 (l + r) / 2，但 l + r 不能溢位
long long multiplyLL(int a, int b);  // a * b 的正確結果
int clampToInt(long long x);       // 夾到 [INT_MIN, INT_MAX]
```

範例：

```
safeMid(0, 10)                    → 5
safeMid(2000000000, 2147483647)   → 2073741823
multiplyLL(100000, 100000)        → 10000000000
multiplyLL(INT_MIN, -1)           → 2147483648
clampToInt(5000000000)            → 2147483647   (INT_MAX)
clampToInt(LLONG_MIN)             → -2147483648  (INT_MIN)
```

練到的概念：`INT_MAX` / `INT_MIN` / `LLONG_MAX`、溢位發生在運算當下、轉型的時機、`static_cast<int>`

提示：先故意寫 `return a * b;` 和 `(l + r) / 2` 跑一次，看看 UBSan 印出什麼，再修正。

---

## Task B：位元操作（★★）

第 k 個 bit：最右邊（最低位）是第 0 個，本題保證 `0 <= k <= 30`。

```cpp
bool testBit(int x, int k);         // 第 k 個 bit 是不是 1
int setBit(int x, int k);           // 第 k 個 bit 設成 1
int clearBit(int x, int k);         // 第 k 個 bit 設成 0
bool isPowerOfTwo(int n);           // n 是 1, 2, 4, 8, ... 嗎？n <= 0 → false
int hammingDistance(int x, int y);  // x、y 有幾個 bit 不同
```

範例：

```
testBit(5, 0)           → true      (5 = 101)
testBit(5, 1)           → false
setBit(5, 1)            → 7         (101 → 111)
clearBit(7, 1)          → 5         (111 → 101)
clearBit(-1, 0)         → -2
isPowerOfTwo(16)        → true
isPowerOfTwo(6)         → false
isPowerOfTwo(INT_MIN)   → false
hammingDistance(1, 4)   → 2         (001 vs 100)
hammingDistance(-1, 0)  → 32
```

練到的概念：`1 << k`、`>>`、`&`、`|`、`~`、`^`、`x & (x - 1)`、`__builtin_popcount`、`&&` 短路避免溢位

提示：每個函式都可以只寫一行。`isPowerOfTwo`：2 的冪次在二進位裡長什麼樣子？`x & (x - 1)` 會把它變成什麼？

---

## Task C：函式模板（★★）

```cpp
template <typename T> T myMax(const vector<T>& v);          // 最大值（v 不是空的）
template <typename T> T sumAll(const vector<T>& v);         // 用 + 加總；空陣列回傳 T{}
template <typename T> pair<T, T> minMax(const vector<T>& v); // {最小值, 最大值}（v 不是空的）
```

範例：

```
myMax(vector<int>{-5, -2, -9})                    → -2
myMax(vector<string>{"pear", "apple", "zoo"})     → "zoo"
sumAll(vector<string>{"ab", "c", "de"})           → "abcde"
sumAll(vector<long long>{3000000000, 3000000000}) → 6000000000
sumAll(vector<int>{})                             → 0
minMax(vector<int>{3, -1, 7, 2})                  → {-1, 7}
minMax(vector<char>{'m', 'z', 'a'})               → {'a', 'z'}
```

練到的概念：`template <typename T>`、模板引數推導、`T{}` 零值、只用 `<` 和 `+`（所以 `int`、`double`、`string`、`char` 都能用）、回傳 `pair`

提示：同一份程式碼要能同時處理 `int` 和 `string`，所以不能寫 `T best = 0;` 或 `INT_MIN`。

---

## Task D：取模運算與快速冪（★★★）

```cpp
int sumMod(const vector<int>& a);       // 總和 % MOD（a[i] <= 1e9，長度到 1e5）
int subMod(int a, int b);               // (a - b) mod MOD，結果在 [0, MOD)
int productMod(const vector<int>& a);   // 乘積 % MOD；空陣列回傳 1
long long powMod(long long base, long long exp, long long mod);  // base^exp % mod，O(log exp)
```

範例：

```
sumMod({1000000000, 1000000000, 1000000000})   → 999999986
subMod(3, 5)                                   → 1000000005
productMod({1000000000, 1000000000})           → 49
productMod({})                                 → 1
powMod(2, 10, MOD)                             → 1024
powMod(1000000000000, 2, MOD)                  → 49000000
powMod(3, MOD - 2, MOD)                        → 333333336
powMod(7, 1000000000000000000, MOD)            → 259616729
```

練到的概念：`const int MOD = 1e9 + 7`、每一步取模、`long long` 中間值、負數取模、快速冪（二進位拆解 exp）

⚠️ 最後一個測試的 `exp = 1e18`。如果你的 `powMod` 是「乘 exp 次」的迴圈，程式會**卡住永遠跑不完**（相當於 LeetCode 的 Time Limit Exceeded），請按 `Ctrl+C` 中斷，改寫成快速冪。

提示：快速冪的想法見 notes.md。`base` 可能比 `mod` 大很多，相乘前要先處理。

---

## Task E：用 bitmask 列舉子集合（★★★）

`n <= 20`。mask 從 `0` 跑到 `2^n - 1`，mask 的第 `i` 個 bit 是 1 就代表選了 `nums[i]`。

```cpp
vector<vector<int>> subsets(const vector<int>& nums);           // 所有子集合
int countSubsetsWithSum(const vector<int>& nums, int target);   // 總和 == target 的子集合數（含空集合）
```

`subsets` 的順序：依 mask 由小到大；每個子集合內依 `i` 由小到大。

範例：

```
subsets({1, 2, 3})
→ {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}}
   m=0  m=1  m=2  m=3     m=4  m=5     m=6     m=7

subsets({})                              → {{}}        （只有空集合）
countSubsetsWithSum({1, 2, 3, 4}, 5)     → 2           （{1,4}、{2,3}）
countSubsetsWithSum({3, 1, 4, 1, 5}, 5)  → 4           （兩個 1 視為不同元素）
countSubsetsWithSum({1, 2, 3}, 0)        → 1           （空集合）
```

練到的概念：`1 << n` 個狀態、`mask & (1 << i)` 判斷有沒有選、巢狀迴圈、`vector<vector<int>>`

---

## 完成檢查

- [ ] `make run Q=012` 全部 PASS
- [ ] 沒有任何 sanitizer 錯誤訊息（`runtime error` / `AddressSanitizer`）
- [ ] 能說出每個 Task 用到的概念（特別是：為什麼要 `(long long)a * b` 而不是 `(long long)(a * b)`？減法取模為什麼要 `+ MOD`？快速冪為什麼是 O(log exp)？）
