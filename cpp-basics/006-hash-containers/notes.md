# 006 · 雜湊容器與有序容器（`unordered_map` / `unordered_set` / `map` / `set`）

## 這一課學什麼

- `unordered_map<K, V>`：雜湊表，統計次數、建索引的主力
- `unordered_set<T>`：快速判斷「看過沒」
- `map` / `set`：紅黑樹，**key 永遠由小到大排好**，還能找「>= x 的最小元素」
- `operator[]` 會**自動插入**預設值：計數時是好幫手，查詢時是陷阱
- 走訪中刪除元素的正確寫法：`it = m.erase(it)`
- range-for + structured binding：`for (const auto& [key, value] : m)`

## 語法速查

```cpp
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// ---- unordered_map：計數 ----
unordered_map<string, int> freq;
freq["apple"]++;              // key 不存在 → 先插入 {"apple", 0} 再 ++，計數就這樣寫
freq["kiwi"] = 5;             // 新增或覆蓋

// ---- 查詢（不會插入）----
if (freq.count("apple")) { }  // count 只會回傳 0 或 1
auto it = freq.find("pear");  // 找不到時 it == freq.end()
if (it != freq.end()) {
    cout << it->first << " " << it->second << "\n";  // first = key, second = value
}

// ---- 走訪（structured binding）----
for (const auto& [word, cnt] : freq) {   // 唯讀走訪
    cout << word << ": " << cnt << "\n";
}
for (auto& [word, cnt] : freq) cnt *= 2; // 要修改 value 就用 auto&

// ---- unordered_set ----
unordered_set<int> seen;
seen.insert(3);
bool isNew = seen.insert(3).second;  // false：已經存在，insert 沒有發生
seen.erase(3);

// ---- map / set：有序 ----
map<string, int> m = {{"pear", 2}, {"apple", 1}};
for (const auto& [k, v] : m) { }     // 依 key 字典順序：apple, pear

set<int> s = {1, 4, 9};
auto c = s.lower_bound(5);           // 第一個 >= 5 → 指向 9
if (c != s.end()) cout << *c;
auto f = s.upper_bound(5);           // 第一個 > 5 → 也指向 9
if (f != s.begin()) cout << *prev(f);// 往前一格 = 最大的 <= 5 → 4
int smallest = *s.begin();           // set 非空時：最小值
int largest = *s.rbegin();           // set 非空時：最大值

// ---- 走訪中刪除 ----
for (auto it2 = m.begin(); it2 != m.end();) {
    if (it2->second < 2) it2 = m.erase(it2);  // erase 回傳下一個有效的 iterator
    else ++it2;
}
```

### 複雜度

| 操作 | `unordered_map` / `unordered_set` | `map` / `set` |
|---|---|---|
| 插入 / 查詢 / 刪除 | 平均 O(1)，最差 O(n) | O(log n) |
| 走訪順序 | 不固定，不能依賴 | key 由小到大 |
| `lower_bound` / `upper_bound` | 不支援 | O(log n) |
| key 的要求 | 需要 hash（`pair` 預設沒有） | 需要 `<` 比較 |

## 常見坑

1. **用 `operator[]` 查詢 → 不存在的 key 被偷偷插入**

   ```cpp
   if (m[key] > 0) { }        // ❌ key 不存在時會插入 {key, 0}，m.size() 變大
   if (m.count(key)) { }      // ✅ 只查不插
   ```

   另一個副作用：值剛好是 0 的 key 會被誤判成「不存在」。

2. **`const` 的 map 不能用 `operator[]`**（因為它可能會插入）

   ```cpp
   int getBad(const unordered_map<string, int>& m) {
       return m["x"];                            // ❌ 編譯錯誤
   }
   int getGood(const unordered_map<string, int>& m) {
       auto it = m.find("x");                    // ✅ 用 find
       return it == m.end() ? 0 : it->second;
   }
   ```

   `m.at("x")` 也能用在 const map 上，但 key 不存在時會丟例外、程式直接中止。

3. **erase 之後還繼續用舊的 iterator**

   ```cpp
   for (auto it = m.begin(); it != m.end(); ++it)
       if (it->second < 2) m.erase(it);        // ❌ it 已失效，ASan 會報 heap-use-after-free
   for (auto it = m.begin(); it != m.end();)
       if (it->second < 2) it = m.erase(it);   // ✅ 拿 erase 的回傳值
       else ++it;
   ```

4. **對 `set` 用 `std::lower_bound`**：結果對，但是 O(n)，容易 TLE

   ```cpp
   auto slow = lower_bound(s.begin(), s.end(), x);  // ❌ set 的 iterator 不能跳，只能一步步走
   auto fast = s.lower_bound(x);                    // ✅ 成員函式，O(log n)
   ```

5. **依賴 `unordered_map` 的走訪順序**：每次結果可能不同。需要順序就改用 `map`，或把結果放進 vector 再 `sort`。

6. **structured binding 少了 `&`，改的是複本**

   ```cpp
   for (auto [k, v] : m) v = 0;    // ❌ 改到的是複製出來的 pair，m 沒變
   for (auto& [k, v] : m) v = 0;   // ✅
   ```

7. **`unordered_map<pair<int,int>, int>` 編譯失敗**：標準函式庫沒有提供 `pair` 的 hash。

   ```cpp
   unordered_map<pair<int, int>, int> bad;    // ❌ 編譯錯誤
   map<pair<int, int>, int> ok;               // ✅ 改用 map（pair 有 <）
   unordered_map<long long, int> ok2;         // ✅ 或把 (r, c) 編碼成 r * 100000LL + c
   ```

## 在 LeetCode 會怎麼用

- 「統計次數」：`unordered_map<int, int> cnt; for (int x : nums) cnt[x]++;`
- 「看過沒 / 有沒有重複」：`unordered_set<int>`，`insert(x).second` 一次完成「檢查 + 插入」。
- 「值 → 索引」的對照表：`unordered_map<int, int> pos;`（之後 013 Two Sum 就會用到）。
- 需要「有序 + 動態插入刪除 + 找前驅／後繼」：`set` / `map` 的 `lower_bound`（例如行事曆區間、滑動視窗中位數）。
- 雜湊表常見的模式是「一邊走訪一邊查詢」，把 O(n²) 的雙重迴圈降成 O(n)。

## 參考

- [std::unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map)
- [std::unordered_set](https://en.cppreference.com/w/cpp/container/unordered_set)
- [std::map](https://en.cppreference.com/w/cpp/container/map)
- [std::set](https://en.cppreference.com/w/cpp/container/set)
- [std::map::erase](https://en.cppreference.com/w/cpp/container/map/erase)
- [std::set::lower_bound](https://en.cppreference.com/w/cpp/container/set/lower_bound)
- [Structured binding declaration](https://en.cppreference.com/w/cpp/language/structured_binding)
