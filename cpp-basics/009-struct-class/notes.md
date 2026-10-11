# 009 · struct 與 class

## 這一課學什麼

- 用 `struct` 把相關資料綁在一起，寫**建構子**並用 **member initializer list** 初始化成員
- `const` 成員函式：保證「不會修改物件」，`const` 物件 / `const&` 參數只能呼叫它
- 自訂 `operator<` / `operator==`，讓你的 struct 可以直接丟進 `sort`、`set`、`find`
- `class` + `private`：把資料藏起來，只開放安全的操作，維持**不變量**（invariant）
- `this` 指標、物件要「傳參考」才會改到本尊
- LeetCode **設計題**（Design problem）的標準長相：`class MinStack { public: ... private: ... };`

## 語法速查

```cpp
// ---- struct + 建構子 ----
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}                // 預設建構子
    Point(int x, int y) : x(x), y(y) {}    // member initializer list：成員(值)
                                           // x(x)：外面的 x 是成員，括號裡是參數
    int dist2() const { return x * x + y * y; }  // const 成員函式：不改物件
    void move(int dx, int dy) { x += dx; y += dy; }  // 會改物件 → 不加 const
};

Point a;            // 呼叫 Point()     → (0, 0)
Point b(3, 4);      // 呼叫 Point(int, int)
Point c{3, 4};      // 大括號也可以
vector<Point> v(5); // 5 個 Point()，所以 vector<T>(n) 需要預設建構子

// ---- 沒寫建構子的 struct：aggregate，直接用 {} 依序填欄位 ----
struct Student {
    string name;
    int score;
    // 「a < b」的意思是「a 要排在 b 前面」
    bool operator<(const Student& o) const {
        if (score != o.score) return score > o.score;  // 分數高的在前
        return name < o.name;                           // 同分比名字
    }
    bool operator==(const Student& o) const { return name == o.name && score == o.score; }
};
Student s{"amy", 95};
vector<Student> cls = {{"bob", 80}, {"amy", 95}};
sort(cls.begin(), cls.end());   // 不傳 comparator → 自動用 operator<
set<Student> st(cls.begin(), cls.end());  // set / map 的 key 也靠 operator<

// 多個欄位「全部由小到大」比較時，tie 很方便（#include <tuple>）
// return tie(x, y) < tie(o.x, o.y);

// ---- class：預設 private ----
class Counter {
public:                         // 外面可以用
    explicit Counter(int limit) : limit_(limit) {}  // explicit：禁止 Counter c = 5; 這種隱式轉換
    bool inc() {                // 只能透過這個函式改 count_，所以永遠不會超過 limit_
        if (count_ >= limit_) return false;
        count_++;
        return true;
    }
    int value() const { return count_; }
    bool same(const Counter& other) const { return this == &other; }  // this：指向自己的指標
private:                        // 只有成員函式能碰
    int limit_;
    int count_ = 0;             // default member initializer
};
Counter cnt(2);
cnt.inc();          // OK
// cnt.count_ = 99; // ❌ 編譯錯誤：'count_' is a private member
```

### struct vs class

| | `struct` | `class` |
|---|---|---|
| 預設存取權限 | `public` | `private` |
| 慣例用途 | 單純的資料包（Point、Edge、ListNode） | 有規則要保護的物件（設計題、BankAccount） |

除了預設權限，兩者**完全一樣**，都能有建構子、成員函式、`private`。

## 常見坑

1. **忘記在成員函式加 `const`** → `const` 物件或 `const&` 參數呼叫不了

   ```cpp
   int dist2() { return x * x + y * y; }        // ❌
   void f(const Point& p) { p.dist2(); }        //    error: 'this' argument to member function 'dist2' has type 'const Point', but function is not marked const
   int dist2() const { return x * x + y * y; }  // ✅
   ```

2. **`operator<` 用 `<=` 寫** → 不是 strict weak ordering，`sort` 可能當掉、`set` 行為錯亂

   ```cpp
   return score <= o.score;   // ❌ a < a 會是 true
   return score < o.score;    // ✅ 「相等」時一定要回傳 false
   ```

3. **`set` 用 `operator<` 判斷重複**：`!(a < b) && !(b < a)` 就當成同一個元素

   ```cpp
   bool operator<(const Student& o) const { return score > o.score; }  // ❌ 同分不同名會被 set 吃掉
   // ✅ 所有「會讓兩個物件不同」的欄位都要比到
   ```

4. **`operator==` 沒加 `const`**：C++20 下會出現 `-Wambiguous-reversed-operator` 警告

   ```cpp
   bool operator==(const Point& o) { ... }        // ❌
   bool operator==(const Point& o) const { ... }  // ✅ 比較運算子一律 const
   ```

5. **在建構子「本體」賦值，而不是用 initializer list**：`const` 成員、參考成員、沒有預設建構子的成員都只能用 initializer list

   ```cpp
   Point(int px, int py) { x = px; y = py; }  // ❌ 能動，但先預設初始化再賦值
   Point(int px, int py) : x(px), y(py) {}    // ✅
   ```

   另外，initializer list 的**執行順序 = 成員宣告順序**，不是你寫的順序（寫反會有 `-Wreorder` 警告）。

6. **物件傳值 → 改到的是複本**

   ```cpp
   bool transferTo(BankAccount other, long long amt);   // ❌ other 是複本，對方餘額沒變
   bool transferTo(BankAccount& other, long long amt);  // ✅ 傳參考
   ```

7. **類別定義結尾忘記分號**

   ```cpp
   struct Point { int x; }    // ❌ error: expected ';' after struct
   struct Point { int x; };   // ✅
   ```

8. **`class` 忘記寫 `public:`** → 全部都是 private，LeetCode 會編譯失敗

## 在 LeetCode 會怎麼用

- 每一題的答案本身就是 `class Solution { public: ... };`，可以在 `private:` 放 helper 函式和共用的成員變數（例如 `vector<vector<int>> memo;`）。
- **設計題**（MinStack、LRU Cache、Trie、Iterator…）：題目給你 `class` 的骨架，你決定 `private` 成員，並讓每個操作符合時間複雜度。
- 圖論 / 排程題常自訂 `struct Edge { int u, v, w; }` 或 `struct State`，再寫 `operator<` 丟進 `sort`、`set`、`priority_queue`。
- 需要多欄位排序時，`operator<`（或 008 的 lambda comparator）二選一；`set` / `map` 的 key 用 `operator<` 最省事。

## 參考

- [Classes](https://en.cppreference.com/w/cpp/language/classes)
- [Constructors and member initializer lists](https://en.cppreference.com/w/cpp/language/constructor)
- [const member functions](https://en.cppreference.com/w/cpp/language/member_functions#const-_and_volatile-qualified_member_functions)
- [Operator overloading（比較運算子）](https://en.cppreference.com/w/cpp/language/operators#Comparison_operators)
- [Access specifiers（public / private）](https://en.cppreference.com/w/cpp/language/access)
- [Aggregate initialization](https://en.cppreference.com/w/cpp/language/aggregate_initialization)
- [std::tie](https://en.cppreference.com/w/cpp/utility/tuple/tie)
- [Compare（strict weak ordering 的要求）](https://en.cppreference.com/w/cpp/named_req/Compare)
