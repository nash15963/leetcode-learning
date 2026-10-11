// 017 · Binary Tree Level Order Traversal（LeetCode #102）
// 執行：make run Q=017
// 題目說明見 question.md；class Solution 可以直接貼到 LeetCode 送出
// TreeNode 的定義在 include/lc/structures.hpp（和 LeetCode 一樣）

#include <queue>
#include <vector>

#include "lc/structures.hpp"
#include "lc/test.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // TODO: 實作
        return {};
    }
};

// ---------- 測試用，不用改 ----------
// lc::null 代表 LeetCode 輸入裡的 null
vector<vector<int>> solve(const vector<int>& levelVals) {
    TreeNode* root = lc::make_tree(levelVals);
    vector<vector<int>> ans = Solution().levelOrder(root);
    lc::free_tree(root);
    return ans;
}

int main() {
    const int null = lc::null;

    lc::section("範例");
    CHECK_EQ(solve({3, 9, 20, null, null, 15, 7}), {{3}, {9, 20}, {15, 7}});
    CHECK_EQ(solve({1}), {{1}});
    CHECK_EQ(solve({}), {});

    lc::section("邊界");
    CHECK_EQ(solve({1, 2, null, 3, null, 4}), {{1}, {2}, {3}, {4}});  // 一路往左
    CHECK_EQ(solve({1, null, 2, null, 3}), {{1}, {2}, {3}});          // 一路往右
    CHECK_EQ(solve({1, 2, 3, 4, 5, 6, 7}), {{1}, {2, 3}, {4, 5, 6, 7}});
    CHECK_EQ(solve({-1, 0, 1000}), {{-1}, {0, 1000}});
    return lc::summary();
}
