# 001 · 輸入輸出與流程控制 — 練習題

> 先讀 notes.md。完成後執行 `make run Q=001`，全部 PASS 即完成。

所有函式都在 `main.cpp` 裡，只要把 `// TODO: 實作` 換成你的程式碼即可，`main()` 裡的測試不用改。

---

## Task A：從 1 印到 10（★）

寫兩個「印東西」的函式：

1. `print1To10()`：用 **for 迴圈** 印出 1 到 10，數字之間一個空白，最後換行。
2. `printCountdown(n)`：用 **while 迴圈** 從 `n` 倒數印到 `1`，格式同上；`n <= 0` 時只印一個換行。

```cpp
void print1To10();
void printCountdown(int n);
```

範例：

```
print1To10()      → "1 2 3 4 5 6 7 8 9 10\n"
printCountdown(5) → "5 4 3 2 1\n"
printCountdown(0) → "\n"
```

練到的概念：`for`、`while`、`cout <<`、行尾不要多一個空白

提示：「第一個數字前面不印空白，之後每個數字前面印一個空白」比「每個數字後面印空白」好處理。

---

## Task B：1 加到 n 與 int 溢位（★）

計算 `1 + 2 + ... + n`（`n <= 0` 回傳 0），寫兩個版本：

1. `sumLoop(n)`：用迴圈一個一個加。
2. `sumFormula(n)`：用公式 `n * (n + 1) / 2`。

```cpp
long long sumLoop(int n);
long long sumFormula(int n);
```

範例：

```
sumLoop(10)              → 55
sumLoop(100000)          → 5000050000
sumFormula(2000000000)   → 2000000001000000000
```

練到的概念：`int` 上限 `INT_MAX`（約 21 億）、`long long`、「先轉型再運算」

提示：回傳型別是 `long long` **不代表**中間的計算也是 `long long`。如果看到
`runtime error: signed integer overflow`，代表你的某個 `int` 爆了。

---

## Task C：FizzBuzz（★★）

回傳一個長度為 `n` 的 `vector<string>`，第 `i` 個（從 1 開始數）元素是：

- `i` 是 15 的倍數 → `"FizzBuzz"`
- `i` 是 3 的倍數 → `"Fizz"`
- `i` 是 5 的倍數 → `"Buzz"`
- 其他 → `i` 本身轉成字串

```cpp
vector<string> fizzBuzz(int n);
```

範例：

```
fizzBuzz(5) → ["1", "2", "Fizz", "4", "Buzz"]
fizzBuzz(0) → []
```

練到的概念：`if / else if` 的判斷順序、`%`、`vector::push_back`、`to_string`

---

## Task D：乘法表（★★）

印出 `n × n` 的乘法表：第 `i` 行（1-based）的第 `j` 個數字是 `i * j`，每個數字用 `setw(4)`
靠右對齊（寬度 4），每行結尾換行。`n <= 0` 時什麼都不印。

```cpp
void printTable(int n);
```

範例（`·` 代表空白）：

```
printTable(3)
···1···2···3
···2···4···6
···3···6···9
```

`printTable(10)` 的最後一行是 `··10··20··30··40··50··60··70··80··90·100`。

練到的概念：巢狀迴圈、`#include <iomanip>`、`setw` 只影響「下一個」輸出

---

## Task E：讀到 EOF — ACM 模式暖身（★★★）

有些線上測驗（ACM 模式）要你自己從 `cin` 讀輸入。為了能測試，這裡的函式改成接收
`istream& in`：測試時傳 `istringstream`，真正使用時傳 `cin`，寫法完全一樣。

1. `sumAll(in)`：一直讀整數直到讀不到（EOF）為止，回傳總和。
2. `solveCases(in)`：第一行是測資筆數 `T`，接下來 `T` 行，每行開頭是 `k`，後面接 `k` 個整數。
   對每筆測資**印出**這 `k` 個整數的總和，一筆一行。

```cpp
long long sumAll(istream& in);
void solveCases(istream& in);
```

範例：

```
sumAll("1 2 3")                    → 6
sumAll("")                         → 0
solveCases("2\n3 1 2 3\n2 10 20\n") → 印出 "6\n30\n"
```

練到的概念：`while (in >> x)`、`istream&` 參數、先讀筆數再讀資料、大數加總用 `long long`

提示：`in >> x` 本身就是條件，讀成功是 true、讀到 EOF 是 false。每個數字本身不超過
`int`，但加起來可能會。

---

## 完成檢查

- [ ] `make run Q=001` 全部 PASS
- [ ] 輸出中沒有 `runtime error:` 或 `AddressSanitizer` 等 sanitizer 錯誤
- [ ] 能說出每個 Task 用到的概念（例如：為什麼 `sumFormula` 要先轉成 `long long` 再乘？）
