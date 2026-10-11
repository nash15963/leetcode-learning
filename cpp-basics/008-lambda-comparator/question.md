# 008 · Lambda 與自訂比較 — 練習題

> 先讀 notes.md。完成後執行 `make run Q=008`，全部 PASS 即完成。

所有函式都在 `main.cpp` 裡，把 `// TODO: 實作` 換成你的程式碼即可。這一課每一題都請**用 lambda** 完成（不要另外寫具名的比較函式）。

---

## Task A：lambda 語法與 capture（★）

```cpp
int countGreaterThan(const vector<int>& nums, int threshold);  // count_if + [threshold]
int sumOfEvens(const vector<int>& nums);                       // for_each + [&]
void addToAll(vector<int>& nums, int delta);                   // for_each，原地修改
```

範例：

```
countGreaterThan {1, 5, 8, 3, 10}, threshold = 4   → 3
countGreaterThan {-5, -1, 0},      threshold = -2  → 2
sumOfEvens       {1, 2, 3, 4, 6}                   → 12
addToAll         {1, 2, 3}, delta = 10             → {11, 12, 13}
```

練到的概念：lambda 基本語法、`[x]` 複製 capture、`[&]` 參考 capture、lambda 參數用 `int&` 修改元素

提示：試著在 `sumOfEvens` 把 `[&]` 改成 `[=]`，看看編譯器說什麼。

---

## Task B：多鍵排序（★★）

```cpp
void sortByLengthThenAlpha(vector<string>& words);
void sortByAbsThenValue(vector<int>& nums);
void sortByScoreThenName(vector<pair<string, int>>& students);
```

- `sortByLengthThenAlpha`：先依**長度由短到長**；長度相同依**字典順序**。
- `sortByAbsThenValue`：先依**絕對值由小到大**；絕對值相同時**數值小的在前**（-5 在 5 前面）。
- `sortByScoreThenName`：`pair` 是 `(名字, 分數)`。先依**分數由高到低**；分數相同依**名字字典順序**。

範例：

```
{"banana", "kiwi", "apple", "fig", "date"}  → {"fig", "date", "kiwi", "apple", "banana"}
{-3, 2, -2, 1, 0}                           → {0, 1, -2, 2, -3}
{(bob, 85), (cat, 90), (dan, 70), (amy, 90)} → {(amy, 90), (cat, 90), (bob, 85), (dan, 70)}
```

練到的概念：`sort` 第三個參數傳 lambda、多鍵比較的 `if (第一鍵不同) return ...; return 第二鍵比較;` 寫法、comparator 參數用 `const T&`

---

## Task C：區間排序與合併（★★）

```cpp
vector<vector<int>> mergeIntervals(vector<vector<int>> intervals);
```

每個區間是 `{start, end}`。合併所有重疊的區間（**端點相接也算重疊**，例如 `[1,4]` 和 `[4,5]`），回傳依 `start` 由小到大的結果。輸入不保證已排序。

範例：

```
{{1, 3}, {2, 6}, {8, 10}, {15, 18}}  → {{1, 6}, {8, 10}, {15, 18}}
{{1, 4}, {4, 5}}                     → {{1, 5}}
{{8, 10}, {1, 3}, {2, 6}}            → {{1, 6}, {8, 10}}
{{1, 10}, {2, 3}, {4, 5}}            → {{1, 10}}      （後面的區間被整個包住）
{}                                   → {}
```

練到的概念：用 lambda 依 `start` 排序二維陣列、`back()` 取得結果中最後一個區間並原地修改、`max` 更新右端點

提示：被「整個包住」的區間會讓 `end = cur[1]` 這種寫法出錯。

---

## Task D：comparator 捕捉外部資料（★★★）

```cpp
vector<int> sortByFrequency(vector<int> nums);
vector<int> argsort(const vector<int>& nums);
```

- `sortByFrequency`：依每個值的**出現次數由少到多**排序；次數相同時，**數值大的在前**。
- `argsort`：不改動 `nums`，回傳「索引」陣列，使得 `nums[idx[0]] <= nums[idx[1]] <= ...`；值相同時**索引小的在前**。

範例：

```
sortByFrequency {1, 1, 2, 2, 2, 3}   → {3, 1, 1, 2, 2, 2}
sortByFrequency {2, 3, 1, 3, 2}      → {1, 3, 3, 2, 2}   （2 和 3 都出現 2 次，3 較大排前面）
argsort         {30, 10, 20}         → {1, 2, 0}
argsort         {5, 1, 5, 1}         → {1, 3, 0, 2}
```

練到的概念：先用 `unordered_map` 統計（006）再讓 lambda 用 `[&]` 捕捉它、對「索引」排序但比較「值」、`iota` 產生 0..n-1

提示：`argsort` 的「值相同時索引小的在前」可以在 comparator 裡多比一鍵，或改用 `stable_sort`。

---

## Task E：遞迴 lambda — 網格 DFS（★★★）

```cpp
int countIslands(vector<vector<char>> grid);  // '1' 陸地、'0' 水
int maxIslandArea(vector<vector<int>> grid);  // 1 陸地、0 水
```

上下左右相連的陸地算同一座島（斜對角**不算**相連）。

- `countIslands`：回傳島嶼數量。
- `maxIslandArea`：回傳最大島嶼的面積（格子數）；沒有陸地回傳 0。

範例（countIslands）：

```
1 1 0 0
1 0 0 1   → 2
0 0 1 1

1 0 1
0 1 0     → 5   （斜角不相連，每個 1 都是獨立的島）
1 0 1
```

範例（maxIslandArea）：

```
0 1 1
1 1 0     → 4
0 0 1

1 1 1
1 0 1     → 8   （環狀）
1 1 1
```

練到的概念：`function<void(int, int)>` / `function<int(int, int)>` 遞迴 lambda、`[&]` 捕捉 `grid` 與大小、先檢查邊界再存取、把走過的格子改掉當作「已拜訪」標記

提示：這裡參數是傳值（複製一份 grid），所以你可以直接修改它。LeetCode 上常見的簽名是 `vector<vector<char>>& grid`，寫法相同。記得處理空的 grid。

---

## 完成檢查

- [ ] `make run Q=008` 全部 PASS
- [ ] 沒有任何 sanitizer 錯誤訊息（`runtime error` / `AddressSanitizer`）
- [ ] 能說出每個 Task 用到的概念（特別是：`[=]` 和 `[&]` 差在哪？comparator 為什麼不能用 `<=`？遞迴 lambda 為什麼不能用 `auto`？）
