# 005 · STL 演算法（`<algorithm>` / `<numeric>`）

## 這一課學什麼

- 用 `sort` 排序（由小到大、由大到小 `greater<int>()`），用 `reverse` 反轉
- 用 `accumulate` 加總，以及「初始值 `0` vs `0LL`」的溢位陷阱
- 用 `max_element` / `min_element` 找最大最小值，再用 `distance` 換成索引
- 在**排序好**的陣列上用 `lower_bound` / `upper_bound` 做二分搜尋（計數、找插入位置）
- 用 `unique` + `erase` 去除重複
- 觀念：STL 演算法吃的是「iterator 區間 `[first, last)`」，不是容器本身

## 語法速查

```cpp
#include <algorithm>   // sort, reverse, max_element, lower_bound, unique ...
#include <functional>  // greater<int>, multiplies<long long>
#include <iterator>    // distance
#include <numeric>     // accumulate
#include <vector>
using namespace std;

vector<int> v = {5, 2, 9, 1, 5};

// ---- 排序 / 反轉 ----
sort(v.begin(), v.end());                  // {1, 2, 5, 5, 9}  由小到大
sort(v.begin(), v.end(), greater<int>());  // {9, 5, 5, 2, 1}  由大到小（注意有括號，是一個物件）
sort(v.rbegin(), v.rend());                // 另一種由大到小寫法：反向 iterator
reverse(v.begin(), v.end());               // 原地反轉，string 也能用

// ---- 加總 / 乘積 ----
long long sum = accumulate(v.begin(), v.end(), 0LL);  // 回傳型別 = 初始值的型別
long long prod = accumulate(v.begin(), v.end(), 1LL, multiplies<long long>());

// ---- 最大 / 最小（回傳 iterator，不是值也不是索引）----
auto it = max_element(v.begin(), v.end());  // 指向第一個最大值
int maxVal = *it;                            // 取值：用 * 解參考
int idx = distance(v.begin(), it);           // 轉成索引
int idx2 = min_element(v.begin(), v.end()) - v.begin();  // vector 的 iterator 也能直接相減

// ---- 二分搜尋（前提：已排序）----
vector<int> s = {1, 2, 2, 2, 3, 5};
auto lo = lower_bound(s.begin(), s.end(), 2);  // 第一個 >= 2 的位置 → 索引 1
auto hi = upper_bound(s.begin(), s.end(), 2);  // 第一個 >  2 的位置 → 索引 4
int cnt = hi - lo;                             // 2 出現 3 次
bool found = binary_search(s.begin(), s.end(), 3);  // 只想知道有沒有

// ---- 去重（前提：重複的元素要相鄰，通常先 sort）----
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());  // erase-unique 慣用寫法
```

### 複雜度

| 演算法 | 時間 | 備註 |
|---|---|---|
| `sort` | O(n log n) | 不保證相等元素的相對順序（要保證用 `stable_sort`） |
| `reverse` / `accumulate` / `max_element` / `unique` | O(n) | 單趟走訪 |
| `lower_bound` / `upper_bound` / `binary_search` | O(log n) | 只在 random-access iterator（vector、陣列）上是 log n |

## 常見坑

1. **`accumulate` 初始值寫 `0`，結果用 `int` 在累加 → 溢位**

   ```cpp
   vector<int> v = {INT_MAX, INT_MAX};
   long long bad = accumulate(v.begin(), v.end(), 0);    // ❌ 中途就用 int 算爆了，UBSan 會報 signed integer overflow
   long long good = accumulate(v.begin(), v.end(), 0LL); // ✅ 初始值決定累加型別
   ```

   存進 `long long` 變數也不會「事後補救」，溢位早就發生在 `accumulate` 裡面。

2. **`unique` 不會真的刪掉元素**：它只把不重複的搬到前面，回傳「新結尾」

   ```cpp
   unique(v.begin(), v.end());                      // ❌ v.size() 沒變，尾巴是垃圾值
   v.erase(unique(v.begin(), v.end()), v.end());   // ✅ 再 erase 掉尾巴
   ```

3. **`unique` 只處理「相鄰」的重複**

   ```cpp
   vector<int> v = {1, 2, 1};
   v.erase(unique(v.begin(), v.end()), v.end());   // ❌ 還是 {1, 2, 1}
   sort(v.begin(), v.end());                        // ✅ 先排序讓重複的靠在一起
   v.erase(unique(v.begin(), v.end()), v.end());   //    → {1, 2}
   ```

4. **在未排序的陣列上用 `lower_bound`**：不會報錯，但答案是錯的

   ```cpp
   vector<int> v = {5, 1, 4};
   auto it = lower_bound(v.begin(), v.end(), 4);   // ❌ 結果沒有意義
   sort(v.begin(), v.end());                        // ✅ 先排序
   auto it2 = lower_bound(v.begin(), v.end(), 4);
   ```

5. **空容器解參考 `max_element` 的結果**：空的時候回傳 `end()`，`*end()` 是未定義行為

   ```cpp
   int m = *max_element(v.begin(), v.end());        // ❌ v 為空時 UB
   if (v.empty()) return -1;                        // ✅ 先檢查
   int m2 = *max_element(v.begin(), v.end());
   ```

6. **以為 `max_element` 回傳索引**

   ```cpp
   int idx = max_element(v.begin(), v.end());       // ❌ 編譯錯誤：iterator 不能轉 int
   int idx2 = max_element(v.begin(), v.end()) - v.begin();  // ✅
   ```

7. **`greater<int>()` 與 `greater<int>` 搞混**：`sort` 要的是「物件」（有括號）；之後 `priority_queue` 的樣板參數要的是「型別」（沒括號，見 007）。

## 在 LeetCode 會怎麼用

- 很多題第一步就是 `sort(nums.begin(), nums.end())`，讓雙指標 / 貪婪 / 去重變得可行。
- 大數加總（陣列長度 1e5、元素到 1e9）一律 `accumulate(..., 0LL)` 或用 `long long` 變數累加。
- 「找最大值的位置」：`max_element(...) - nums.begin()` 一行搞定。
- 「排序陣列中某值出現幾次 / 第一個 >= x 的位置」：`upper_bound - lower_bound`、`lower_bound - begin()`，不必自己手寫二分。
- 座標壓縮：`sort` + `erase(unique(...))` + `lower_bound` 找排名，是中高階題的常見套路。

## 參考

- [std::sort](https://en.cppreference.com/w/cpp/algorithm/sort)
- [std::reverse](https://en.cppreference.com/w/cpp/algorithm/reverse)
- [std::accumulate](https://en.cppreference.com/w/cpp/algorithm/accumulate)
- [std::max_element](https://en.cppreference.com/w/cpp/algorithm/max_element) / [std::min_element](https://en.cppreference.com/w/cpp/algorithm/min_element)
- [std::distance](https://en.cppreference.com/w/cpp/iterator/distance)
- [std::lower_bound](https://en.cppreference.com/w/cpp/algorithm/lower_bound) / [std::upper_bound](https://en.cppreference.com/w/cpp/algorithm/upper_bound)
- [std::unique](https://en.cppreference.com/w/cpp/algorithm/unique)
- [std::greater](https://en.cppreference.com/w/cpp/utility/functional/greater)
