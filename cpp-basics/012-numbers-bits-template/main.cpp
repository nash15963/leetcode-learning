// 012 · 數字範圍、取模、位元運算與函式模板（INT_MAX / MOD / bitmask / template）
// 執行：make run Q=012
// 題目說明見 question.md

#include <climits>  // INT_MAX, INT_MIN, LLONG_MAX, LLONG_MIN
#include <string>
#include <utility>  // pair
#include <vector>

#include "lc/test.hpp"

using namespace std;

const int MOD = 1e9 + 7;  // 1000000007，LeetCode 最常見的模數

// ===== Task A：整數範圍與安全中點 =====

// 二分搜尋的中點：保證 0 <= l <= r <= INT_MAX，回傳 (l + r) / 2（無條件捨去），但不能讓 l + r 溢位
int safeMid(int l, int r) {
    // TODO: 實作
    return 0;
}

// 回傳 a * b 的正確結果（可能超過 int 範圍）
long long multiplyLL(int a, int b) {
    // TODO: 實作
    return 0;
}

// 把 x 夾到 int 範圍內：小於 INT_MIN 回傳 INT_MIN，大於 INT_MAX 回傳 INT_MAX，否則原樣回傳
int clampToInt(long long x) {
    // TODO: 實作
    return 0;
}

// ===== Task B：位元操作 =====
// 第 k 個 bit：最右邊（最低位）是第 0 個。本題保證 0 <= k <= 30

// x 的第 k 個 bit 是不是 1
bool testBit(int x, int k) {
    // TODO: 實作
    return false;
}

// 把 x 的第 k 個 bit 設成 1，回傳結果
int setBit(int x, int k) {
    // TODO: 實作
    return 0;
}

// 把 x 的第 k 個 bit 設成 0，回傳結果
int clearBit(int x, int k) {
    // TODO: 實作
    return 0;
}

// n 是不是 2 的冪次（1, 2, 4, 8, ...）；n <= 0 一律 false
bool isPowerOfTwo(int n) {
    // TODO: 實作
    return false;
}

// x 和 y 的二進位表示有幾個 bit 不同（請用 __builtin_popcount）
int hammingDistance(int x, int y) {
    // TODO: 實作
    return 0;
}

// ===== Task C：函式模板 =====

// 回傳 v 中最大的元素（保證 v 不是空的）
template <typename T>
T myMax(const vector<T>& v) {
    // TODO: 實作
    return T{};
}

// 回傳所有元素用 + 加起來的結果；空陣列回傳 T{}（int → 0、string → ""）
template <typename T>
T sumAll(const vector<T>& v) {
    // TODO: 實作
    return T{};
}

// 回傳 {最小值, 最大值}（保證 v 不是空的）
template <typename T>
pair<T, T> minMax(const vector<T>& v) {
    // TODO: 實作
    return {T{}, T{}};
}

// ===== Task D：取模運算與快速冪 =====

// 所有元素的總和 % MOD（0 <= a[i] <= 1e9，長度可能到 1e5）
int sumMod(const vector<int>& a) {
    // TODO: 實作
    return 0;
}

// (a - b) mod MOD，結果必須落在 [0, MOD)（0 <= a, b < MOD）
int subMod(int a, int b) {
    // TODO: 實作
    return 0;
}

// 所有元素的乘積 % MOD（0 <= a[i] <= 1e9）；空陣列回傳 1
int productMod(const vector<int>& a) {
    // TODO: 實作
    return 0;
}

// base^exp % mod，必須是 O(log exp) 的快速冪（0 <= base <= 1e18、0 <= exp <= 1e18、1 <= mod <= MOD）
long long powMod(long long base, long long exp, long long mod) {
    // TODO: 實作
    return 0;
}

// ===== Task E：用 bitmask 列舉子集合 =====

// 回傳 nums 的所有子集合：mask 從 0 到 2^n - 1，mask 的第 i 個 bit 是 1 就選 nums[i]
// 順序：依 mask 由小到大；每個子集合內依 i 由小到大（n <= 20）
vector<vector<int>> subsets(const vector<int>& nums) {
    // TODO: 實作
    return {};
}

// 有幾個子集合（包含空集合）的總和剛好等於 target（n <= 20）
int countSubsetsWithSum(const vector<int>& nums, int target) {
    // TODO: 實作
    return 0;
}

int main() {
    lc::section("Task A：整數範圍與安全中點");
    CHECK_EQ(safeMid(0, 10), 5);
    CHECK_EQ(safeMid(7, 8), 7);
    CHECK_EQ(safeMid(2000000000, 2147483647), 2073741823);  // l + r 會超過 INT_MAX
    CHECK_EQ(safeMid(INT_MAX - 1, INT_MAX), INT_MAX - 1);
    CHECK_EQ(multiplyLL(100000, 100000), 10000000000LL);
    CHECK_EQ(multiplyLL(INT_MAX, 2), 4294967294LL);
    CHECK_EQ(multiplyLL(INT_MIN, -1), 2147483648LL);
    CHECK_EQ(multiplyLL(-3, 7), -21);
    CHECK_EQ(clampToInt(42), 42);
    CHECK_EQ(clampToInt(5000000000LL), INT_MAX);
    CHECK_EQ(clampToInt(-5000000000LL), INT_MIN);
    CHECK_EQ(clampToInt(LLONG_MAX), INT_MAX);
    CHECK_EQ(clampToInt(LLONG_MIN), INT_MIN);

    lc::section("Task B：位元操作");
    CHECK(testBit(5, 0));  // 5 = 101
    CHECK(!testBit(5, 1));
    CHECK(testBit(5, 2));
    CHECK(testBit(1 << 30, 30));
    CHECK_EQ(setBit(5, 1), 7);  // 101 → 111
    CHECK_EQ(setBit(5, 0), 5);  // 已經是 1 → 不變
    CHECK_EQ(setBit(0, 30), 1073741824);
    CHECK_EQ(clearBit(7, 1), 5);  // 111 → 101
    CHECK_EQ(clearBit(5, 1), 5);  // 已經是 0 → 不變
    CHECK_EQ(clearBit(-1, 0), -2);
    CHECK(isPowerOfTwo(1));
    CHECK(isPowerOfTwo(16));
    CHECK(isPowerOfTwo(1 << 30));
    CHECK(!isPowerOfTwo(6));
    CHECK(!isPowerOfTwo(0));
    CHECK(!isPowerOfTwo(-8));
    CHECK(!isPowerOfTwo(INT_MIN));
    CHECK_EQ(hammingDistance(1, 4), 2);  // 001 vs 100
    CHECK_EQ(hammingDistance(7, 7), 0);
    CHECK_EQ(hammingDistance(0, INT_MAX), 31);
    CHECK_EQ(hammingDistance(-1, 0), 32);

    lc::section("Task C：函式模板");
    CHECK_EQ(myMax(vector<int>{3, 9, 2}), 9);
    CHECK_EQ(myMax(vector<int>{-5, -2, -9}), -2);  // 全部是負數
    CHECK_EQ(myMax<int>({7}), 7);                  // 也可以明確寫出 <int>
    CHECK_EQ(myMax(vector<double>{1.5, -2.0, 0.25}), 1.5);
    CHECK_EQ(myMax(vector<string>{"pear", "apple", "zoo", "kiwi"}), "zoo");
    CHECK_EQ(sumAll(vector<int>{1, 2, 3}), 6);
    CHECK_EQ(sumAll(vector<long long>{3000000000LL, 3000000000LL}), 6000000000LL);
    CHECK_EQ(sumAll(vector<string>{"ab", "c", "de"}), "abcde");
    CHECK_EQ(sumAll<double>({0.5, 0.25}), 0.75);
    CHECK_EQ(sumAll(vector<int>{}), 0);
    CHECK_EQ(minMax(vector<int>{3, -1, 7, 2}), {-1, 7});
    CHECK_EQ(minMax(vector<char>{'m', 'z', 'a'}), {'a', 'z'});
    CHECK_EQ(minMax(vector<string>{"b", "a", "c"}), {"a", "c"});

    lc::section("Task D：取模運算與快速冪");
    CHECK_EQ(sumMod({1, 2, 3}), 6);
    CHECK_EQ(sumMod({1000000000, 1000000000, 1000000000}), 999999986);
    CHECK_EQ(sumMod(vector<int>(100000, 1000000000)), 999300007);
    CHECK_EQ(subMod(5, 3), 2);
    CHECK_EQ(subMod(3, 5), 1000000005);  // 不能是負數
    CHECK_EQ(subMod(0, MOD - 1), 1);
    CHECK_EQ(productMod({2, 3, 4}), 24);
    CHECK_EQ(productMod({1000000000, 1000000000}), 49);
    CHECK_EQ(productMod({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}),
             146326063);
    CHECK_EQ(productMod({}), 1);
    CHECK_EQ(powMod(2, 10, MOD), 1024);
    CHECK_EQ(powMod(5, 3, 7), 6);
    CHECK_EQ(powMod(7, 0, MOD), 1);
    CHECK_EQ(powMod(2, 30, MOD), 73741817);
    CHECK_EQ(powMod(1000000000000LL, 2, MOD), 49000000);   // base 比 mod 大很多
    CHECK_EQ(powMod(3, MOD - 2, MOD), 333333336);          // 3 的模反元素
    CHECK_EQ(powMod(7, 1000000000000000000LL, MOD), 259616729);  // exp = 1e18：O(exp) 的迴圈永遠跑不完

    lc::section("Task E：用 bitmask 列舉子集合");
    CHECK_EQ(subsets({1, 2, 3}), {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}});
    CHECK_EQ(subsets({5}), {{}, {5}});
    CHECK_EQ(subsets({}).size(), 1);  // 只有空集合
    CHECK_EQ(subsets(vector<int>(10, 0)).size(), 1024);
    CHECK_EQ(countSubsetsWithSum({1, 2, 3, 4}, 5), 2);  // {1,4}、{2,3}
    CHECK_EQ(countSubsetsWithSum({3, 1, 4, 1, 5}, 5), 4);
    CHECK_EQ(countSubsetsWithSum({-1, 1, 2}, 1), 2);
    CHECK_EQ(countSubsetsWithSum({1, 2, 3}, 0), 1);  // 空集合
    {
        vector<int> oneToTwenty;
        for (int i = 1; i <= 20; i++) oneToTwenty.push_back(i);
        CHECK_EQ(countSubsetsWithSum(oneToTwenty, 105), 15272);  // 2^20 個子集合
    }

    return lc::summary();
}
