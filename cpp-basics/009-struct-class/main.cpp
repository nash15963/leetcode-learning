// 009 · struct 與 class（建構子 / const 成員函式 / operator< / private / 設計題）
// 執行：make run Q=009
// 題目說明見 question.md

#include <algorithm>  // sort, find, min_element
#include <climits>    // INT_MAX, INT_MIN
#include <set>
#include <string>
#include <vector>

#include "lc/test.hpp"

using namespace std;

// ===== Task A：Point — 建構子與 const 成員函式 =====

struct Point {
    int x;
    int y;

    // 預設建構子（範例，已完成）：用 member initializer list 把 x、y 設成 0
    Point() : x(0), y(0) {}

    // TODO: 實作 — 改成用 member initializer list 把 x 設成 px、y 設成 py
    Point(int px, int py) : x(0), y(0) {}

    // 回傳到原點距離的「平方」：x*x + y*y（不會修改物件 → 標成 const）
    int dist2() const {
        // TODO: 實作
        return -1;
    }

    // 往 (dx, dy) 方向移動（會修改物件 → 不能是 const）
    void move(int dx, int dy) {
        // TODO: 實作
    }

    // 兩個點的 x、y 都相同才算相等
    bool operator==(const Point& other) const {
        // TODO: 實作
        return false;
    }
};

// ===== Task B：Student — 讓 sort 和 set 認得你的 struct =====

struct Student {
    string name;
    int score;

    // 排序規則：分數「高」的排前面；分數相同時，name 字典序小的排前面
    bool operator<(const Student& other) const {
        // TODO: 實作
        return false;
    }

    // name 和 score 都相同才算相等
    bool operator==(const Student& other) const {
        // TODO: 實作
        return false;
    }
};

// 測試用，不用改：把 Student 陣列轉成名字陣列，方便比對與印出
vector<string> namesOf(const vector<Student>& students) {
    vector<string> out;
    for (const Student& s : students) out.push_back(s.name);
    return out;
}

// ===== Task C：BankAccount — private 成員與不變量 =====

class BankAccount {
public:
    // 開戶：initial < 0 時視為 0
    BankAccount(const string& owner, long long initial) {
        // TODO: 實作（建議用 member initializer list）
    }

    // 存款：amount <= 0 → 拒絕，回傳 false，什麼都不改
    bool deposit(long long amount) {
        // TODO: 實作
        return false;
    }

    // 提款：amount <= 0 或餘額不足 → 拒絕，回傳 false，什麼都不改
    bool withdraw(long long amount) {
        // TODO: 實作
        return false;
    }

    // 轉帳給 other：規則同提款；不能轉給自己（拒絕）
    bool transferTo(BankAccount& other, long long amount) {
        // TODO: 實作
        return false;
    }

    // 以下兩個 getter 已完成，不用改
    long long balance() const { return balance_; }
    const string& owner() const { return owner_; }

private:
    string owner_;
    long long balance_ = 0;  // 不變量：永遠 >= 0
};

// ===== Task D：MinStack — LeetCode 設計題 =====
// push / pop / top / getMin 全部 O(1)。題目保證呼叫 pop / top / getMin 時 stack 不是空的。

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        // TODO: 實作
    }

    void pop() {
        // TODO: 實作
    }

    int top() const {
        // TODO: 實作
        return 0;
    }

    int getMin() const {
        // TODO: 實作
        return 0;
    }

private:
    // TODO: 自己決定要存哪些成員
};

int main() {
    lc::section("Task A：Point — 建構子與 const 成員函式");
    {
        Point origin;
        CHECK_EQ(origin.x, 0);
        Point p(3, 4);
        CHECK_EQ(p.x, 3);
        CHECK_EQ(p.y, 4);
        CHECK_EQ(p.dist2(), 25);
        const Point cp(-6, 8);  // const 物件只能呼叫 const 成員函式
        CHECK_EQ(cp.dist2(), 100);
        Point m(1, 2);
        m.move(2, -5);
        CHECK(m == Point(3, -3));
        CHECK(!(Point(1, 2) == Point(2, 1)));
    }

    lc::section("Task B：Student — 讓 sort 和 set 認得你的 struct");
    {
        Student amy90{"amy", 90}, bob90{"bob", 90}, amy80{"amy", 80}, amy91{"amy", 91};
        Student amy90copy = amy90;
        CHECK(bob90 < amy80);  // 分數高的排前面
        CHECK(amy90 < bob90);  // 同分 → 名字小的排前面
        CHECK(!(bob90 < amy90));
        CHECK(!(amy90 < amy90copy));  // 相等的兩個物件，誰都不 < 誰
        CHECK(amy90 == amy90copy);
        CHECK(!(amy90 == amy91));

        vector<Student> cls = {{"dan", 70}, {"amy", 95}, {"cat", 70}, {"bob", 95}, {"eve", 88}};
        sort(cls.begin(), cls.end());  // 沒有傳 comparator → 用你的 operator<
        CHECK_EQ(namesOf(cls), {"amy", "bob", "eve", "cat", "dan"});
        CHECK(find(cls.begin(), cls.end(), Student{"eve", 88}) != cls.end());  // find 用 operator==

        set<Student> s = {{"amy", 95}, {"bob", 80}, {"amy", 95}, {"amy", 60}, {"cat", 80}};
        CHECK_EQ(s.size(), 4);  // 完全相同的 {"amy", 95} 只留一個
        CHECK_EQ(namesOf(vector<Student>(s.begin(), s.end())), {"amy", "bob", "cat", "amy"});
    }

    lc::section("Task C：BankAccount — private 成員與不變量");
    {
        BankAccount a("alice", 100);
        CHECK_EQ(a.owner(), "alice");
        CHECK_EQ(a.balance(), 100);
        CHECK(a.deposit(50));
        CHECK_EQ(a.balance(), 150);
        CHECK(!a.deposit(0));
        CHECK(!a.deposit(-10));
        CHECK(!a.withdraw(200));  // 餘額不足
        CHECK_EQ(a.balance(), 150);
        CHECK(a.withdraw(150));
        CHECK_EQ(a.balance(), 0);

        BankAccount b("bob", -30);  // 負的初始金額 → 0
        CHECK_EQ(b.balance(), 0);

        BankAccount c("carol", 3000000000LL);  // 超過 int 範圍
        CHECK(c.transferTo(b, 120));
        CHECK_EQ(c.balance(), 2999999880LL);
        CHECK_EQ(b.balance(), 120);
        CHECK(!b.transferTo(c, 121));  // 餘額不足
        CHECK(!c.transferTo(c, 10));   // 不能轉給自己
        CHECK_EQ(c.balance(), 2999999880LL);
    }

    lc::section("Task D：MinStack — LeetCode 設計題");
    {
        MinStack st;  // LeetCode 155 的範例
        st.push(-2);
        st.push(0);
        st.push(-3);
        CHECK_EQ(st.getMin(), -3);
        st.pop();
        CHECK_EQ(st.top(), 0);
        CHECK_EQ(st.getMin(), -2);

        MinStack dup;  // 最小值重複出現
        dup.push(1);
        dup.push(1);
        dup.push(2);
        dup.pop();
        dup.pop();
        CHECK_EQ(dup.getMin(), 1);

        MinStack ext;  // 極端值
        ext.push(INT_MAX);
        ext.push(INT_MIN);
        CHECK_EQ(ext.getMin(), INT_MIN);
        ext.pop();
        CHECK_EQ(ext.getMin(), INT_MAX);

        // 跟暴力解比對 200 次 push + 200 次 pop
        MinStack big;
        vector<int> mirror;
        int mismatch = 0;
        for (int i = 0; i < 200; i++) {
            int v = (i * 37) % 101 - 50;
            big.push(v);
            mirror.push_back(v);
            if (big.top() != v || big.getMin() != *min_element(mirror.begin(), mirror.end())) {
                mismatch++;
            }
        }
        while (!mirror.empty()) {
            if (big.top() != mirror.back() ||
                big.getMin() != *min_element(mirror.begin(), mirror.end())) {
                mismatch++;
            }
            big.pop();
            mirror.pop_back();
        }
        CHECK_EQ(mismatch, 0);
    }

    return lc::summary();
}
