// 016 · Reverse Linked List（LeetCode #206）
// 執行：make run Q=016
// 題目說明見 question.md；class Solution 可以直接貼到 LeetCode 送出
// ListNode 的定義在 include/lc/structures.hpp（和 LeetCode 一樣）

#include <vector>

#include "lc/structures.hpp"
#include "lc/test.hpp"
using namespace std;

class Solution {
public:
    // Task A：迭代版
    ListNode* reverseList(ListNode* head) {
        // TODO: 實作
        return nullptr;
    }

    // Task B：遞迴版（Follow-up）
    ListNode* reverseListRecursive(ListNode* head) {
        // TODO: 實作
        return nullptr;
    }
};

// ---------- 測試用，不用改 ----------
// 先記下所有節點，最後統一 delete：就算答案還沒寫好也不會洩漏記憶體；
// 走訪時最多走 n 步，避免寫錯產生環狀串列時卡死
vector<int> solve(const vector<int>& vals, bool recursive) {
    ListNode* head = lc::make_list(vals);
    vector<ListNode*> nodes;
    for (ListNode* p = head; p != nullptr; p = p->next) nodes.push_back(p);

    Solution sol;
    ListNode* result = recursive ? sol.reverseListRecursive(head) : sol.reverseList(head);

    vector<int> out;
    for (ListNode* p = result; p != nullptr && out.size() <= nodes.size(); p = p->next) {
        out.push_back(p->val);
    }
    for (ListNode* p : nodes) delete p;
    return out;
}

int main() {
    for (bool recursive : {false, true}) {
        lc::section(recursive ? "Task B：遞迴版" : "Task A：迭代版");
        CHECK_EQ(solve({1, 2, 3, 4, 5}, recursive), {5, 4, 3, 2, 1});
        CHECK_EQ(solve({1, 2}, recursive), {2, 1});
        CHECK_EQ(solve({7}, recursive), {7});
        CHECK_EQ(solve({}, recursive), {});
        CHECK_EQ(solve({-5000, 0, 5000}, recursive), {5000, 0, -5000});
    }
    return lc::summary();
}
