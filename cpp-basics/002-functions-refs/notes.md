# 002 · 函式、參考與指標

## 這一課學什麼

- 函式的宣告、定義與呼叫；函式要「先宣告再使用」
- 三種傳參方式：傳值（by value）、參考（`T&`）、唯讀參考（`const T&`）
- 指標（pointer）基礎：`&x` 取位址、`*p` 解參考、`nullptr`、指標加減走訪陣列
- 用 `pair` 回傳兩個值，搭配 structured binding（結構化繫結）`auto [a, b]`
- 函式多載（overload）與預設引數（default argument）

## 語法速查

### 函式與傳參

```cpp
int add(int a, int b) { return a + b; }        // 傳值：參數是複製品

void inc(int& x) { x++; }                      // 參考：x 就是呼叫端的變數本身
int n = 1; inc(n);                             // n == 2

int total(const vector<int>& v) {              // 唯讀參考：不複製、也不能改
    int s = 0;
    for (int x : v) s += x;                    // x 是複製（int 很小，沒關係）
    return s;
}

void doubleAll(vector<int>& v) {
    for (int& x : v) x *= 2;                   // int& 才能改到 vector 裡的元素
}
```

### 指標

```cpp
int a = 10;
int* p = &a;          // p 存的是 a 的位址
*p = 20;              // 透過指標改 a → a == 20
int* q = nullptr;     // 空指標：不指向任何東西
if (q != nullptr) { /* 確認不是空的才解參考 */ }

int arr[] = {1, 2, 3, 4};
int* it = arr;        // 陣列名稱會自動轉成「指向第一個元素的指標」
it++;                 // 指向 arr[1]
int third = *(arr + 2);  // 等同 arr[2]
for (int* ptr = arr; ptr != arr + 4; ptr++) cout << *ptr;  // [arr, arr+4) 走一遍

vector<int> v = {5, 6};
int* d = v.data();    // vector 底層陣列的指標
```

`const int* p`：不能透過 `p` 改值（唯讀）；`int* const p`：`p` 本身不能指向別處。

### pair 與 structured binding

```cpp
#include <utility>
pair<int, int> divmod(int a, int b) { return {a / b, a % b}; }

pair<int, int> r = divmod(17, 5);
cout << r.first << " " << r.second;   // 3 2
auto [q2, rem] = divmod(17, 5);       // C++17：直接拆成兩個變數
pair<string, int> pr = {"age", 18};   // 兩個型別可以不同
```

### 多載與預設引數

```cpp
int area(int side) { return side * side; }       // 同名、參數不同 → overload
int area(int w, int h) { return w * h; }

string greet(const string& name, const string& prefix = "Hi") {  // 預設引數放最右邊
    return prefix + ", " + name;
}
greet("Amy");            // "Hi, Amy"
greet("Amy", "Hello");   // "Hello, Amy"
```

## 常見坑

1. **傳值的 swap 不會生效**：改到的是複製品。

   ```cpp
   void swapV(int a, int b) { int t = a; a = b; b = t; }    // ❌ 呼叫端不變
   void swapR(int& a, int& b) { int t = a; a = b; b = t; }  // ✅
   ```

2. **大型參數傳值**：每次呼叫都複製整個 vector，遞迴裡會 TLE / MLE。

   ```cpp
   int dfs(vector<int> v, int i);         // ❌ 每層都複製 O(n)
   int dfs(const vector<int>& v, int i);  // ✅ 不複製
   ```

3. **range-for 想修改元素卻沒加 `&`**

   ```cpp
   for (int x : v) x += 1;   // ❌ 改的是複製品，v 不變
   for (int& x : v) x += 1;  // ✅
   ```

4. **最大值初始為 0**：全是負數時答案錯。

   ```cpp
   int best = 0;        // ❌ maxOf({-5, -3}) 會得到 0
   int best = nums[0];  // ✅（或 INT_MIN，要 #include <climits>）
   ```

5. **回傳區域變數的參考 / 指標**：函式結束後變數就消失了（dangling，UB）。

   ```cpp
   int& bad() { int x = 1; return x; }   // ❌ -Wall 會警告
   int good() { int x = 1; return x; }   // ✅ 回傳值
   ```

6. **對 `nullptr` 解參考**：UBSan 先印 `runtime error: load of null pointer`，接著 ASan 報
   `SEGV on unknown address 0x000000000000`，程式崩潰。

   ```cpp
   int v = *findPtr(a, a + n, 99);                // ❌ 找不到時是 nullptr
   const int* p = findPtr(a, a + n, 99);
   int v = (p != nullptr) ? *p : -1;              // ✅ 先檢查
   ```

7. **一行宣告多個指標**：`*` 只跟著它右邊的變數。

   ```cpp
   int* a, b;    // ❌ a 是 int*，b 只是 int
   int* a; int* b;  // ✅
   ```

8. **預設引數不在最右邊**

   ```cpp
   void f(int a = 1, int b);   // ❌ 編譯錯誤
   void f(int b, int a = 1);   // ✅
   ```

## 在 LeetCode 會怎麼用

- 題目給的函式簽名常是 `vector<int>& nums`（可修改的參考）：可以直接原地修改，例如原地排序、去重。
- 自己寫的 helper / DFS 一律用 `const vector<int>&` 或 `vector<int>&` 傳大物件，避免複製。
- 需要回傳兩個值（例如區間 `[l, r]`、`{min, max}`）時用 `pair`，接收時用 `auto [l, r] = ...`。
- 指標是 Linked List（010）與 Tree（011）的基礎：`node->next`、`root == nullptr` 都是這一課的延伸。

## 參考

- https://en.cppreference.com/w/cpp/language/function
- https://en.cppreference.com/w/cpp/language/reference
- https://en.cppreference.com/w/cpp/language/pointer
- https://en.cppreference.com/w/cpp/language/nullptr
- https://en.cppreference.com/w/cpp/utility/pair
- https://en.cppreference.com/w/cpp/language/structured_binding
- https://en.cppreference.com/w/cpp/language/overload_resolution
- https://en.cppreference.com/w/cpp/language/default_arguments
