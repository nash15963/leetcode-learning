// 015 · Group Anagrams（LeetCode #49）
// 執行：make run Q=015
// 題目說明見 question.md；class Solution 可以直接貼到 LeetCode 送出

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

#include "lc/test.hpp"
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // TODO: 實作
        return {};
    }
};

// ---------- 測試用，不用改 ----------
// 題目允許任意順序回傳：每組內排序，再把所有組排序，方便比較
vector<vector<string>> solve(vector<string> strs) {
    vector<vector<string>> groups = Solution().groupAnagrams(strs);
    for (auto& g : groups) sort(g.begin(), g.end());
    sort(groups.begin(), groups.end());
    return groups;
}

int main() {
    lc::section("範例");
    CHECK_EQ(solve({"eat", "tea", "tan", "ate", "nat", "bat"}),
             {{"ate", "eat", "tea"}, {"bat"}, {"nat", "tan"}});
    CHECK_EQ(solve({""}), {{""}});
    CHECK_EQ(solve({"a"}), {{"a"}});

    lc::section("邊界");
    CHECK_EQ(solve({"", ""}), {{"", ""}});                        // 兩個空字串是同一組
    CHECK_EQ(solve({"ab", "ba", "abc"}), {{"ab", "ba"}, {"abc"}});  // 長度不同不會同組
    CHECK_EQ(solve({"aab", "aba", "abb"}), {{"aab", "aba"}, {"abb"}});  // 字母相同但次數不同
    return lc::summary();
}
