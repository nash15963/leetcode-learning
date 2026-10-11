// 013 · Two Sum（LeetCode #1）
// 執行：make run Q=013
// 題目說明見 question.md；class Solution 可以直接貼到 LeetCode 送出

#include <algorithm>
#include <unordered_map>
#include <vector>

#include "lc/test.hpp"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // TODO: 實作
        return {};
    }
};

// ---------- 測試用，不用改 ----------
// 題目允許任意順序回傳，所以先排序再比較
vector<int> solve(vector<int> nums, int target) {
    vector<int> ans = Solution().twoSum(nums, target);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    lc::section("範例");
    CHECK_EQ(solve({2, 7, 11, 15}, 9), {0, 1});
    CHECK_EQ(solve({3, 2, 4}, 6), {1, 2});
    CHECK_EQ(solve({3, 3}, 6), {0, 1});

    lc::section("邊界");
    CHECK_EQ(solve({-1, -2, -3, -4, -5}, -8), {2, 4});
    CHECK_EQ(solve({0, 4, 3, 0}, 0), {0, 3});
    CHECK_EQ(solve({1000000000, -1000000000, 7}, 0), {0, 1});
    return lc::summary();
}
