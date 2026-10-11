# 012 · 數字範圍、取模、位元運算與函式模板

## 這一課學什麼

- `int` / `long long` 的範圍，以及 `<climits>` 裡的 `INT_MAX`、`INT_MIN`、`LLONG_MAX`
- 溢位發生在「運算的當下」：`(long long)a * b`、二分搜尋的安全中點 `l + (r - l) / 2`
- 取模運算：`const int MOD = 1e9 + 7;`、每一步都取模、減法要 `+ MOD`、快速冪
- 位元運算：`1 << k`、測試 / 設定 / 清除某個 bit、`x & (x - 1)`、`__builtin_popcount`
- 用 bitmask 列舉所有子集合
- 函式模板 `template <typename T>`：同一份程式碼給 `int`、`double`、`string` 用

## 語法速查

```cpp
#include <climits>
// ---- 範圍 ----
INT_MAX;    //  2147483647           ≈ 2.1e9（2^31 - 1）
INT_MIN;    // -2147483648
LLONG_MAX;  //  9223372036854775807  ≈ 9.2e18（2^63 - 1）
// 經驗法則：答案可能超過 2e9 → 用 long long

long long p = (long long)a * b;      // 先轉型再乘（static_cast<long long>(a) * b 也可以）
long long q = 1LL * a * b;           // 另一種常見寫法
int mid = l + (r - l) / 2;           // 二分搜尋中點：l + r 可能溢位，r - l 不會

// ---- 取模 ----
const int MOD = 1e9 + 7;             // 1e9 是 double，但 1000000007 剛好能精確轉成 int
long long s = 0;
for (int x : a) s = (s + x) % MOD;           // 加完馬上取模
long long prod = 1;
for (int x : a) prod = prod * x % MOD;       // prod < MOD、x <= 1e9 → 乘積 < 1e18，long long 裝得下
int diff = ((a - b) % MOD + MOD) % MOD;      // C++ 的 % 可能是負的：-7 % 3 == -1

// 快速冪：把 exp 看成二進位，例如 3^13 = 3^8 * 3^4 * 3^1（13 = 1101b）
// 每一輪：exp 最低位是 1 就把目前的 base 乘進答案；base 自己平方；exp >>= 1   → O(log exp)

// ---- 位元運算 ----
1 << k                 // 只有第 k 個 bit 是 1（k <= 30；更大要用 1LL << k）
(x >> k) & 1           // 第 k 個 bit 是 0 還是 1
x | (1 << k)           // 設成 1
x & ~(1 << k)          // 設成 0
x ^ (1 << k)           // 反轉
x & (x - 1)            // 去掉最低位的 1：12 (1100) → 8 (1000)
__builtin_popcount(x)  // 有幾個 1（unsigned int）；long long 用 __builtin_popcountll
a ^ b                  // XOR：相同為 0、不同為 1

// ---- bitmask 列舉子集合（n 個元素 → 2^n 個 mask）----
for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) { /* 這個子集合有選 nums[i] */ }
    }
}

// ---- 函式模板 ----
template <typename T>
T firstOr(const vector<T>& v, const T& fallback) {   // T 由呼叫時的引數推導
    return v.empty() ? fallback : v[0];
}
firstOr(vector<int>{3, 4}, 0);              // T = int
firstOr(vector<string>{}, string("none"));  // T = string
firstOr<double>({1.5}, 0.0);                // 也可以明確寫 <double>
T zero{};   // 模板裡的「零值」：int → 0、double → 0.0、string → ""
```

### 位元圖解：mask = 5 代表選了哪些？

```
nums  = {  a,   b,   c }
index :    0    1    2
mask  = 5 = 1 0 1 (二進位，由右往左是第 0、1、2 個 bit)
            | | +-- bit 0 = 1 → 選 a
            | +---- bit 1 = 0 → 不選 b
            +------ bit 2 = 1 → 選 c        → 子集合 {a, c}
```

## 常見坑

1. **先用 int 算完才轉 long long**：溢位已經發生了

   ```cpp
   long long p = a * b;                // ❌ UBSan：signed integer overflow: ... cannot be represented in type 'int'
   long long p = (long long)a * b;     // ✅ 至少一邊先變成 long long
   ```

2. **二分搜尋的中點**

   ```cpp
   int mid = (l + r) / 2;              // ❌ l = 2e9、r = INT_MAX 時溢位
   int mid = l + (r - l) / 2;          // ✅
   ```

3. **減法取模得到負數**

   ```cpp
   int d = (a - b) % MOD;              // ❌ a < b 時是負的
   int d = ((a - b) % MOD + MOD) % MOD;  // ✅
   ```

4. **乘完才取模，或累乘變數用 int**

   ```cpp
   int prod = 1; prod = prod * x % MOD;          // ❌ prod * x 用 int 算，溢位
   long long prod = 1; prod = prod * x % MOD;    // ✅
   ```

   快速冪也一樣：`base` 一開始要先 `base %= mod`，不然 `base * base` 可能超過 `LLONG_MAX`。

5. **位移超過範圍**

   ```cpp
   int big = 1 << 32;          // ❌ UBSan：shift exponent 32 is too large for 32-bit type 'int'
   long long big = 1LL << 40;  // ✅ k >= 31 時用 1LL
   ```

   `1 << 31` 會得到 `INT_MIN`（負數），也很容易出錯。

6. **`x & (x - 1)` 碰到 0 或負數**

   ```cpp
   return (n & (n - 1)) == 0;              // ❌ n = 0 回傳 true；n = INT_MIN 時 n - 1 溢位
   return n > 0 && (n & (n - 1)) == 0;     // ✅ && 短路：n <= 0 就不會算後面
   ```

7. **位元運算的優先順序比 `==` 低**

   ```cpp
   if (x & 1 == 0)      // ❌ 被解讀成 x & (1 == 0)
   if ((x & 1) == 0)    // ✅ 位元運算一律加括號
   ```

8. **模板的「零值」寫成 `0`、或用第一個元素以外的值當初始最大值**

   ```cpp
   T best = 0;     // ❌ T = string 時編譯錯誤；全部是負數時答案錯
   T best = v[0];  // ✅ 最大 / 最小值從第一個元素開始
   T total{};      // ✅ 加總從「零值」開始
   ```

9. **模板引數推導不到 `{...}`**

   ```cpp
   myMax({3, 1, 4});               // ❌ couldn't infer template argument 'T'
   myMax(vector<int>{3, 1, 4});    // ✅
   myMax<int>({3, 1, 4});          // ✅
   ```

## 在 LeetCode 會怎麼用

- 題目寫「答案可能很大，請回傳對 `10^9 + 7` 取模的結果」→ DP / 組合數題，每一步都 `% MOD`，中間值用 `long long`。
- 「回傳 0 若結果超出 32-bit 範圍」（例如 Reverse Integer）→ 用 `long long` 算，再和 `INT_MAX` / `INT_MIN` 比較。
- 二分搜尋一律 `l + (r - l) / 2`。
- `n <= 20` 通常是暗示「可以用 bitmask 暴力列舉 2^n 種情況」；狀態壓縮 DP 也是同一套位元操作。
- `__builtin_popcount`、`x & (x - 1)`、XOR 是位元題（Single Number、Counting Bits、Hamming Distance）的基本工具。
- 函式模板在 LeetCode 不常自己寫，但讀懂 `template <typename T>` 才看得懂 STL 的錯誤訊息和別人的模板程式碼。

## 參考

- [Fixed width integer types / `<climits>`](https://en.cppreference.com/w/cpp/header/climits)
- [Arithmetic operators（`%`、`<<`、`>>`、`&`、`|`、`^`、`~`）](https://en.cppreference.com/w/cpp/language/operator_arithmetic)
- [Operator precedence](https://en.cppreference.com/w/cpp/language/operator_precedence)
- [Function template](https://en.cppreference.com/w/cpp/language/function_template)
- [Template argument deduction](https://en.cppreference.com/w/cpp/language/template_argument_deduction)
- [GCC/Clang builtins（`__builtin_popcount`）](https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html)
