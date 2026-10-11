// 006 · 雜湊容器與有序容器（unordered_map / unordered_set / map / set）
// 執行：make run Q=006
// 題目說明見 question.md

#include <map>
#include <set>
#include <sstream>  // istringstream（拆單字用）
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>  // pair
#include <vector>

#include "lc/test.hpp"

using namespace std;

// ===== Task A：單字頻率 =====

// 回傳每個單字出現的次數（單字之間可能有多個空白）
unordered_map<string, int> wordFrequency(const string& text) {
    // TODO: 實作
    return {};
}

// 回傳出現最多次的單字；平手時回傳字典順序最小的；沒有單字回傳 ""
string mostFrequentWord(const string& text) {
    // TODO: 實作
    return "";
}

// ===== Task B：operator[] 自動插入陷阱 =====

// 把 words 裡每個字的次數累加進 freq
void addWords(unordered_map<string, int>& freq, const vector<string>& words) {
    // TODO: 實作
}

// 回傳 key 是否存在於 m。注意：呼叫後 m 不可以多出新的 key
bool hasKey(unordered_map<string, int>& m, const string& key) {
    // TODO: 實作
    return false;
}

// 回傳 key 對應的值；不存在就回傳 def
int getOrDefault(const unordered_map<string, int>& m, const string& key, int def) {
    // TODO: 實作
    return 0;
}

// ===== Task C：unordered_set 找重複 =====

// 由左往右掃，回傳第一個「第二次出現」的值；沒有重複回傳 -1
int firstDuplicate(const vector<int>& nums) {
    // TODO: 實作
    return 0;
}

// 去除重複，但保留每個值「第一次出現」的順序
vector<int> uniqueInOrder(const vector<int>& nums) {
    // TODO: 實作
    return {};
}

// ===== Task D：有序 map / set =====

// 統計次數，並依單字的字典順序回傳 (單字, 次數)
vector<pair<string, int>> sortedFrequency(const vector<string>& words) {
    // TODO: 實作
    return {};
}

// 回傳 s 中「>= x 的最小元素」；不存在回傳 -1
int ceilingOf(const set<int>& s, int x) {
    // TODO: 實作
    return 0;
}

// 回傳 s 中「<= x 的最大元素」；不存在回傳 -1
int floorOf(const set<int>& s, int x) {
    // TODO: 實作
    return 0;
}

// ===== Task E：邊走訪邊刪除 =====

// 刪除所有次數 < minCount 的單字
void removeRareWords(map<string, int>& freq, int minCount) {
    // TODO: 實作
}

// 刪除 s 中所有 k 的倍數
void removeMultiples(set<int>& s, int k) {
    // TODO: 實作
}

int main() {
    lc::section("Task A：單字頻率");
    {
        unordered_map<string, int> expected = {{"the", 2}, {"cat", 1}, {"sat", 1}};
        CHECK(wordFrequency("the cat sat the") == expected);
    }
    {
        unordered_map<string, int> expected = {{"a", 2}, {"b", 1}};
        CHECK(wordFrequency("  a   b a ") == expected);
    }
    CHECK_EQ(mostFrequentWord("b a b c a b"), "b");
    CHECK_EQ(mostFrequentWord("dog cat cat dog"), "cat");
    CHECK_EQ(mostFrequentWord("zebra"), "zebra");
    CHECK_EQ(mostFrequentWord(""), "");

    lc::section("Task B：operator[] 自動插入陷阱");
    {
        unordered_map<string, int> freq = {{"apple", 1}};
        addWords(freq, {"apple", "kiwi", "apple"});
        unordered_map<string, int> expected = {{"apple", 3}, {"kiwi", 1}};
        CHECK(freq == expected);
    }
    {
        unordered_map<string, int> m = {{"a", 1}, {"zero", 0}};
        CHECK(hasKey(m, "zero"));     // 值是 0，但 key 存在
        CHECK(!hasKey(m, "missing"));
        CHECK_EQ(m.size(), 2);        // 查詢不應該讓 m 變大
    }
    {
        const unordered_map<string, int> m = {{"x", 5}};
        CHECK_EQ(getOrDefault(m, "x", -1), 5);
        CHECK_EQ(getOrDefault(m, "y", -1), -1);
    }

    lc::section("Task C：unordered_set 找重複");
    CHECK_EQ(firstDuplicate({2, 1, 3, 5, 3, 2}), 3);
    CHECK_EQ(firstDuplicate({7, 7}), 7);
    CHECK_EQ(firstDuplicate({1, 2, 3}), -1);
    CHECK_EQ(uniqueInOrder({3, 1, 3, 2, 1}), {3, 1, 2});
    CHECK_EQ(uniqueInOrder({4, 4, 4, 4}), {4});
    CHECK_EQ(uniqueInOrder({}), {});

    lc::section("Task D：有序 map / set");
    CHECK_EQ(sortedFrequency({"pear", "apple", "pear", "fig"}),
             {{"apple", 1}, {"fig", 1}, {"pear", 2}});
    CHECK_EQ(ceilingOf({1, 4, 9}, 5), 9);
    CHECK_EQ(ceilingOf({1, 4, 9}, 4), 4);
    CHECK_EQ(ceilingOf({1, 4, 9}, 10), -1);
    CHECK_EQ(floorOf({1, 4, 9}, 5), 4);
    CHECK_EQ(floorOf({1, 4, 9}, 0), -1);

    lc::section("Task E：邊走訪邊刪除");
    {
        map<string, int> freq = {{"a", 1}, {"b", 3}, {"c", 2}, {"d", 5}};
        removeRareWords(freq, 3);
        CHECK_EQ((vector<pair<string, int>>(freq.begin(), freq.end())), {{"b", 3}, {"d", 5}});
    }
    {
        map<string, int> freq = {{"x", 1}, {"y", 1}};
        removeRareWords(freq, 2);
        CHECK(freq.empty());
    }
    {
        set<int> s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        removeMultiples(s, 3);
        CHECK_EQ(vector<int>(s.begin(), s.end()), {1, 2, 4, 5, 7, 8, 10});
    }
    {
        set<int> s = {3, 4, 9};
        removeMultiples(s, 3);
        CHECK_EQ(vector<int>(s.begin(), s.end()), {4});
    }
    {
        set<int> s = {2, 4, 6};
        removeMultiples(s, 2);
        CHECK(s.empty());
    }

    return lc::summary();
}
