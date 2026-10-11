// 004 · vector、陣列與切片
// 執行：make run Q=004
// 題目說明見 question.md

#include <string>
#include <utility>  // pair
#include <vector>

#include "lc/test.hpp"

using namespace std;

// ===== Task A：vector 基本操作 =====

// 用 push_back 收集 nums 中所有偶數（包含負數和 0），保持原本順序
vector<int> keepEvens(const vector<int>& nums) {
    // TODO: 實作
    return {};
}

// 用 emplace_back 產生 {index, 值} 的 pair 列表
vector<pair<int, int>> withIndex(const vector<int>& nums) {
    // TODO: 實作
    return {};
}

// 把 st 當成堆疊（stack）：從尾端一直 pop_back，直到 back() == target 為止（target 本身保留）；
// 如果 pop 到空了就停。回傳總共 pop 掉幾個元素
int popUntil(vector<int>& st, int target) {
    // TODO: 實作
    return 0;
}

// ===== Task B：size_t 倒序迴圈陷阱 =====

// 從後面往前找，回傳 target 最後一次出現的 index；找不到回傳 -1
int lastIndexOf(const vector<int>& v, int target) {
    // TODO: 實作
    return 0;
}

// 回傳有幾個 i 滿足 v[i] == v[i + 1]
int countAdjacentEqual(const vector<int>& v) {
    // TODO: 實作
    return 0;
}

// ===== Task C：切片與拼接 =====

// 回傳 v[i..j)（左閉右開）的複製，0 <= i <= j <= v.size()
vector<int> slice(const vector<int>& v, int i, int j) {
    // TODO: 實作
    return {};
}

// 回傳把 v 向右旋轉 k 步的結果（k >= 0，可能大於 v.size()）
vector<int> rotateRight(const vector<int>& v, int k) {
    // TODO: 實作
    return {};
}

// ===== Task D：2D vector =====

// 回傳 rows × cols、每格都是 val 的 2D vector
vector<vector<int>> makeGrid(int rows, int cols, int val) {
    // TODO: 實作
    return {};
}

// 回傳矩陣的轉置（m 可能不是正方形，也可能是空的）
vector<vector<int>> transpose(const vector<vector<int>>& m) {
    // TODO: 實作
    return {};
}

// ===== Task E：前綴和區間查詢 =====

// 回傳長度 n + 1 的前綴和：pre[0] = 0，pre[i + 1] = pre[i] + nums[i]
vector<long long> buildPrefix(const vector<int>& nums) {
    // TODO: 實作
    return {};
}

// 用前綴和回傳 nums[l] + ... + nums[r]（閉區間）
long long rangeSum(const vector<long long>& pre, int l, int r) {
    // TODO: 實作
    return 0;
}

// 每個 query 是 {l, r}，回傳每個閉區間 [l, r] 的總和
vector<long long> answerQueries(const vector<int>& nums, const vector<pair<int, int>>& queries) {
    // TODO: 實作
    return {};
}

int main() {
    lc::section("Task A：vector 基本操作");
    CHECK_EQ(keepEvens({1, 2, -3, -4, 0, 7}), {2, -4, 0});  // -3 % 2 == -1，不是 1
    CHECK_EQ(withIndex({7, 8, 9}), {{0, 7}, {1, 8}, {2, 9}});
    {
        vector<int> st = {1, 2, 3, 4, 5};
        CHECK_EQ(popUntil(st, 3), 2);
        CHECK_EQ(st, {1, 2, 3});
    }
    {
        vector<int> st = {1, 2};
        CHECK_EQ(popUntil(st, 9), 2);  // 找不到 target：全部 pop 完，不能對空 vector 呼叫 back()
        CHECK(st.empty());
    }

    lc::section("Task B：size_t 倒序迴圈陷阱");
    CHECK_EQ(lastIndexOf({1, 2, 3, 2, 1}, 2), 3);
    CHECK_EQ(lastIndexOf({5}, 5), 0);
    CHECK_EQ(lastIndexOf({1, 2, 3}, 9), -1);
    CHECK_EQ(lastIndexOf({}, 1), -1);  // 空 vector：v.size() - 1 會變成超大的數
    CHECK_EQ(countAdjacentEqual({1, 1, 2, 2, 2, 3}), 3);
    CHECK_EQ(countAdjacentEqual({}), 0);

    lc::section("Task C：切片與拼接");
    CHECK_EQ(slice({10, 20, 30, 40, 50}, 1, 4), {20, 30, 40});
    CHECK_EQ(slice({10, 20, 30}, 0, 3), {10, 20, 30});
    CHECK_EQ(slice({10, 20, 30}, 2, 2), {});
    CHECK_EQ(rotateRight({1, 2, 3, 4, 5, 6, 7}, 3), {5, 6, 7, 1, 2, 3, 4});
    CHECK_EQ(rotateRight({1, 2}, 5), {2, 1});  // k 比長度大
    CHECK_EQ(rotateRight({}, 3), {});          // 空 vector：小心 k % 0

    lc::section("Task D：2D vector");
    CHECK_EQ(makeGrid(2, 3, 7), {{7, 7, 7}, {7, 7, 7}});
    CHECK_EQ(makeGrid(0, 5, 1), {});
    CHECK_EQ(transpose({{1, 2, 3}, {4, 5, 6}}), {{1, 4}, {2, 5}, {3, 6}});
    CHECK_EQ(transpose({{1, 2}, {3, 4}}), {{1, 3}, {2, 4}});
    CHECK_EQ(transpose({{5}}), {{5}});
    CHECK_EQ(transpose({}), {});  // 空矩陣：不能讀 m[0]

    lc::section("Task E：前綴和區間查詢");
    CHECK_EQ(buildPrefix({1, 2, 3, 4}), {0, 1, 3, 6, 10});
    CHECK_EQ(buildPrefix({}), {0});
    {
        vector<long long> pre = {0, 1, 3, 6, 10};  // nums = {1, 2, 3, 4}
        CHECK_EQ(rangeSum(pre, 1, 2), 5);
        CHECK_EQ(rangeSum(pre, 0, 3), 10);
    }
    CHECK_EQ(answerQueries({-2, 0, 3, -5, 2, -1}, {{0, 2}, {2, 5}, {0, 5}}), {1, -1, -3});
    CHECK_EQ(answerQueries({2000000000, 2000000000, 2000000000}, {{0, 2}, {1, 1}}),
             {6000000000LL, 2000000000LL});

    return lc::summary();
}
