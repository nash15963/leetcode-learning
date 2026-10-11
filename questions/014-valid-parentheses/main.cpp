// 014 · Valid Parentheses（LeetCode #20）
// 執行：make run Q=014
// 題目說明見 question.md；class Solution 可以直接貼到 LeetCode 送出

#include <stack>
#include <string>

#include "lc/test.hpp"
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // TODO: 實作
        return false;
    }
};

int main() {
    Solution sol;

    lc::section("範例");
    CHECK_EQ(sol.isValid("()"), true);
    CHECK_EQ(sol.isValid("()[]{}"), true);
    CHECK_EQ(sol.isValid("(]"), false);
    CHECK_EQ(sol.isValid("([])"), true);

    lc::section("邊界");
    CHECK_EQ(sol.isValid("([)]"), false);  // 交錯
    CHECK_EQ(sol.isValid("{[]}"), true);   // 巢狀
    CHECK_EQ(sol.isValid("("), false);     // 只有左括號
    CHECK_EQ(sol.isValid("]"), false);     // 一開始就是右括號（stack 為空）
    CHECK_EQ(sol.isValid("(("), false);    // 結束時 stack 不為空
    return lc::summary();
}
