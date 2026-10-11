// 007 · 堆疊、佇列、雙端佇列、優先佇列（stack / queue / deque / priority_queue）
// 執行：make run Q=007
// 題目說明見 question.md

#include <algorithm>   // reverse
#include <deque>
#include <functional>  // greater
#include <queue>       // queue, priority_queue
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>     // pair
#include <vector>

#include "lc/test.hpp"

using namespace std;

// ===== Task A：stack 基本 — 退格字串 =====

// '#' 代表退格：刪掉前一個還沒被刪的字元（沒有字元可刪就忽略）。回傳最後的字串
string applyBackspace(const string& s) {
    // TODO: 實作
    return "";
}

// ===== Task B：stack — 後序運算式計算機（RPN）=====

// tokens 是合法的後序運算式，運算子只有 + - * /，除法向 0 取整
int evalRPN(const vector<string>& tokens) {
    // TODO: 實作
    return 0;
}

// ===== Task C：queue 模擬 =====

// 1..n 號依序圍成一圈，從目前的人開始數 1、2、…、k，數到 k 的人出局，
// 下一個人重新從 1 開始數。回傳最後留下的人的編號
int hotPotato(int n, int k) {
    // TODO: 實作
    return 0;
}

// times 是遞增的請求時間。對每個時間 t，回傳落在 [t - window, t] 內的請求數（包含自己）
vector<int> recentCounts(const vector<int>& times, int window) {
    // TODO: 實作
    return {};
}

// ===== Task D：deque — 滑動視窗最大值 =====

// 回傳每個長度為 k 的視窗中的最大值（1 <= k <= nums.size()）
vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    // TODO: 實作
    return {};
}

// ===== Task E：priority_queue — 最大堆積、最小堆積、自訂比較 =====

// 每回合取出最重的兩顆石頭 x <= y 互撞：相等就都消失，否則剩下 y - x 放回去。
// 回傳最後剩下的石頭重量；沒有石頭剩下回傳 0
int lastStoneWeight(const vector<int>& stones) {
    // TODO: 實作
    return -1;
}

// 回傳第 k 大的元素（重複的值也算，1 <= k <= nums.size()）
int kthLargest(const vector<int>& nums, int k) {
    // TODO: 實作
    return 0;
}

// 回傳出現頻率最高的 k 個值：頻率高的在前；頻率相同時，數值小的在前
vector<int> topKFrequent(const vector<int>& nums, int k) {
    // TODO: 實作
    return {};
}

int main() {
    lc::section("Task A：stack 基本 — 退格字串");
    CHECK_EQ(applyBackspace("ab#c"), "ac");
    CHECK_EQ(applyBackspace("abc##"), "a");
    CHECK_EQ(applyBackspace("a##b"), "b");
    CHECK_EQ(applyBackspace("hello"), "hello");
    CHECK_EQ(applyBackspace("###"), "");

    lc::section("Task B：stack — 後序運算式計算機（RPN）");
    CHECK_EQ(evalRPN({"2", "1", "+", "3", "*"}), 9);
    CHECK_EQ(evalRPN({"4", "13", "5", "/", "+"}), 6);
    CHECK_EQ(evalRPN({"5", "3", "-"}), 2);
    CHECK_EQ(evalRPN({"7", "-2", "/"}), -3);
    CHECK_EQ(evalRPN({"42"}), 42);
    CHECK_EQ(evalRPN({"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}), 22);

    lc::section("Task C：queue 模擬");
    CHECK_EQ(hotPotato(5, 2), 3);
    CHECK_EQ(hotPotato(7, 3), 4);
    CHECK_EQ(hotPotato(6, 1), 6);
    CHECK_EQ(hotPotato(1, 3), 1);
    CHECK_EQ(recentCounts({1, 100, 3001, 3002}, 3000), {1, 2, 3, 3});
    CHECK_EQ(recentCounts({1, 2, 10, 11, 12}, 2), {1, 2, 1, 2, 3});

    lc::section("Task D：deque — 滑動視窗最大值");
    CHECK_EQ(maxSlidingWindow({1, 3, -1, -3, 5, 3, 6, 7}, 3), {3, 3, 5, 5, 6, 7});
    CHECK_EQ(maxSlidingWindow({1, 3, -1, -3, 5, 3, 6, 7}, 1), {1, 3, -1, -3, 5, 3, 6, 7});
    CHECK_EQ(maxSlidingWindow({4, 2, 12, 3}, 4), {12});
    CHECK_EQ(maxSlidingWindow({9, 8, 7, 6, 5}, 2), {9, 8, 7, 6});
    CHECK_EQ(maxSlidingWindow({2, 2, 2, 2}, 2), {2, 2, 2});

    lc::section("Task E：priority_queue — 最大堆積、最小堆積、自訂比較");
    CHECK_EQ(lastStoneWeight({2, 7, 4, 1, 8, 1}), 1);
    CHECK_EQ(lastStoneWeight({2, 2}), 0);
    CHECK_EQ(kthLargest({3, 2, 1, 5, 6, 4}, 2), 5);
    CHECK_EQ(kthLargest({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4), 4);
    CHECK_EQ(topKFrequent({1, 1, 1, 2, 2, 3}, 2), {1, 2});
    CHECK_EQ(topKFrequent({4, 4, 5, 5, 6, 6, 6, 7}, 3), {6, 4, 5});

    return lc::summary();
}
