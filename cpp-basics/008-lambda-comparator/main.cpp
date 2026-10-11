// 008 · Lambda 與自訂比較（capture / sort comparator / 遞迴 lambda）
// 執行：make run Q=008
// 題目說明見 question.md

#include <algorithm>   // sort, stable_sort, count_if, for_each, max
#include <cstdlib>     // abs
#include <functional>  // function
#include <numeric>     // iota
#include <string>
#include <unordered_map>
#include <utility>     // pair
#include <vector>

#include "lc/test.hpp"

using namespace std;

// ===== Task A：lambda 語法與 capture =====

// 回傳大於 threshold 的元素個數。請用 count_if + lambda（capture threshold）
int countGreaterThan(const vector<int>& nums, int threshold) {
    // TODO: 實作
    return 0;
}

// 回傳所有偶數的總和。請用 for_each + lambda（用 [&] 累加到外面的變數）
int sumOfEvens(const vector<int>& nums) {
    // TODO: 實作
    return 0;
}

// 把每個元素加上 delta（原地修改）。請用 for_each + lambda
void addToAll(vector<int>& nums, int delta) {
    // TODO: 實作
}

// ===== Task B：多鍵排序 =====

// 先依長度由短到長；長度相同依字典順序
void sortByLengthThenAlpha(vector<string>& words) {
    // TODO: 實作
}

// 先依絕對值由小到大；絕對值相同時，數值小的（負數）在前
void sortByAbsThenValue(vector<int>& nums) {
    // TODO: 實作
}

// pair = (名字, 分數)。先依分數由高到低；分數相同依名字字典順序
void sortByScoreThenName(vector<pair<string, int>>& students) {
    // TODO: 實作
}

// ===== Task C：區間排序與合併 =====

// 每個區間是 {start, end}（start <= end）。合併所有重疊（含端點相接）的區間，依 start 由小到大回傳
vector<vector<int>> mergeIntervals(vector<vector<int>> intervals) {
    // TODO: 實作
    return {};
}

// ===== Task D：comparator 捕捉外部資料 =====

// 依出現次數由少到多排序；次數相同時，數值大的在前
vector<int> sortByFrequency(vector<int> nums) {
    // TODO: 實作
    return {};
}

// 回傳「索引」陣列：依 nums[i] 由小到大排列；值相同時索引小的在前
vector<int> argsort(const vector<int>& nums) {
    // TODO: 實作
    return {};
}

// ===== Task E：遞迴 lambda — 網格 DFS =====

// '1' 是陸地、'0' 是水；上下左右相連的陸地算同一座島。回傳島嶼數量
int countIslands(vector<vector<char>> grid) {
    // TODO: 實作
    return 0;
}

// 1 是陸地、0 是水；回傳面積（格子數）最大的島嶼面積；沒有陸地回傳 0
int maxIslandArea(vector<vector<int>> grid) {
    // TODO: 實作
    return 0;
}

int main() {
    lc::section("Task A：lambda 語法與 capture");
    CHECK_EQ(countGreaterThan({1, 5, 8, 3, 10}, 4), 3);
    CHECK_EQ(countGreaterThan({-5, -1, 0}, -2), 2);
    CHECK_EQ(sumOfEvens({1, 2, 3, 4, 6}), 12);
    CHECK_EQ(sumOfEvens({-2, 3, 8}), 6);
    {
        vector<int> a = {1, 2, 3};
        addToAll(a, 10);
        CHECK_EQ(a, {11, 12, 13});
    }
    {
        vector<int> a = {-1, 0};
        addToAll(a, -5);
        CHECK_EQ(a, {-6, -5});
    }

    lc::section("Task B：多鍵排序");
    {
        vector<string> w = {"banana", "kiwi", "apple", "fig", "date"};
        sortByLengthThenAlpha(w);
        CHECK_EQ(w, {"fig", "date", "kiwi", "apple", "banana"});
    }
    {
        vector<string> w = {"bb", "a", "ab", "c", "ba"};
        sortByLengthThenAlpha(w);
        CHECK_EQ(w, {"a", "c", "ab", "ba", "bb"});
    }
    {
        vector<int> a = {-3, 2, -2, 1, 0};
        sortByAbsThenValue(a);
        CHECK_EQ(a, {0, 1, -2, 2, -3});
    }
    {
        vector<int> a = {5, -5, 5, -5};
        sortByAbsThenValue(a);
        CHECK_EQ(a, {-5, -5, 5, 5});
    }
    {
        vector<pair<string, int>> s = {{"bob", 85}, {"cat", 90}, {"dan", 70}, {"amy", 90}};
        sortByScoreThenName(s);
        CHECK_EQ(s, {{"amy", 90}, {"cat", 90}, {"bob", 85}, {"dan", 70}});
    }

    lc::section("Task C：區間排序與合併");
    CHECK_EQ(mergeIntervals({{1, 3}, {2, 6}, {8, 10}, {15, 18}}), {{1, 6}, {8, 10}, {15, 18}});
    CHECK_EQ(mergeIntervals({{1, 4}, {4, 5}}), {{1, 5}});
    CHECK_EQ(mergeIntervals({{8, 10}, {1, 3}, {2, 6}}), {{1, 6}, {8, 10}});
    CHECK_EQ(mergeIntervals({{1, 10}, {2, 3}, {4, 5}}), {{1, 10}});
    CHECK_EQ(mergeIntervals({{5, 7}}), {{5, 7}});
    CHECK_EQ(mergeIntervals({}), {});

    lc::section("Task D：comparator 捕捉外部資料");
    CHECK_EQ(sortByFrequency({1, 1, 2, 2, 2, 3}), {3, 1, 1, 2, 2, 2});
    CHECK_EQ(sortByFrequency({2, 3, 1, 3, 2}), {1, 3, 3, 2, 2});
    CHECK_EQ(sortByFrequency({-1, 1, -6, 4, 5, -6, 1, 4, 1}), {5, -1, 4, 4, -6, -6, 1, 1, 1});
    CHECK_EQ(argsort({30, 10, 20}), {1, 2, 0});
    CHECK_EQ(argsort({5, 1, 5, 1}), {1, 3, 0, 2});
    CHECK_EQ(argsort({7}), {0});

    lc::section("Task E：遞迴 lambda — 網格 DFS");
    CHECK_EQ(countIslands({{'1', '1', '0', '0'},
                           {'1', '0', '0', '1'},
                           {'0', '0', '1', '1'}}),
             2);
    CHECK_EQ(countIslands({{'1', '0', '1'},
                           {'0', '1', '0'},
                           {'1', '0', '1'}}),
             5);
    CHECK_EQ(countIslands({}), 0);
    CHECK_EQ(maxIslandArea({{0, 1, 1},
                            {1, 1, 0},
                            {0, 0, 1}}),
             4);
    CHECK_EQ(maxIslandArea({{1, 0, 1},
                            {0, 0, 0},
                            {1, 1, 1}}),
             3);
    CHECK_EQ(maxIslandArea({{1, 1, 1},
                            {1, 0, 1},
                            {1, 1, 1}}),
             8);

    return lc::summary();
}
