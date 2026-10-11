// 001 · 輸入輸出與流程控制
// 執行：make run Q=001
// 題目說明見 question.md

#include <iomanip>   // setw
#include <iostream>  // cout, istream
#include <sstream>   // istringstream（測試用：把字串當成輸入）
#include <string>
#include <vector>

#include "lc/test.hpp"

using namespace std;

// ===== Task A：從 1 印到 10（for / while）=====

// 用 for 迴圈印出 "1 2 3 4 5 6 7 8 9 10"，數字之間一個空白、最後換行
void print1To10() {
    // TODO: 實作
}

// 用 while 迴圈從 n 倒數印到 1，例如 n = 3 印出 "3 2 1" 再換行
// n <= 0 時只印一個換行
void printCountdown(int n) {
    // TODO: 實作
}

// ===== Task B：1 加到 n 與 int 溢位 =====

// 用迴圈計算 1 + 2 + ... + n（n <= 0 回傳 0）
long long sumLoop(int n) {
    // TODO: 實作
    return 0;
}

// 用公式 n * (n + 1) / 2 計算（n <= 0 回傳 0）
long long sumFormula(int n) {
    // TODO: 實作
    return 0;
}

// ===== Task C：FizzBuzz =====

// 回傳 1..n 的 FizzBuzz 結果：3 的倍數 "Fizz"、5 的倍數 "Buzz"、
// 15 的倍數 "FizzBuzz"、其他就是數字本身（轉成字串）
vector<string> fizzBuzz(int n) {
    // TODO: 實作
    return {};
}

// ===== Task D：乘法表（setw 對齊）=====

// 印出 n × n 乘法表：第 i 行第 j 個數字是 i * j，每個數字用 setw(4) 靠右對齊，
// 每行結尾換行。n <= 0 時什麼都不印
void printTable(int n) {
    // TODO: 實作
}

// ===== Task E：讀到 EOF（ACM 模式暖身）=====

// 從 in 一直讀整數直到讀不到為止，回傳總和
long long sumAll(istream& in) {
    // TODO: 實作
    return 0;
}

// 輸入格式：第一行 T（測資筆數），接下來 T 行，每行開頭是 k，後面接 k 個整數
// 對每筆測資，印出那 k 個整數的總和，一筆一行
void solveCases(istream& in) {
    // TODO: 實作
}

int main() {
    lc::section("Task A：從 1 印到 10（for / while）");
    CHECK_EQ(lc::capture([] { print1To10(); }), "1 2 3 4 5 6 7 8 9 10\n");
    CHECK_EQ(lc::capture([] { printCountdown(5); }), "5 4 3 2 1\n");
    CHECK_EQ(lc::capture([] { printCountdown(1); }), "1\n");
    CHECK_EQ(lc::capture([] { printCountdown(0); }), "\n");

    lc::section("Task B：1 加到 n 與 int 溢位");
    CHECK_EQ(sumLoop(10), 55);
    CHECK_EQ(sumLoop(0), 0);
    CHECK_EQ(sumLoop(100000), 5000050000LL);  // 超過 INT_MAX（約 21 億）
    CHECK_EQ(sumFormula(10), 55);
    CHECK_EQ(sumFormula(100000), 5000050000LL);
    CHECK_EQ(sumFormula(2000000000), 2000000001000000000LL);

    lc::section("Task C：FizzBuzz");
    CHECK_EQ(fizzBuzz(1), {"1"});
    CHECK_EQ(fizzBuzz(5), {"1", "2", "Fizz", "4", "Buzz"});
    CHECK_EQ(fizzBuzz(15), {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11",
                            "Fizz", "13", "14", "FizzBuzz"});
    CHECK_EQ(fizzBuzz(0), {});

    lc::section("Task D：乘法表（setw 對齊）");
    CHECK_EQ(lc::capture([] { printTable(1); }), "   1\n");
    CHECK_EQ(lc::capture([] { printTable(3); }), "   1   2   3\n   2   4   6\n   3   6   9\n");
    CHECK_EQ(lc::capture([] { printTable(0); }), "");
    {
        string t10 = lc::capture([] { printTable(10); });
        CHECK_EQ(t10.size(), 410);  // 10 行 ×（10 格 × 4 字元 + 換行）
        CHECK(t10.find("  10  20  30  40  50  60  70  80  90 100\n") != string::npos);
    }

    lc::section("Task E：讀到 EOF（ACM 模式暖身）");
    {
        istringstream in("1 2 3");
        CHECK_EQ(sumAll(in), 6);
    }
    {
        istringstream in("10\n-20\n  30\n");
        CHECK_EQ(sumAll(in), 20);
    }
    {
        istringstream in("");
        CHECK_EQ(sumAll(in), 0);
    }
    {
        istringstream in("2000000000 2000000000 2000000000");
        CHECK_EQ(sumAll(in), 6000000000LL);
    }
    {
        istringstream in("2\n3 1 2 3\n2 10 20\n");
        CHECK_EQ(lc::capture([&] { solveCases(in); }), "6\n30\n");
    }
    {
        istringstream in("1\n2 2000000000 2000000000\n");
        CHECK_EQ(lc::capture([&] { solveCases(in); }), "4000000000\n");
    }

    return lc::summary();
}
