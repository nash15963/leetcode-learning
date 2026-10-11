# 008 · Lambda 與自訂比較（capture / comparator / 遞迴 lambda）

## 這一課學什麼

- lambda 的語法：`[capture](參數) -> 回傳型別 { 函式本體 }`
- capture 方式：`[x]` 複製、`[&x]` 參考、`[=]` 全部複製、`[&]` 全部參考
- 把 lambda 傳給 STL：`sort`、`count_if`、`for_each`
- 寫 comparator：多鍵排序、必須符合「嚴格弱序」（用 `<`，不能用 `<=`）
- comparator 捕捉外部資料（例如次數表、原陣列）來決定順序
- 用 `std::function` 寫遞迴 lambda，做網格 DFS（LeetCode 最常見寫法之一）

## 語法速查

```cpp
#include <algorithm>
#include <functional>  // function
#include <numeric>     // iota
using namespace std;

// ---- 基本語法 ----
auto add = [](int a, int b) { return a + b; };   // 回傳型別自動推導
auto half = [](int x) -> double { return x / 2.0; };  // 也可以明確寫出回傳型別
int s = add(2, 3);                                // 5，呼叫方式跟函式一樣

// ---- capture ----
int limit = 5, total = 0;
auto big = [limit](int x) { return x > limit; };  // 複製一份 limit
auto acc = [&total](int x) { total += x; };       // 參考 total，可以修改外面的值
auto all1 = [=](int x) { return x > limit; };     // 用到的外部變數全部複製
auto all2 = [&](int x) { total += x + limit; };   // 用到的外部變數全部參考

// ---- 搭配 STL ----
vector<int> v = {3, 8, 1, 9};
int cnt = count_if(v.begin(), v.end(), big);                  // 符合條件的個數
for_each(v.begin(), v.end(), [&](int x) { total += x; });     // 對每個元素做事
for_each(v.begin(), v.end(), [](int& x) { x *= 2; });         // 參數用 int& 才能改到元素

// ---- comparator：回傳 true 代表 a 要排在 b 前面 ----
sort(v.begin(), v.end(), [](int a, int b) { return a > b; }); // 由大到小

vector<string> w = {"bb", "a", "ab"};
sort(w.begin(), w.end(), [](const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();     // 第一鍵：長度
    return a < b;                                              // 第二鍵：字典順序
});

// ---- 索引排序（argsort）：comparator 捕捉原陣列 ----
vector<int> idx(v.size());
iota(idx.begin(), idx.end(), 0);                               // idx = {0, 1, 2, 3}
sort(idx.begin(), idx.end(), [&](int i, int j) { return v[i] < v[j]; });

// ---- 遞迴 lambda：一定要用 function<> 明確寫出型別 ----
vector<vector<char>> grid = {{'1', '0'}, {'1', '1'}};
int rows = grid.size(), cols = grid[0].size();
function<void(int, int)> dfs = [&](int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != '1') return;  // 先檢查邊界
    grid[r][c] = '0';                                                          // 標記走過
    dfs(r + 1, c); dfs(r - 1, c); dfs(r, c + 1); dfs(r, c - 1);
};
```

### capture 選擇速查

| 寫法 | 意思 | 適合 |
|---|---|---|
| `[]` | 不捕捉 | 純比較函式（只看參數） |
| `[x]` / `[=]` | 建立 lambda 當下**複製**一份 | 讀取小型變數（int、門檻值） |
| `[&x]` / `[&]` | **參考**外部變數 | 要修改外部變數、或捕捉大型容器避免複製 |

## 常見坑

1. **comparator 用 `<=`**：違反嚴格弱序，相等元素多時 `sort` 可能越界（ASan 會報 heap-buffer-overflow）

   ```cpp
   sort(v.begin(), v.end(), [](int a, int b) { return a <= b; });  // ❌ a == b 時必須回傳 false
   sort(v.begin(), v.end(), [](int a, int b) { return a < b; });   // ✅
   ```

2. **用 `[=]` 卻想修改外部變數**

   ```cpp
   for_each(v.begin(), v.end(), [=](int x) { total += x; });  // ❌ 編譯錯誤：cannot assign to a variable captured by copy
   for_each(v.begin(), v.end(), [&](int x) { total += x; });  // ✅
   ```

3. **複製 capture 是「建立當下」的快照**

   ```cpp
   int k = 1;
   auto byCopy = [k]() { return k; };
   auto byRef = [&k]() { return k; };
   k = 10;
   byCopy();  // 1  ← 之後改 k 不影響它
   byRef();   // 10
   ```

4. **遞迴 lambda 用 `auto` 宣告**

   ```cpp
   auto dfs = [&](int i) { dfs(i - 1); };                    // ❌ 'dfs' declared with deduced type 'auto' cannot appear in its own initializer
   function<void(int)> dfs2 = [&](int i) { dfs2(i - 1); };  // ✅
   ```

5. **DFS 先存取再檢查邊界**：越界存取，ASan 會報錯

   ```cpp
   if (grid[r][c] != '1' || r < 0 || r >= rows) return;  // ❌ r = -1 時已經越界
   if (r < 0 || r >= rows || grid[r][c] != '1') return;  // ✅ || 短路求值：邊界先檢查
   ```

6. **comparator 參數傳值**：每次比較都複製整個 vector / string，又慢又耗記憶體

   ```cpp
   [](vector<int> a, vector<int> b) { return a[0] < b[0]; }                // ❌
   [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; }  // ✅
   ```

7. **回傳一個用 `[&]` 捕捉區域變數的 lambda**：函式結束後區域變數已消失，變成 dangling reference（懸空參考）

   ```cpp
   function<int()> makeBad() { int n = 5; return [&]() { return n; }; }   // ❌
   function<int()> makeGood() { int n = 5; return [n]() { return n; }; }  // ✅ 複製一份帶走
   ```

## 在 LeetCode 會怎麼用

- 區間題（合併區間、會議室、射氣球）：第一步幾乎都是「依 start 或 end 排序」。
- 自訂排序規則：依頻率、依長度、依某個計算結果；需要外部資料時用 `[&]` 捕捉。
- 網格 / 圖的 DFS：`function<void(int, int)> dfs = [&](int r, int c) {...};` 直接寫在函式裡，可以捕捉 `grid`、`rows`、`cols`，不用另外寫成員函式傳一堆參數。
- 在 `class Solution` 裡如果把 comparator 寫成成員函式，要加 `static` 才能傳給 `sort`；直接寫 lambda 最省事。

## 參考

- [Lambda expressions](https://en.cppreference.com/w/cpp/language/lambda)
- [std::function](https://en.cppreference.com/w/cpp/utility/functional/function)
- [std::sort](https://en.cppreference.com/w/cpp/algorithm/sort)（Compare 的要求）
- [Named requirements: Compare](https://en.cppreference.com/w/cpp/named_req/Compare)（嚴格弱序）
- [std::count_if](https://en.cppreference.com/w/cpp/algorithm/count)
- [std::for_each](https://en.cppreference.com/w/cpp/algorithm/for_each)
- [std::iota](https://en.cppreference.com/w/cpp/algorithm/iota)
