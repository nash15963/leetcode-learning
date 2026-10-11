// 迷你測試框架
//
// 用法（寫在 main() 裡）：
//   lc::section("Task A: 加總");
//   CHECK(isEven(4));                    // 條件為 true 就 PASS
//   CHECK_EQ(sumTo(10), 55);             // 實際值 == 期望值 就 PASS
//   CHECK_EQ(twoSum({2, 7}, 9), {0, 1}); // 期望值可以直接寫 {...}
//   std::string out = lc::capture([] { print1to10(); });  // 擷取 cout 輸出
//   return lc::summary();                // 全部通過回傳 0，否則回傳 1
#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace lc {

// ---------- 把值轉成字串（測試失敗時印出來）----------
// 先宣告所有版本，讓巢狀型別（例如 vector<pair<int,int>>）互相找得到
inline std::string to_str(const std::string& s);
inline std::string to_str(const char* s);
inline std::string to_str(char c);
inline std::string to_str(bool b);
template <typename A, typename B>
std::string to_str(const std::pair<A, B>& p);
template <typename T>
std::string to_str(const std::vector<T>& v);
template <typename T>
std::string to_str(const T& x);

inline std::string to_str(const std::string& s) { return "\"" + s + "\""; }
inline std::string to_str(const char* s) { return to_str(std::string(s)); }
inline std::string to_str(char c) {
    // '\0'、換行等看不到的字元改印數值，例如 (char)0
    if (c < 32 || c == 127) return "(char)" + std::to_string(static_cast<int>(c));
    return std::string("'") + c + "'";
}
inline std::string to_str(bool b) { return b ? "true" : "false"; }

template <typename A, typename B>
std::string to_str(const std::pair<A, B>& p) {
    return "(" + to_str(p.first) + ", " + to_str(p.second) + ")";
}

template <typename T>
std::string to_str(const std::vector<T>& v) {
    std::string s = "[";
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0) s += ", ";
        s += to_str(v[i]);
    }
    return s + "]";
}

template <typename T>
std::string to_str(const T& x) {
    std::ostringstream os;
    os << x;
    return os.str();
}

// ---------- 計數 ----------
inline int g_pass = 0;
inline int g_fail = 0;

inline void section(const std::string& title) { std::cout << "\n== " << title << " ==\n"; }

inline void report(bool ok, const std::string& expr, const char* file, int line) {
    if (ok) {
        g_pass++;
        std::cout << "  ✅ PASS  " << expr << "\n";
    } else {
        g_fail++;
        std::cout << "  ❌ FAIL  " << expr << "  (line " << line << ")\n";
    }
}

inline void check(bool ok, const char* expr, const char* file, int line) {
    report(ok, expr, file, line);
}

// 讓期望值的型別跟著實際值走，這樣 CHECK_EQ(v.size(), 3) 不會有 signed/unsigned 警告
template <typename T>
struct same_type {
    using type = T;
};

template <typename T>
void check_eq(const T& actual, const typename same_type<T>::type& expected, const char* expr,
              const char* file, int line) {
    bool ok = (actual == expected);
    report(ok, expr, file, line);
    if (!ok) {
        std::cout << "           expected: " << to_str(expected) << "\n";
        std::cout << "           actual:   " << to_str(actual) << "\n";
    }
}

// 擷取一段程式碼印到 std::cout 的內容
template <typename F>
std::string capture(F f) {
    std::ostringstream buf;
    std::streambuf* old = std::cout.rdbuf(buf.rdbuf());
    f();
    std::cout.rdbuf(old);
    return buf.str();
}

inline int summary() {
    int total = g_pass + g_fail;
    std::cout << "\n== 結果：" << g_pass << " / " << total << " 通過 ==\n";
    if (g_fail == 0) std::cout << "🎉 全部通過！\n";
    return g_fail == 0 ? 0 : 1;
}

}  // namespace lc

#define CHECK(cond) ::lc::check(static_cast<bool>(cond), #cond, __FILE__, __LINE__)
#define CHECK_EQ(actual, ...) \
    ::lc::check_eq((actual), __VA_ARGS__, #actual " == " #__VA_ARGS__, __FILE__, __LINE__)
