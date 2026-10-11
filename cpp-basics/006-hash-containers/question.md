# 006 · 雜湊容器與有序容器 — 練習題

> 先讀 notes.md。完成後執行 `make run Q=006`，全部 PASS 即完成。

所有函式都在 `main.cpp` 裡，把 `// TODO: 實作` 換成你的程式碼即可。

---

## Task A：單字頻率（★）

```cpp
unordered_map<string, int> wordFrequency(const string& text);
string mostFrequentWord(const string& text);
```

- `wordFrequency`：回傳每個單字出現的次數。單字之間可能有**多個空白**，開頭結尾也可能有空白。
- `mostFrequentWord`：回傳出現最多次的單字；**平手時回傳字典順序最小的**；沒有任何單字回傳 `""`。

範例：

```
wordFrequency    "the cat sat the"   → {the: 2, cat: 1, sat: 1}
wordFrequency    "  a   b a "        → {a: 2, b: 1}
mostFrequentWord "b a b c a b"       → "b"
mostFrequentWord "dog cat cat dog"   → "cat"   （dog、cat 都 2 次，cat 字典順序較小）
mostFrequentWord ""                  → ""
```

練到的概念：`unordered_map<string, int>`、`freq[w]++` 計數、`istringstream` 拆字、`for (const auto& [word, cnt] : freq)`

提示：`mostFrequentWord` 可以直接呼叫你寫好的 `wordFrequency`。

---

## Task B：operator[] 自動插入陷阱（★★）

```cpp
void addWords(unordered_map<string, int>& freq, const vector<string>& words);
bool hasKey(unordered_map<string, int>& m, const string& key);
int getOrDefault(const unordered_map<string, int>& m, const string& key, int def);
```

- `addWords`：把 `words` 每個字的次數**累加**進既有的 `freq`。
- `hasKey`：回傳 `key` 是否存在。**呼叫後 `m` 的大小不可以改變**（測試會檢查 `m.size()`）。值為 0 的 key 也算存在。
- `getOrDefault`：存在就回傳對應值，否則回傳 `def`。注意 `m` 是 `const`。

範例：

```
freq = {apple: 1}; addWords(freq, {"apple", "kiwi", "apple"})  → freq = {apple: 3, kiwi: 1}
m = {a: 1, zero: 0}
hasKey(m, "zero")     → true
hasKey(m, "missing")  → false，且 m.size() 仍然是 2
getOrDefault({x: 5}, "y", -1)  → -1
```

練到的概念：`operator[]` 何時好用（計數）、何時危險（查詢）、`count` / `find`、`const` 容器的限制、`it->second`

提示：試試看在 `getOrDefault` 裡寫 `m[key]`，讀懂編譯器的錯誤訊息。

---

## Task C：unordered_set 找重複（★★）

```cpp
int firstDuplicate(const vector<int>& nums);
vector<int> uniqueInOrder(const vector<int>& nums);
```

- `firstDuplicate`：由左往右掃，回傳第一個「**第二次出現**」的值；沒有重複回傳 `-1`。
- `uniqueInOrder`：去除重複，但**保留第一次出現的順序**（和 005 的 `sort` + `unique` 不同，順序不能變）。

範例：

```
firstDuplicate {2, 1, 3, 5, 3, 2}  → 3     （掃到索引 4 時 3 第二次出現，比 2 早）
firstDuplicate {1, 2, 3}           → -1
uniqueInOrder  {3, 1, 3, 2, 1}     → {3, 1, 2}
```

練到的概念：`unordered_set` 的 `count` / `insert`、`insert(x).second` 判斷是否為新元素、O(n) 取代 O(n²)

---

## Task D：有序 map / set（★★★）

```cpp
vector<pair<string, int>> sortedFrequency(const vector<string>& words);
int ceilingOf(const set<int>& s, int x);  // >= x 的最小元素，沒有回傳 -1
int floorOf(const set<int>& s, int x);    // <= x 的最大元素，沒有回傳 -1
```

範例：

```
sortedFrequency {"pear", "apple", "pear", "fig"}  → {(apple, 1), (fig, 1), (pear, 2)}
ceilingOf {1, 4, 9}, x = 5    → 9
ceilingOf {1, 4, 9}, x = 10   → -1
floorOf   {1, 4, 9}, x = 5    → 4
floorOf   {1, 4, 9}, x = 0    → -1
```

練到的概念：`map` 走訪時 key 已排序、`set::lower_bound` / `set::upper_bound`（成員函式）、iterator 往回走 `--it` / `prev(it)`、`begin()` / `end()` 邊界

提示：`floorOf` 可以先找「第一個 > x」的位置，再往前退一格；退之前要確認不是 `begin()`。

---

## Task E：邊走訪邊刪除（★★★）

```cpp
void removeRareWords(map<string, int>& freq, int minCount);  // 刪掉次數 < minCount 的
void removeMultiples(set<int>& s, int k);                    // 刪掉所有 k 的倍數
```

範例：

```
freq = {a: 1, b: 3, c: 2, d: 5}; removeRareWords(freq, 3)  → {b: 3, d: 5}
s = {1, 2, ..., 10};              removeMultiples(s, 3)     → {1, 2, 4, 5, 7, 8, 10}
s = {2, 4, 6};                    removeMultiples(s, 2)     → {}
```

練到的概念：`it = m.erase(it)` 慣用寫法、iterator 失效、for 迴圈裡什麼時候 `++it`

提示：先故意寫成「`erase(it)` 後再 `++it`」跑一次，觀察 AddressSanitizer 報的 `heap-use-after-free`，再改成正確寫法。

---

## 完成檢查

- [ ] `make run Q=006` 全部 PASS
- [ ] 沒有任何 sanitizer 錯誤訊息（`runtime error` / `AddressSanitizer`）
- [ ] 能說出每個 Task 用到的概念（特別是：什麼時候用 `[]`、什麼時候用 `count` / `find`？`map` 和 `unordered_map` 怎麼選？）
