# 003 · 字串與字元

## 這一課學什麼

- `string` 的常用操作：`size`、`[]`、`+=`、`push_back`、`substr`、`find`、比較
- `char` 本質上是小整數：`c - 'a'`、`c - '0'`、`'a' + i` 的互相轉換
- `<cctype>` 字元判斷：`isalnum`、`isalpha`、`isdigit`、`isspace`、`tolower`、`toupper`
- 用 `int cnt[26]` 計數字母出現次數
- 用 `istringstream` 依空白切字；`stoi` / `to_string` 在字串與數字間轉換

## 語法速查

### string 基本操作

```cpp
#include <string>
string s = "hello";
s.size();                 // 5（型別是 size_t）
s[0];                     // 'h'（char）
s += " world";            // 串接字串
s += '!';                 // 串接一個字元
s.push_back('?');         // 同上
s.pop_back();             // 移除最後一個字元
s.empty();                // 是否為空
string t(3, 'x');         // "xxx"
for (char c : s) { }      // 逐字元走訪（唯讀）
for (char& c : s) c = toupper(c);   // 要修改就加 &
```

### substr 與 find

```cpp
string s = "abcdef";
s.substr(2, 3);           // "cde"：從 index 2 開始取 3 個字元
s.substr(4);              // "ef"：從 index 4 取到結尾
s.substr(4, 100);         // "ef"：長度超過會自動截斷
size_t pos = s.find("cd");                // 2
if (s.find("zz") == string::npos) { }     // 找不到回傳 string::npos
```

### char 與整數

```cpp
char c = 'e';
int idx = c - 'a';        // 4：字母 → 0~25
char back = 'a' + idx;    // 'e'：0~25 → 字母
int d = '7' - '0';        // 7：數字字元 → 數值
char ch = '0' + 7;        // '7'：數值 → 數字字元

#include <cctype>
isalnum('a'); isalpha('Z'); isdigit('5'); isspace(' ');   // 非 0 代表 true
char lower = tolower('A');   // 'a'（回傳 int，存成 char）
```

### 計數陣列

```cpp
int cnt[26] = {};                 // 全部初始化為 0
for (char c : s) cnt[c - 'a']++;  // 只適用小寫字母
```

### 依空白切字、字串 ↔ 數字

```cpp
#include <sstream>
istringstream iss("  the  sky is ");
string w;
while (iss >> w) { }              // 依序得到 "the" "sky" "is"，多餘空白自動略過

int n = stoi("-42");              // -42（long long 用 stoll）
string t = to_string(123);        // "123"

#include <algorithm>
reverse(s.begin(), s.end());      // 原地反轉字串
```

## 常見坑

1. **`'a'` 和 `"a"` 不一樣**：單引號是 `char`，雙引號是字串（`const char*`）。

   ```cpp
   if (s[0] == "a") { }   // ❌ 編譯錯誤：char 不能和字串比較
   if (s[0] == 'a') { }   // ✅
   ```

2. **兩個字串常值不能直接 `+`**：它們不是 `string`，是指標。

   ```cpp
   string r = "abc" + "def";          // ❌ 編譯錯誤
   string r = string("abc") + "def";  // ✅ 至少一邊是 string
   ```

3. **`substr` 第二個參數是長度，不是結束位置**

   ```cpp
   s.substr(i, j);       // ❌ 想取 [i, j) 卻寫成這樣
   s.substr(i, j - i);   // ✅
   ```

4. **字元數字直接當數值用**：`'7'` 的值是 55（ASCII），不是 7。

   ```cpp
   int d = s[i];         // ❌ '7' → 55
   int d = s[i] - '0';   // ✅ '7' → 7
   ```

5. **`tolower` / `isalnum` 傳入負值的 char**：非 ASCII 字元可能是負數，是未定義行為。

   ```cpp
   tolower(c);                        // ❌ c 可能是負的
   tolower((unsigned char)c);         // ✅
   ```

6. **在迴圈裡 `s = s + c`**：每次都產生新字串並複製，整體變 O(n²)。

   ```cpp
   for (char c : t) res = res + c;   // ❌
   for (char c : t) res += c;        // ✅ 原地附加
   ```

7. **`stoi` / `stoll` 超出範圍**：會丟出 `out_of_range` 例外，程式直接結束（`libc++abi: terminating`）。

   ```cpp
   long long x = stoll("99999999999999999999");  // ❌ 超過 long long
   // ✅ 超長數字一律逐位處理（Task E 的 addStrings）
   ```

8. **用 `int` 接 `find` 的結果再跟 -1 比**：`find` 回傳 `size_t`，正確寫法是和 `string::npos` 比較。

   ```cpp
   if ((int)s.find("x") == -1) { }      // ❌ 依賴轉型行為，不好讀
   if (s.find("x") == string::npos) { } // ✅
   ```

## 在 LeetCode 會怎麼用

- 「只有小寫英文字母」幾乎就是在暗示用 `int cnt[26]`，比 `unordered_map` 快又簡單（Anagram 類題目）。
- 迴文、反轉類題目：雙指標 + `isalnum` / `tolower`。
- 大數運算（Add Strings、Multiply Strings、Add Binary）：從尾端逐位處理 + 進位，最後 `reverse`。
- 解析輸入格式（例如 `"2-1+3"`、路徑 `"/a/./b/../"`）：`substr`、`find`、`istringstream`。

## 參考

- https://en.cppreference.com/w/cpp/string/basic_string
- https://en.cppreference.com/w/cpp/string/basic_string/substr
- https://en.cppreference.com/w/cpp/string/basic_string/find
- https://en.cppreference.com/w/cpp/string/basic_string/stol
- https://en.cppreference.com/w/cpp/string/basic_string/to_string
- https://en.cppreference.com/w/cpp/header/cctype
- https://en.cppreference.com/w/cpp/io/basic_istringstream
- https://en.cppreference.com/w/cpp/algorithm/reverse
