# 009 · struct 與 class — 練習題

> 先讀 notes.md。完成後執行 `make run Q=009`，全部 PASS 即完成。

所有程式碼都在 `main.cpp` 裡，把 `// TODO: 實作` 換成你的程式碼即可。**不要修改函式的簽名**（包含 `const`），測試程式會用到它們。

---

## Task A：Point — 建構子與 const 成員函式（★）

完成 `struct Point`：

```cpp
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}            // 已完成，當作範例
    Point(int px, int py);             // TODO：用 member initializer list
    int dist2() const;                 // 到原點距離的平方 x*x + y*y
    void move(int dx, int dy);         // x += dx, y += dy
    bool operator==(const Point& other) const;
};
```

範例：

```
Point p(3, 4);        p.x → 3, p.y → 4, p.dist2() → 25
const Point cp(-6, 8);  cp.dist2() → 100        （const 物件只能呼叫 const 成員函式）
Point m(1, 2); m.move(2, -5);  m == Point(3, -3) → true
Point(1, 2) == Point(2, 1)  → false
```

練到的概念：建構子、member initializer list、`const` 成員函式 vs 一般成員函式、`operator==`

提示：試著把 `dist2()` 後面的 `const` 拿掉編譯一次，看看錯誤訊息長什麼樣子（看完記得加回去）。

---

## Task B：Student — 讓 sort 和 set 認得你的 struct（★★）

`Student` 沒有建構子，所以可以用 `Student{"amy", 95}` 直接初始化（aggregate initialization）。請實作兩個比較運算子：

```cpp
struct Student {
    string name;
    int score;
    bool operator<(const Student& other) const;   // 「我要排在 other 前面嗎？」
    bool operator==(const Student& other) const;  // name 和 score 都相同
};
```

排序規則：**分數高的排前面**；分數相同時，`name` 字典序小的排前面。

範例：

```
sort 前：{dan 70}, {amy 95}, {cat 70}, {bob 95}, {eve 88}
sort 後：amy, bob, eve, cat, dan

set<Student> 放入 {amy 95}, {bob 80}, {amy 95}, {amy 60}, {cat 80}
→ size = 4，依序為 amy(95), bob(80), cat(80), amy(60)
```

練到的概念：`operator<` 決定 `sort` / `set` 的順序、strict weak ordering（相等時必須回傳 `false`）、`set` 用 `<` 判斷重複、`find` 用 `==`

提示：`set` 認為「`!(a < b) && !(b < a)`」的兩個元素是同一個。想想如果只比分數，`{bob 80}` 和 `{cat 80}` 會發生什麼事。

---

## Task C：BankAccount — private 成員與不變量（★★）

`balance_` 是 `private`，外面的程式碼只能透過成員函式改它。你的任務是讓**餘額永遠不會變成負數**，而且被拒絕的操作「什麼都不改」。

```cpp
class BankAccount {
public:
    BankAccount(const string& owner, long long initial);  // initial < 0 視為 0
    bool deposit(long long amount);    // amount <= 0 → false
    bool withdraw(long long amount);   // amount <= 0 或餘額不足 → false
    bool transferTo(BankAccount& other, long long amount);  // 規則同提款；不能轉給自己
    long long balance() const;         // 已完成
    const string& owner() const;       // 已完成
private:
    string owner_;
    long long balance_ = 0;
};
```

範例：

```
BankAccount a("alice", 100);
a.deposit(50)   → true,  balance 150
a.deposit(-10)  → false, balance 150
a.withdraw(200) → false, balance 150
a.withdraw(150) → true,  balance 0

BankAccount b("bob", -30);          → balance 0
BankAccount c("carol", 3000000000); c.transferTo(b, 120) → true，c = 2999999880，b = 120
c.transferTo(c, 10)                 → false（不能轉給自己）
```

練到的概念：`class` 預設 `private`、不變量、`const` getter、`long long`、物件**傳參考**、`this` 指標、同一個類別的成員函式可以存取「另一個物件」的 private 成員

提示：「是不是同一個物件」要比的是位址：`&other` 和 `this` 都是 `BankAccount*`。

---

## Task D：MinStack — LeetCode 設計題（★★★）

這是 LeetCode 155。設計一個 stack，除了一般的 `push` / `pop` / `top`，還能在 **O(1)** 取得目前的最小值。

```cpp
class MinStack {
public:
    MinStack();
    void push(int val);
    void pop();
    int top() const;
    int getMin() const;
private:
    // 你自己決定要存什麼
};
```

題目保證呼叫 `pop` / `top` / `getMin` 時 stack 不是空的。（LeetCode 原題的 `top()` / `getMin()` 沒有 `const`，但加上 `const` 是更好的習慣。）

範例：

```
push(-2), push(0), push(-3)
getMin() → -3
pop()
top()    → 0
getMin() → -2
```

練到的概念：設計題的 `class` 骨架、自己決定 `private` 成員、用 `vector<int>` 當 stack（`push_back` / `pop_back` / `back`）、O(1) 的設計思路

提示：`getMin()` 不能每次都掃一遍（那是 O(n)）。想想看：每一層除了存「這層的值」，還可以順便存什麼？也要注意最小值重複出現時，`pop` 之後的最小值還對不對。

---

## 完成檢查

- [ ] `make run Q=009` 全部 PASS
- [ ] 沒有任何 sanitizer 錯誤訊息（`runtime error` / `AddressSanitizer`）
- [ ] 能說出每個 Task 用到的概念（特別是：為什麼比較運算子要加 `const`？`set` 怎麼判斷兩個元素重複？`struct` 和 `class` 差在哪？）
