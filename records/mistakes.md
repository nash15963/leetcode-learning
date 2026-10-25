# C++ 錯誤本

> 記錄自己犯過的錯誤，`/check` 發現時會自動新增。**每週回顧一次**，同一類錯誤出現第二次時特別標記 ⚠️。

## 分類索引

| 類別 | 說明 | 次數 |
|---|---|---|
| 溢位 | `int` 相乘 / 相加超過範圍、`accumulate` 初始值型別 | 2 |
| 無號數 | `size_t` 減到負數變超大數、`v.size() - 1` 在空 vector | 1 |
| 越界 | index 超出範圍、對空容器呼叫 `top()` / `front()` / `back()` | 0 |
| 指標 | 解參考 `nullptr`、斷鏈、忘記 `delete` / use-after-free | 1 |
| 容器 | `map[key]` 自動插入、走訪時 erase 導致迭代器失效 | 0 |
| 效能 | 傳值造成不必要的複製（該用 `const&`）、迴圈中重複計算 | 0 |
| 邏輯 | 邊界條件、off-by-one、題意理解錯誤 | 6 |
| 語法 | 少分號、變數名稱蓋掉 std 函式、符號寫錯位置 | 1 |

## 紀錄

<!-- 格式範例：
### 2026-10-12 · 004 · 無號數
- ❌ `for (size_t i = v.size() - 1; i >= 0; i--)`
- ✅ `for (int i = (int)v.size() - 1; i >= 0; i--)`
- 💡 `size_t` 是無號整數，永遠 >= 0，迴圈不會結束；空 vector 時 `size() - 1` 會變成超大數
-->

### 2026-10-18 · 001 · 溢位
- ❌ `sumLoop`：`int tmp = 0; ... tmp += i;`；`sumFormula`：`return n * (n + 1) / 2;`（回傳型別是 `long long`）
- ✅ `long long tmp = 0;`、`return (long long)n * (n + 1) / 2;`
- 💡 回傳型別是 `long long` 不代表中間計算是 `long long`；運算的型別看運算元，要在運算**之前**轉型

### 2026-10-18 · 001 · 溢位 ⚠️
- ❌ `solveCases`：`long sum = 0;`
- ✅ `long long sum = 0;`
- 💡 `long` 在 macOS / Linux 64 位元是 64-bit 所以會過，但 Windows（MSVC）上只有 32-bit，40 億會溢位。要 64-bit 一律寫 `long long`

### 2026-10-18 · 001 · 邏輯
- ❌ `fizzBuzz` 的 `else`：`string tmp = to_string(i);` 之後 `push_back("Fizz")`
- ✅ `push_back(tmp)`（或直接 `push_back(to_string(i))`）
- 💡 actual 出現一大堆相同的值時，先檢查預設分支 push 的是什麼；沒用到的 `string` 變數編譯器**不會**警告

### 2026-10-18 · 001 · 邏輯 ⚠️
- ❌ `printTable`：`if (n <= 0) { cout << endl; }`（沿用了 Task A `printCountdown` 的規則）
- ✅ 整段刪掉，`n <= 0` 時迴圈本來就不會跑
- 💡 每一題的邊界條件都要回頭看題目，不要沿用上一題的規則

### 2026-10-18 · 001 · 邏輯 ⚠️
- ❌ `sumAll`：`in >> x;` 只在迴圈外讀一次，再用 `while (x)` 判斷
- ✅ `while (in >> x) { sum += x; }`
- 💡 讀取要放在 `while` 條件裡，每圈重讀一次；條件要判斷「讀取成功」而不是「值不是 0」（輸入有 0 會提早停）

### 2026-10-25 · 002 · 邏輯 ⚠️
- ❌ swap：`x = a; a = b; b = a;`
- ✅ `b = x;`
- 💡 執行到最後一行時 `a` 已經被改掉了，要用暫存的舊值

### 2026-10-25 · 002 · 邏輯 ⚠️
- ❌ `max(x, array[i]);`、`timeTmp - 1`
- ✅ `x = max(x, array[i]);`、`timeTmp--;`
- 💡 回傳值 / 運算結果要存回變數，`max` 和 `-` 都不會改到原本的變數；warning `expression result unused` 就是在提醒這件事。`timeTmp` 不減會變成無限迴圈

### 2026-10-25 · 002 · 邏輯 ⚠️
- ❌ `maxOf(a, b, c)` 的初始值 `int x = 0;`
- ✅ `int x = a;`（vector 版用 `nums[0]`）
- 💡 找最大 / 最小值時，初始值要用資料裡的值；資料全是負數時，0 會被當成答案

### 2026-10-25 · 002 · 無號數
- ❌ `i < array.size()`、`(int)i < array.size()`
- ✅ `i < (int)array.size()`、`int n = nums.size();`，或不需要 index 時用 `for (int v : nums)`
- 💡 `int` 和 `size()` 比較時，`int` 會被轉成無號數，`-1 < v.size()` 是 false；轉型要轉 `size()` 那一邊

### 2026-10-25 · 002 · 指標
- ❌ `findPtr`：`int* ta = nullptr;`、`ta = p*;`、找到時 `return ta;`（ta 一直是 nullptr）
- ✅ 找到就 `return p;`，迴圈跑完 `return nullptr;`
- 💡 `p` 本身就是位置，回傳位置不用加 `*`；`const int*` 不能放進 `int*`；型別有 `*` 是指標，`*p` 才是值

### 2026-10-25 · 002 · 語法
- ❌ 區域變數取名 `size`，再呼叫 `size(nums)` → `called object type 'int' is not a function`；`addToAll`、`repeatStr` 少分號
- ✅ 換名字（`count`、`ans`）；每個敘述結尾加 `;`
- 💡 變數名稱不要跟 std 函式撞名（`size`、`count`、`max`、`min`），`using namespace std;` 之後很容易衝突
