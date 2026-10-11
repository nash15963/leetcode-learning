# 013 · Two Sum（LeetCode #1）

| 項目 | 內容 |
|---|---|
| LeetCode | [#1 Two Sum](https://leetcode.com/problems/two-sum/) ・ [力扣](https://leetcode.cn/problems/two-sum/) |
| 難度 | Easy |
| 主題 | Array, Hash Table |
| 代码随想录 | [1. 两数之和](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0001.两数之和.md)（哈希表章節） |
| 練到的 C++ | `unordered_map<int, int>`、`find` vs `operator[]`、回傳 `{i, j}` |
| 對應前置練習 | 006 hash-containers |

> 執行：`make run Q=013`。卡住時可以用 `/hint 013`，完成後用 `/check 013`。

## 題目摘要
給一個整數陣列 `nums` 和目標值 `target`，找出**兩個不同位置**的元素，使它們相加等於 `target`，回傳這兩個 index（順序不限）。題目保證恰好有一組解，同一個元素不能用兩次。

## 範例
| nums | target | 輸出 |
|---|---|---|
| `[2,7,11,15]` | 9 | `[0,1]` |
| `[3,2,4]` | 6 | `[1,2]` |
| `[3,3]` | 6 | `[0,1]` |

## 限制
- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i], target <= 10^9`
- 恰好一組解

## 練習重點
- 先想暴力解 O(n²)，再想怎麼用 hash table 降到 O(n)
- 用 `find` 查詢而不是 `operator[]`（後者查不到時會自動插入）
- 想想看：怎麼確保不會用到同一個元素兩次？

## 我的筆記
- 思路：
- 時間 / 空間複雜度：
- 卡住的地方：
