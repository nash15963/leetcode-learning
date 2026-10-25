// 002 · 函式、參考與指標
// 執行：make run Q=002
// 題目說明見 question.md

#include <algorithm>
#include <string>
#include <utility>  // pair
#include <vector>

#include "lc/test.hpp"

using namespace std;

// ===== Task A：swap 兩種寫法 =====

// 用參考（reference）交換 a 和 b 的值
void swapByRef(int& a, int& b) {
    int x = 0;
    x = a;
    a = b;
    b = x;
}

// 用指標（pointer）交換 *a 和 *b 的值
void swapByPtr(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// ===== Task B：三種傳參方式 =====

// 唯讀：回傳 nums 中「大於 k」的元素個數
int countGreater(const vector<int>& nums, int k) {
    int size = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] > k) {
            size++;
        }
    }
    return size;
}

// 可修改：把 nums 每個元素都加上 delta（直接改呼叫端的 vector）
void addToAll(vector<int>& nums, int delta) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        nums[i] = nums[i] + delta;
    }
}

// 傳值（複製一份）：回傳「每個元素都加上 delta」的新 vector，呼叫端原本的不能變
vector<int> addedCopy(vector<int> nums, int delta) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        nums[i] = nums[i] + delta;
    }
    return nums;
}

// ===== Task C：回傳 pair + structured binding =====

// 回傳 {最小值, 最大值}（nums 至少有一個元素）
pair<int, int> minMax(const vector<int>& nums) {
    int lo = nums[0];
    int hi = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        lo = min(lo, nums[i]);
        hi = max(hi, nums[i]);
    }
    pair<int, int> x = {lo, hi};

    return x;
}

// 回傳 target 第一次與最後一次出現的 index；找不到回傳 {-1, -1}
pair<int, int> firstLast(const vector<int>& nums, int target) {
    pair<int, int> x = {-1, -1};

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] == target && x.first == -1) {
            x.first = i;
            x.second = i;
        } else if (nums[i] == target && x.first != -1) {
            x.second = i;
        }
    }

    return x;
}

// ===== Task D：overload 與預設引數 =====

// 三個同名函式（overload），各自回傳最大值
int maxOf(int a, int b) {
    return max(a, b);
}

int maxOf(int a, int b, int c) {
    return max({a, b, c});
}

// nums 至少有一個元素
int maxOf(const vector<int>& nums) {
    int x = nums[0];
    for (int i = 0; i < (int)nums.size(); i++) {
        x = max(x, nums[i]);
    }
    return x;
}

// 把 s 重複 times 次，中間用 sep 隔開；times 預設 2、sep 預設空字串
string repeatStr(const string& s, int times = 2, const string& sep = "") {
    string tmp = s;
    int timeTmp = times - 1;
    while (timeTmp > 0) {
        tmp += sep;
        tmp += s;
        timeTmp--;
    }

    if (times <= 0) {
        return "";
    } else {
        return tmp;
    }
}

// ===== Task E：指標走訪陣列與 nullptr =====

// 加總 [first, last) 範圍內的元素（last 指向最後一個元素的「下一格」）
int sumRange(const int* first, const int* last) {
    int sum = 0;
    for (const int* p = first; p != last; p++) {
        sum += *p;
    }
    return sum;
}

// 在 [first, last) 中找第一個等於 target 的元素，回傳指向它的指標；找不到回傳 nullptr
const int* findPtr(const int* first, const int* last, int target) {
    const int* ta = nullptr;
    for (const int* p = first; p != last; p++) {
        if (*p == target) {
            return p;
        }
    }
    return ta;
}

// p 不是 nullptr 就回傳 *p，否則回傳 fallback
int valueOr(const int* p, int fallback) {
    if (p != nullptr) {
        return *p;
    }
    return fallback;
}

int main() {
    lc::section("Task A：swap 兩種寫法");
    {
        int a = 1, b = 2;
        swapByRef(a, b);
        CHECK_EQ(a, 2);
        CHECK_EQ(b, 1);
    }
    {
        int a = -5, b = 42;
        swapByPtr(&a, &b);
        CHECK_EQ(a, 42);
        CHECK_EQ(b, -5);
    }
    {
        vector<int> v = {1, 2, 3};
        swapByRef(v[0], v[2]);  // 參考可以直接綁到 vector 的元素
        CHECK_EQ(v, {3, 2, 1});
        swapByPtr(&v[0], &v[1]);  // &v[i] 是元素的位址
        CHECK_EQ(v, {2, 3, 1});
    }

    lc::section("Task B：三種傳參方式");
    CHECK_EQ(countGreater({1, 5, 3, 7}, 3), 2);
    CHECK_EQ(countGreater({-1, -2, 0}, -3), 3);
    CHECK_EQ(countGreater({}, 0), 0);
    {
        vector<int> v = {1, 2, 3};
        addToAll(v, 10);
        CHECK_EQ(v, {11, 12, 13});
    }
    {
        vector<int> v = {1, 2, 3};
        vector<int> w = addedCopy(v, 5);
        CHECK_EQ(w, {6, 7, 8});
        CHECK_EQ(v, {1, 2, 3});  // 原本的 v 不能被改到
    }

    lc::section("Task C：回傳 pair + structured binding");
    {
        auto [lo, hi] = minMax({3, 1, 4, 1, 5, 9, 2, 6});
        CHECK_EQ(lo, 1);
        CHECK_EQ(hi, 9);
    }
    CHECK_EQ(minMax({-7}), {-7, -7});
    {
        auto [first, last] = firstLast({5, 7, 7, 8, 8, 10}, 8);
        CHECK_EQ(first, 3);
        CHECK_EQ(last, 4);
    }
    CHECK_EQ(firstLast({}, 3), {-1, -1});

    lc::section("Task D：overload 與預設引數");
    CHECK_EQ(maxOf(3, 7), 7);
    CHECK_EQ(maxOf(-4, -9, -2), -2);
    CHECK_EQ(maxOf({-5, -3, -8}), -3);  // 全是負數：最大值的初始值不能是 0
    CHECK_EQ(repeatStr("ab"), "abab");
    CHECK_EQ(repeatStr("ab", 3), "ababab");
    CHECK_EQ(repeatStr("ab", 3, "-"), "ab-ab-ab");

    lc::section("Task E：指標走訪陣列與 nullptr");
    int arr[] = {4, 8, 15, 16, 23, 42};
    CHECK_EQ(sumRange(arr, arr + 6), 108);
    CHECK_EQ(sumRange(arr + 1, arr + 3), 23);  // 只有 arr[1]、arr[2]
    CHECK_EQ(sumRange(arr, arr), 0);           // 空範圍
    CHECK(findPtr(arr, arr + 6, 16) == arr + 3);
    CHECK_EQ(valueOr(findPtr(arr, arr + 6, 23), -1), 23);
    CHECK_EQ(valueOr(findPtr(arr, arr + 6, 99), -1), -1);  // 找不到 → nullptr → fallback

    return lc::summary();
}
