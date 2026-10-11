# 001 · 輸入輸出與流程控制

## 這一課學什麼

- C++ 程式的骨架：`#include`、`using namespace std;`、`int main()`
- 在這個 repo 編譯、執行、看懂測試結果：`make run Q=001`
- 輸出：`cout`、`"\n"` vs `endl`、用 `setw` 對齊
- 流程控制：`if / else`、`for`、`while`、`%`（取餘數）
- 整數型別：`int` 的上限 `INT_MAX` 與 `long long`，避免溢位（overflow）
- 輸入：`cin >> x`、`while (in >> x)` 一路讀到 EOF（ACM 模式必備）
- 看懂 ASan / UBSan（sanitizer）的錯誤訊息

## 語法速查

### 程式骨架

```cpp
#include <iostream>   // cout / cin 宣告在這個標頭檔
#include <vector>     // 用到什麼就 include 什麼（本 repo 不用 <bits/stdc++.h>）
using namespace std;  // 之後可以寫 cout，而不用寫 std::cout

int main() {
    cout << "Hello" << "\n";
    return 0;         // 0 代表正常結束
}
```

- `#include <xxx>`：把標準函式庫的宣告引入進來。少 include 會看到 `use of undeclared identifier 'xxx'`。
- `using namespace std;`：標準函式庫的東西都放在 `std` 命名空間（namespace）裡。LeetCode 的環境已經幫你寫好這行，
  所以練習時照寫；正式專案（尤其是 header 檔）一般不建議這樣做，以免名稱衝突。

### 編譯與執行（這個 repo）

```bash
make run Q=001     # 編譯 cpp-basics/001-*/main.cpp 並執行測試
make build Q=001   # 只編譯，不執行
```

每個測試會印出 `✅ PASS` 或 `❌ FAIL`（失敗時附上 expected / actual），最後一行是通過數。

### 輸出與對齊

```cpp
#include <iomanip>                // setw 在這裡
cout << 1 << " " << 2 << "\n";    // 1 2
cout << setw(4) << 7 << "|\n";    // "   7|"：靠右、寬度 4
cout << setw(4) << 1 << 2 << "\n";// "   12"：setw 只影響「下一個」輸出
```

### 型別與溢位

```cpp
#include <climits>
int a = INT_MAX;                  // 2147483647（約 2.1 × 10^9）
long long b = 9000000000LL;       // long long 約 ±9.2 × 10^18，字面值加 LL
long long c = (long long)a * 2;   // 先轉型再乘 → 4294967294
```

### 流程控制

```cpp
for (int i = 1; i <= 10; i++) { /* 跑 10 次 */ }

int k = 3;
while (k > 0) { k--; }            // 條件為 true 就一直跑

if (n % 15 == 0) { /* 15 的倍數 */ }
else if (n % 3 == 0) { /* 3 的倍數 */ }
else { /* 其他 */ }
```

### 輸入

```cpp
int x;
cin >> x;                         // 讀一個整數，自動跳過空白與換行
long long sum = 0;
while (cin >> x) sum += x;        // 讀到 EOF（或格式錯誤）時條件變 false
```

把 `cin` 換成 `istream&` 參數，就能用 `istringstream` 假裝輸入來測試：

```cpp
long long readSum(istream& in) { long long s = 0; int x; while (in >> x) s += x; return s; }
istringstream fake("1 2 3");      // #include <sstream>
readSum(fake);                    // 測試用 → 6
readSum(cin);                     // 真的從鍵盤 / 檔案讀
```

## 常見坑

1. **加總用 `int` 溢位**：1 加到 100000 = 5000050000，超過 `INT_MAX`。

   ```cpp
   int sum = 0;  for (int i = 1; i <= n; i++) sum += i;        // ❌ 溢位（UB）
   long long sum = 0;  for (int i = 1; i <= n; i++) sum += i;  // ✅
   ```

2. **回傳 `long long` 但中間用 `int` 算**：右邊整個算完才轉型，太晚了。

   ```cpp
   long long r = n * (n + 1) / 2;              // ❌ n * (n + 1) 先用 int 算就爆了
   long long r = (long long)n * (n + 1) / 2;   // ✅ 先把其中一個轉成 long long
   ```

3. **行尾多一個空白**：線上評測常常逐字比對。

   ```cpp
   for (int i = 1; i <= 3; i++) cout << i << " ";                    // ❌ "1 2 3 "
   for (int i = 1; i <= 3; i++) { if (i > 1) cout << " "; cout << i; } // ✅ "1 2 3"
   ```

4. **整數除法會捨去小數**：`7 / 2 == 3`。要小數就讓其中一邊是 `double`。

   ```cpp
   double avg = sum / n;          // ❌ 先做整數除法
   double avg = (double)sum / n;  // ✅
   ```

5. **用 `eof()` 當迴圈條件**：最後一次讀取已經失敗了，迴圈主體卻照樣多跑一輪。

   ```cpp
   while (!cin.eof()) { cin >> x; sum += x; }  // ❌
   while (cin >> x) { sum += x; }              // ✅
   ```

6. **大量輸出用 `endl`**：`endl` 每次都會 flush，比 `"\n"` 慢很多，資料量大時可能 TLE。

   ```cpp
   cout << ans << endl;   // ❌ 輸出很多行時很慢
   cout << ans << "\n";   // ✅
   ```

## 執行與除錯：看懂 sanitizer 訊息

這個 repo 編譯時開了 `-fsanitize=address,undefined`，程式「做錯事」時會直接告訴你在哪一行：

```text
main.cpp:44:38: runtime error: signed integer overflow: 2147450880 + 65536 cannot be represented in type 'int'
```

- **UBSan**（UndefinedBehaviorSanitizer）：`runtime error: ...` 開頭，常見的有 `signed integer overflow`
  （int 溢位）、`division by zero`、`load of null pointer`。`檔名:行:欄` 就是出事的位置。
- **ASan**（AddressSanitizer）：`ERROR: AddressSanitizer: heap-buffer-overflow`（陣列越界）、
  `heap-use-after-free`（用到已釋放的記憶體）等，程式會直接停止。往下看 stack trace，找第一個
  在 `main.cpp` 的那一行（例如 `#1 ... in fizzBuzz(int) main.cpp:47`）。

看到這些訊息時，就算測試顯示 PASS 也代表程式有 bug，要修掉。

## 在 LeetCode 會怎麼用

- LeetCode 是「函式模式」：只要實作 `class Solution` 裡的函式，**不用**寫 `main`、不用 `cin` / `cout`。
- 但「題目數字範圍 × 運算次數」是否會超過 `int`，每題都要想一次：看到 `10^5` 個 `10^9` 相加、
  或兩個 `10^5` 相乘，就要用 `long long`。
- ACM 模式（部分面試平台、競賽）要自己讀輸入、印輸出：記住 `while (cin >> x)`、先讀筆數再讀資料，
  並用 `"\n"` 取代 `endl`。

## 參考

- https://en.cppreference.com/w/cpp/io/cout
- https://en.cppreference.com/w/cpp/io/manip/setw
- https://en.cppreference.com/w/cpp/language/for
- https://en.cppreference.com/w/cpp/language/while
- https://en.cppreference.com/w/cpp/language/types
- https://en.cppreference.com/w/cpp/types/climits
- https://en.cppreference.com/w/cpp/io/basic_istream/operator_gtgt
- https://clang.llvm.org/docs/AddressSanitizer.html
- https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html
