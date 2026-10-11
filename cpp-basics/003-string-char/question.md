# 003 · 字串與字元 — 練習題

> 先讀 notes.md。完成後執行 `make run Q=003`，全部 PASS 即完成。

所有函式都在 `main.cpp` 裡，只要把 `// TODO: 實作` 換成你的程式碼即可，`main()` 裡的測試不用改。

---

## Task A：迴文判斷（★）

只看英文字母與數字（alphanumeric）、忽略大小寫，判斷 `s` 是不是迴文（palindrome）。
空字串、或去掉符號後變成空字串，都算迴文。

```cpp
bool isPalindrome(const string& s);
```

範例：

```
"A man, a plan, a canal: Panama" → true   （"amanaplanacanalpanama"）
"race a car"                     → false
" .,!"                           → true
"0P"                             → false  （數字也要算）
```

練到的概念：`<cctype>` 的 `isalnum` / `tolower`、雙指標（two pointers）、`s[i]` 取字元

提示：左右兩個 index 往中間走，遇到不是字母數字的就跳過。傳給 `isalnum` 的字元先轉成 `unsigned char`。

---

## Task B：字元計數 `int cnt[26]`（★★）

字串只包含小寫英文字母時，最快的計數方式是開一個長度 26 的陣列，用 `c - 'a'` 當 index。

1. `firstUniqChar`：回傳第一個「在整個字串只出現一次」的字元的 index，沒有就回傳 `-1`。
2. `canConstruct`：`magazine` 裡每個字母只能用一次，能不能拼出 `note`？

```cpp
int firstUniqChar(const string& s);
bool canConstruct(const string& note, const string& magazine);
```

範例：

```
firstUniqChar("loveleetcode") → 2   （'v'）
firstUniqChar("aabb")         → -1
canConstruct("aa", "ab")      → false
canConstruct("aa", "aab")     → true
```

練到的概念：`int cnt[26] = {};`（全部歸零）、`c - 'a'`、走兩遍（先計數、再查詢）

---

## Task C：substr 切片（★★）

1. `chunk`：把 `s` 每 `k` 個字元切成一段，最後一段可以不足 `k` 個。
2. `longestCommonPrefix`：回傳所有字串的最長共同前綴（`strs` 為空時回傳 `""`）。

```cpp
vector<string> chunk(const string& s, int k);
string longestCommonPrefix(const vector<string>& strs);
```

範例：

```
chunk("abcdefg", 3)                                → ["abc", "def", "g"]
chunk("", 4)                                       → []
longestCommonPrefix({"flower", "flow", "flight"})  → "fl"
longestCommonPrefix({"dog", "racecar", "car"})     → ""
```

練到的概念：`s.substr(pos, len)`（第二個參數是**長度**，不是結束位置）、`size()`、`const string&` 走訪

提示：`substr` 的 `len` 超過剩餘長度時會自動截到結尾，所以 `chunk` 不用特別處理最後一段。

---

## Task D：反轉單字順序（★★）

把句子裡的單字順序反轉。輸入可能有前後空白、單字之間可能有多個空白；輸出時單字之間只留一個空白，
頭尾不留空白。

```cpp
string reverseWords(const string& s);
```

範例：

```
"the sky is blue"   → "blue is sky the"
"  hello world  "   → "world hello"
"a good   example"  → "example good a"
"   "               → ""
```

練到的概念：`istringstream` + `>>` 自動以空白切字、`vector<string>`、`reverse`、字串串接

提示：`>>` 讀 `string` 時會自動跳過所有空白，正好解決「多個空白」的問題。

---

## Task E：字串數字相加（★★★）

1. `addSmall`：`a`、`b` 是 `int` 範圍內的整數字串（可能有負號），用 `stoi` 轉成數字相加，再用
   `to_string` 轉回字串。
2. `addStrings`：`a`、`b` 是**非負**整數字串，長度可能很長（超過 `long long`），所以不能轉成數字，
   要像小學直式加法一樣，從個位數開始逐位相加、處理進位（carry）。

```cpp
string addSmall(const string& a, const string& b);
string addStrings(const string& a, const string& b);
```

範例：

```
addSmall("12", "30")                         → "42"
addSmall("-5", "3")                          → "-2"
addStrings("456", "77")                      → "533"
addStrings("999", "1")                       → "1000"
addStrings("99999999999999999999", "1")      → "100000000000000000000"
```

練到的概念：`stoi` / `to_string`、`c - '0'` 和 `'0' + d` 的轉換、從尾端往前走、進位、最後 `reverse`

提示：用兩個 index 從 `a`、`b` 的尾端往前走，迴圈條件記得考慮「還有進位」。如果用 `stoll` 處理
`addStrings`，超長字串會丟出 `out_of_range` 例外讓程式直接結束。

---

## 完成檢查

- [ ] `make run Q=003` 全部 PASS
- [ ] 輸出中沒有 `runtime error:` 或 `AddressSanitizer` 等 sanitizer 錯誤
- [ ] 能說出每個 Task 用到的概念（例如：`'7' - '0'` 是多少？`s.substr(2, 3)` 取的是哪幾個字元？）
