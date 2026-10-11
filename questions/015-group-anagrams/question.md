# 015 · Group Anagrams（LeetCode #49）

| 項目 | 內容 |
|---|---|
| LeetCode | [#49 Group Anagrams](https://leetcode.com/problems/group-anagrams/) ・ [力扣](https://leetcode.cn/problems/group-anagrams/) |
| 難度 | Medium |
| 主題 | Array, Hash Table, String, Sorting |
| 代码随想录 | （未收錄；相關題：[242. 有效的字母异位词](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0242.有效的字母异位词.md)） |
| 練到的 C++ | `unordered_map<string, vector<string>>`、對 `string` 做 `sort`、structured binding 走訪 map |
| 對應前置練習 | 003 string-char、005 stl-algorithms、006 hash-containers |

> 執行：`make run Q=015`。卡住時可以用 `/hint 015`，完成後用 `/check 015`。

## 題目摘要
給一個字串陣列 `strs`，把**字母異位詞（anagram）**分到同一組。anagram 指的是用相同字母、相同次數重新排列而成的字串（例如 `eat` / `tea` / `ate`）。組的順序和組內順序都不限。

## 範例
| strs | 輸出（任意順序） |
|---|---|
| `["eat","tea","tan","ate","nat","bat"]` | `[["bat"],["nat","tan"],["ate","eat","tea"]]` |
| `[""]` | `[[""]]` |
| `["a"]` | `[["a"]]` |

## 限制
- `1 <= strs.length <= 10^4`
- `0 <= strs[i].length <= 100`
- 只包含小寫英文字母

## 練習重點
- 關鍵問題：怎麼替每個字串算出一個「同組就相同」的 **key**？
- 試著想出兩種不同的 key，並比較它們的時間複雜度
- 走訪 `unordered_map` 時用 `for (auto& [key, group] : m)`

## 我的筆記
- 思路：
- 時間 / 空間複雜度：
- 卡住的地方：
