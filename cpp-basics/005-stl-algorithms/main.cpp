// 005 · STL 演算法（sort / accumulate / max_element / lower_bound / unique）
// 執行：make run Q=005
// 題目說明見 question.md

#include <algorithm>   // sort, reverse, max_element, min_element, lower_bound, upper_bound, unique
#include <climits>     // INT_MAX
#include <functional>  // greater, multiplies
#include <iterator>    // distance
#include <numeric>     // accumulate
#include <string>
#include <vector>

#include "lc/test.hpp"

using namespace std;

// ===== Task A：排序與反轉 =====

// 由小到大排序（原地修改 nums）
void sortAscending(vector<int>& nums) {
    // TODO: 實作
}

// 由大到小排序（原地修改 nums），請使用 greater<int>()
void sortDescending(vector<int>& nums) {
    // TODO: 實作
}

// 回傳反轉後的字串（s 是複製進來的，可以直接修改）
string reversedString(string s) {
    // TODO: 實作
    return "";
}

// ===== Task B：加總與 0LL 陷阱 =====

// 回傳所有元素的總和（總和可能超過 int 範圍）
long long sumAll(const vector<int>& nums) {
    // TODO: 實作
    return 0;
}

// 回傳所有元素的乘積（空陣列回傳 1）
long long productAll(const vector<int>& nums) {
    // TODO: 實作
    return 0;
}

// ===== Task C：最大／最小值與索引 =====

// 回傳「最大值第一次出現」的索引；空陣列回傳 -1
int indexOfMax(const vector<int>& nums) {
    // TODO: 實作
    return 0;
}

// 回傳「最小值第一次出現」的索引；空陣列回傳 -1
int indexOfMin(const vector<int>& nums) {
    // TODO: 實作
    return 0;
}

// 回傳 最大值 - 最小值；空陣列回傳 0
int maxMinusMin(const vector<int>& nums) {
    // TODO: 實作
    return -1;
}

// ===== Task D：在排序好的陣列上二分搜尋 =====

// sorted 已由小到大排序。回傳 target 出現的次數
int countOccurrences(const vector<int>& sorted, int target) {
    // TODO: 實作
    return -1;
}

// sorted 已由小到大排序。回傳 target 應該插入的位置（第一個 >= target 的索引）
int insertPosition(const vector<int>& sorted, int target) {
    // TODO: 實作
    return -1;
}

// sorted 已由小到大排序。回傳落在閉區間 [lo, hi] 內的元素個數
int countInRange(const vector<int>& sorted, int lo, int hi) {
    // TODO: 實作
    return -1;
}

// ===== Task E：去重（unique + erase）=====

// 只移除「相鄰」的重複元素（不要排序），例如 {1,1,2,2,1} → {1,2,1}
void removeAdjacentDuplicates(vector<int>& nums) {
    // TODO: 實作
}

// 排序後去掉所有重複，例如 {3,1,3,2} → {1,2,3}
void sortAndDedupe(vector<int>& nums) {
    // TODO: 實作
}

// 回傳「第 k 小的不同值」（k 從 1 開始）；不同值不足 k 個時回傳 -1
int kthSmallestDistinct(vector<int> nums, int k) {
    // TODO: 實作
    return 0;
}

int main() {
    lc::section("Task A：排序與反轉");
    {
        vector<int> a = {5, 2, 9, 1, 5};
        sortAscending(a);
        CHECK_EQ(a, {1, 2, 5, 5, 9});
    }
    {
        vector<int> a = {-3, 0, -10, 7};
        sortAscending(a);
        CHECK_EQ(a, {-10, -3, 0, 7});
    }
    {
        vector<int> a = {5, 2, 9, 1, 5};
        sortDescending(a);
        CHECK_EQ(a, {9, 5, 5, 2, 1});
    }
    {
        vector<int> a = {-1, -7, 3};
        sortDescending(a);
        CHECK_EQ(a, {3, -1, -7});
    }
    CHECK_EQ(reversedString("hello"), "olleh");
    CHECK_EQ(reversedString("ab"), "ba");

    lc::section("Task B：加總與 0LL 陷阱");
    CHECK_EQ(sumAll({1, 2, 3, 4}), 10);
    CHECK_EQ(sumAll({INT_MAX, INT_MAX}), 4294967294LL);
    CHECK_EQ(sumAll({2000000000, 2000000000, -1}), 3999999999LL);
    CHECK_EQ(productAll({2, 3, 4}), 24);
    CHECK_EQ(productAll({100000, 100000}), 10000000000LL);
    CHECK_EQ(productAll({}), 1);

    lc::section("Task C：最大／最小值與索引");
    CHECK_EQ(indexOfMax({3, 9, 2, 9}), 1);
    CHECK_EQ(indexOfMax({}), -1);
    CHECK_EQ(indexOfMin({5, 4, 3, 2, 1}), 4);
    CHECK_EQ(indexOfMin({7, -2, 8, -2}), 1);
    CHECK_EQ(maxMinusMin({3, 9, 1, 7}), 8);
    CHECK_EQ(maxMinusMin({}), 0);

    lc::section("Task D：在排序好的陣列上二分搜尋");
    CHECK_EQ(countOccurrences({1, 2, 2, 2, 3, 5}, 2), 3);
    CHECK_EQ(countOccurrences({1, 2, 2, 2, 3, 5}, 4), 0);
    CHECK_EQ(insertPosition({1, 3, 5, 6}, 5), 2);
    CHECK_EQ(insertPosition({1, 3, 5, 6}, 7), 4);
    CHECK_EQ(countInRange({1, 2, 2, 3, 5, 8}, 2, 5), 4);
    CHECK_EQ(countInRange({1, 2, 2, 3, 5, 8}, 6, 7), 0);

    lc::section("Task E：去重（unique + erase）");
    {
        vector<int> a = {1, 1, 2, 2, 1, 1};
        removeAdjacentDuplicates(a);
        CHECK_EQ(a, {1, 2, 1});
    }
    {
        vector<int> a = {4, 4, 4};
        removeAdjacentDuplicates(a);
        CHECK_EQ(a, {4});
    }
    {
        vector<int> a = {3, 1, 3, 2, 1};
        sortAndDedupe(a);
        CHECK_EQ(a, {1, 2, 3});
    }
    {
        vector<int> a = {5, 5, 5, 5};
        sortAndDedupe(a);
        CHECK_EQ(a, {5});
    }
    CHECK_EQ(kthSmallestDistinct({5, 3, 3, 1, 5, 2}, 2), 2);
    CHECK_EQ(kthSmallestDistinct({5, 3, 3, 1, 5, 2}, 5), -1);

    return lc::summary();
}
