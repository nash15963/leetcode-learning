// 003 · 字串與字元
// 執行：make run Q=003
// 題目說明見 question.md

#include <algorithm>  // reverse
#include <cctype>     // isalnum, isalpha, isdigit, tolower, toupper
#include <sstream>    // istringstream
#include <string>     // string, to_string, stoi
#include <vector>

#include "lc/test.hpp"

using namespace std;

// ===== Task A：迴文判斷（isalnum / tolower）=====

// 只看英文字母和數字、忽略大小寫，判斷 s 是不是迴文
bool isPalindrome(const string& s) {
    // TODO: 實作
    return false;
}

// ===== Task B：字元計數 int cnt[26] =====

// s 只有小寫英文字母。回傳第一個「只出現一次」的字元的 index；沒有就回傳 -1
int firstUniqChar(const string& s) {
    // TODO: 實作
    return 0;
}

// 兩個字串都只有小寫英文字母。magazine 裡的每個字母只能用一次，
// 能不能拼出 note？
bool canConstruct(const string& note, const string& magazine) {
    // TODO: 實作
    return false;
}

// ===== Task C：substr 切片 =====

// 把 s 每 k 個字元切成一段（最後一段可以不足 k 個），k >= 1
vector<string> chunk(const string& s, int k) {
    // TODO: 實作
    return {};
}

// 回傳所有字串的最長共同前綴；strs 為空時回傳 ""
string longestCommonPrefix(const vector<string>& strs) {
    // TODO: 實作
    return "";
}

// ===== Task D：反轉單字順序（istringstream）=====

// 把 s 裡的單字順序反轉，單字之間只留一個空白，頭尾不留空白
string reverseWords(const string& s) {
    // TODO: 實作
    return "";
}

// ===== Task E：字串數字相加 =====

// a、b 是 int 範圍內的整數字串（可能有負號），用 stoi / to_string 回傳相加結果
string addSmall(const string& a, const string& b) {
    // TODO: 實作
    return "";
}

// a、b 是非負整數字串（可能非常長，超過 long long），逐位相加回傳結果
string addStrings(const string& a, const string& b) {
    // TODO: 實作
    return "";
}

int main() {
    lc::section("Task A：迴文判斷（isalnum / tolower）");
    CHECK_EQ(isPalindrome("A man, a plan, a canal: Panama"), true);
    CHECK_EQ(isPalindrome("race a car"), false);
    CHECK_EQ(isPalindrome("No 'x' in Nixon"), true);
    CHECK_EQ(isPalindrome(""), true);
    CHECK_EQ(isPalindrome(" .,!"), true);  // 去掉符號後是空字串
    CHECK_EQ(isPalindrome("0P"), false);   // 數字也要算進去

    lc::section("Task B：字元計數 int cnt[26]");
    CHECK_EQ(firstUniqChar("loveleetcode"), 2);
    CHECK_EQ(firstUniqChar("dddccdbba"), 8);
    CHECK_EQ(firstUniqChar("aabb"), -1);
    CHECK_EQ(canConstruct("aa", "ab"), false);
    CHECK_EQ(canConstruct("aa", "aab"), true);
    CHECK_EQ(canConstruct("", "xyz"), true);

    lc::section("Task C：substr 切片");
    CHECK_EQ(chunk("abcdefg", 3), {"abc", "def", "g"});
    CHECK_EQ(chunk("abcdef", 2), {"ab", "cd", "ef"});
    CHECK_EQ(chunk("", 4), {});
    CHECK_EQ(longestCommonPrefix({"flower", "flow", "flight"}), "fl");
    CHECK_EQ(longestCommonPrefix({"interview", "inter", "internet"}), "inter");
    CHECK_EQ(longestCommonPrefix({"dog", "racecar", "car"}), "");

    lc::section("Task D：反轉單字順序（istringstream）");
    CHECK_EQ(reverseWords("the sky is blue"), "blue is sky the");
    CHECK_EQ(reverseWords("  hello world  "), "world hello");
    CHECK_EQ(reverseWords("a good   example"), "example good a");
    CHECK_EQ(reverseWords("single"), "single");
    CHECK_EQ(reverseWords("   "), "");

    lc::section("Task E：字串數字相加");
    CHECK_EQ(addSmall("12", "30"), "42");
    CHECK_EQ(addSmall("-5", "3"), "-2");
    CHECK_EQ(addStrings("456", "77"), "533");
    CHECK_EQ(addStrings("999", "1"), "1000");
    CHECK_EQ(addStrings("0", "0"), "0");
    CHECK_EQ(addStrings("99999999999999999999", "1"), "100000000000000000000");  // 超過 long long

    return lc::summary();
}
