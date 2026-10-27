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
    int l = 0;
    int r = (int)s.size() - 1;

    while (l < r) {
        if (!isalnum((unsigned char)s[l])) {
            l++;
            continue;
        }

        if (!isalnum((unsigned char)s[r])) {
            r--;
            continue;
        }
        if (tolower((unsigned char)s[l]) != tolower((unsigned char)s[r])) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

// ===== Task B：字元計數 int cnt[26] =====
// s 只有小寫英文字母。回傳第一個「只出現一次」的字元的 index；沒有就回傳 -1
int firstUniqChar(const string& s) {
    int cnt[26] = {};

    for (char c : s) {
        cnt[c - 'a']++;
    }
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (cnt[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}

// 兩個字串都只有小寫英文字母。magazine 裡的每個字母只能用一次，
// 能不能拼出 note？
bool canConstruct(const string& note, const string& magazine) {
    int cnt[26] = {};
    for (char c : magazine) {
        cnt[c - 'a']++;
    }

    for (char c : note) {
        cnt[c - 'a']--;

        if (cnt[c - 'a'] < 0) {
            return false;
        }
    }
    return true;
}

// ===== Task C：substr 切片 =====

// 把 s 每 k 個字元切成一段（最後一段可以不足 k 個），k >= 1
vector<string> chunk(const string& s, int k) {
    vector<string> result;
    int n = s.size();
    for (int i = 0; i < n; i += k) {
        result.push_back(s.substr(i, k));
    }
    return result;
}

// 回傳所有字串的最長共同前綴；strs 為空時回傳 ""
string longestCommonPrefix(const vector<string>& strs) {
    if (strs.empty()) {  // 沒有任何字串
        return "";
    }
    const string& first = strs[0];  // 拿第一個字串當基準
    int len = first.size();
    int m = strs.size();
    for (int i = 0; i < len; i++) {    // 外層：第 i 個字元（欄）
        for (int j = 1; j < m; j++) {  // 內層：其他每一個字串（列）
            if (i >= (int)strs[j].size() || strs[j][i] != first[i]) {
                return first.substr(0, i);  // 這一欄對不上 → 前 i 個就是答案
            }
        }
    }
    return first;
}

// ===== Task D：反轉單字順序（istringstream）=====

// 把 s 裡的單字順序反轉，單字之間只留一個空白，頭尾不留空白
string reverseWords(const string& s) {
    // istringstream 是一個在 leetcode 常用到的觀念嗎 ？
    istringstream iss(s);
    string w;
    vector<string> list = {};
    string result = "";
    while (iss >> w) {
        list.push_back(w);
    }

    int n = list.size();

    for (int i = n - 1; i >= 0; i--) {
        result += list[i];
        result += ' ';
    }

    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}

// ===== Task E：字串數字相加 =====

// a、b 是 int 範圍內的整數字串（可能有負號），用 stoi / to_string 回傳相加結果
string addSmall(const string& a, const string& b) {
    return to_string(stoi(a) + stoi(b));
}

// a、b 是非負整數字串（可能非常長，超過 long long），逐位相加回傳結果
string addStrings(const string& a, const string& b) {
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;
    string result;
    while (i >= 0 || j >= 0 || carry > 0) {
        int x = (i >= 0) ? a[i] - '0' : 0;
        int y = (j >= 0) ? b[j] - '0' : 0;
        int sum = x + y + carry;
        result.push_back('0' + sum % 10);
        carry = sum / 10;
        i--;
        j--;
    }

    reverse(result.begin(), result.end());

    return result;
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
