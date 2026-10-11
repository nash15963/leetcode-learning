# 004 · vector、陣列與切片

## 這一課學什麼

- `vector` 的各種初始化方式，以及 `push_back` / `emplace_back` / `pop_back` / `back` / `front`
- `size()` 回傳 `size_t`（無號整數）帶來的倒序迴圈與 `size() - 1` 陷阱
- 用 iterator 範圍做「切片」：`vector<int>(v.begin() + i, v.begin() + j)`，以及用 `insert` 拼接
- 2D vector 的建立與走訪
- C-style 陣列（`int a[26]`）與 vector 的差別
- 前綴和（prefix sum）：LeetCode 最常見的 vector 技巧之一

## 語法速查

### 初始化

```cpp
#include <vector>
vector<int> a;                    // 空的
vector<int> b(5);                 // {0, 0, 0, 0, 0}
vector<int> c(5, -1);             // {-1, -1, -1, -1, -1}
vector<int> d = {3, 1, 4};        // 直接列出元素
vector<int> e(d.begin(), d.end());// 從一段範圍複製
vector<int> f = d;                // 複製整個 vector
vector<vector<int>> g(3, vector<int>(4, 0));  // 3 個 row、每個 row 4 格的 2D vector
```

### 增減與存取

```cpp
v.push_back(7);                   // 尾端加入
v.emplace_back(7);                // 同上，但直接在尾端「建構」元素
vector<pair<int, int>> ps;
ps.emplace_back(1, 2);            // 直接傳建構參數，不用寫 {1, 2} 或 make_pair
v.pop_back();                     // 移除尾端（不回傳值）
v.back(); v.front();              // 最後 / 第一個元素（空的時候不能呼叫）
v[i];                             // 不檢查邊界，越界是 UB
v.at(i);                          // 會檢查邊界，越界丟出 out_of_range
v.size(); v.empty(); v.clear();
v.resize(10);                     // 改變大小，多出來的補 0
```

### 走訪

```cpp
for (int x : v) { }               // 唯讀複製
for (int& x : v) x *= 2;          // 修改元素
for (const auto& row : grid) { }  // 2D：用 const auto& 避免複製整個 row
int n = v.size();                 // 習慣：先轉成 int 再寫迴圈
for (int i = n - 1; i >= 0; i--) { }  // 倒序（i 是 int，所以 n == 0 也安全）
```

### 切片與拼接

```cpp
vector<int> v = {10, 20, 30, 40, 50};
vector<int> mid(v.begin() + 1, v.begin() + 4);   // {20, 30, 40}：左閉右開 [1, 4)
vector<int> tail(v.begin() + 3, v.end());        // {40, 50}
vector<int> res = {1, 2};
res.insert(res.end(), tail.begin(), tail.end()); // {1, 2, 40, 50}：拼接
```

### C-style 陣列

```cpp
int cnt[26] = {};                 // 大小固定、全部歸零（不寫 = {} 的話是垃圾值）
int arr[] = {1, 2, 3};            // 大小由編譯器推算
int len = sizeof(arr) / sizeof(arr[0]);  // 3（傳進函式後就不能這樣算了）
```

## 常見坑

1. **`size_t` 倒序迴圈**：`i >= 0` 永遠成立，`i` 從 0 再減 1 會變成超大的數。編譯器（這個 repo 的設定）
   **不會**警告，執行時 ASan 才會報 `heap-buffer-overflow`。

   ```cpp
   for (size_t i = v.size() - 1; i >= 0; i--) { }          // ❌ 永遠停不下來 + 越界
   for (int i = (int)v.size() - 1; i >= 0; i--) { }        // ✅
   ```

2. **`v.size() - 1` 在空 vector 時下溢**

   ```cpp
   for (size_t i = 0; i < v.size() - 1; i++) { v[i + 1]; } // ❌ v 為空時 size() - 1 是超大的數
   for (size_t i = 0; i + 1 < v.size(); i++) { v[i + 1]; } // ✅ 把減法改成加法
   ```

3. **對空 vector 呼叫 `back()` / `front()` / `v[0]`**

   ```cpp
   while (st.back() != target) st.pop_back();                  // ❌ pop 到空就出事
   while (!st.empty() && st.back() != target) st.pop_back();   // ✅ 短路求值先檢查
   ```

4. **小括號和大括號意思不同**

   ```cpp
   vector<int> v{5, 1};   // ❌ 想要 5 個 1，結果是 {5, 1}
   vector<int> v(5, 1);   // ✅ {1, 1, 1, 1, 1}
   ```

5. **range-for 走訪 2D vector 沒加 `&`**：每一輪都複製整個 row，又慢又改不到原本的值。

   ```cpp
   for (auto row : grid) row[0] = 1;          // ❌ 改的是複製品
   for (auto& row : grid) row[0] = 1;         // ✅
   ```

6. **`push_back` 後還在用舊的參考 / iterator**：vector 擴容會搬家，舊位址失效（ASan：`heap-use-after-free`）。

   ```cpp
   int& first = v[0]; v.push_back(9); first = 1;   // ❌ first 可能指向已釋放的記憶體
   v.push_back(9); v[0] = 1;                       // ✅ 需要時再重新取
   ```

7. **`k % n` 時 `n == 0`**：UBSan 報 `runtime error: division by zero`。

   ```cpp
   k %= v.size();                       // ❌ v 為空時除以零
   if (v.empty()) return {}; k %= n;    // ✅ 先處理空的情況
   ```

8. **負數取餘數**：C++ 的 `%` 結果和被除數同號，`-3 % 2 == -1`。

   ```cpp
   if (x % 2 == 1) { /* 奇數 */ }   // ❌ 負奇數會漏掉
   if (x % 2 != 0) { /* 奇數 */ }   // ✅
   ```

## 在 LeetCode 會怎麼用

- 題目參數幾乎都是 `vector<int>& nums`；第一行先寫 `int n = nums.size();`，之後全部用 `int` 算，避開 `size_t` 陷阱。
- DP 表格：`vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));`，grid 題用 `grid.size()` / `grid[0].size()`。
- 子陣列和、區間查詢（Range Sum Query、Subarray Sum Equals K）：前綴和開 `n + 1` 格，用 `long long`。
- 分治（merge sort、建樹）需要子陣列時可以用切片，但每次切片都會複製；追求效率時改傳 `l`、`r` 兩個 index。

## 參考

- https://en.cppreference.com/w/cpp/container/vector
- https://en.cppreference.com/w/cpp/container/vector/vector
- https://en.cppreference.com/w/cpp/container/vector/emplace_back
- https://en.cppreference.com/w/cpp/container/vector/insert
- https://en.cppreference.com/w/cpp/types/size_t
- https://en.cppreference.com/w/cpp/language/array
- https://en.cppreference.com/w/cpp/algorithm/partial_sum
