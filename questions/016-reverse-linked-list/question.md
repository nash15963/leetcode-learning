# 016 · Reverse Linked List（LeetCode #206）

| 項目 | 內容 |
|---|---|
| LeetCode | [#206 Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) ・ [力扣](https://leetcode.cn/problems/reverse-linked-list/) |
| 難度 | Easy |
| 主題 | Linked List, Recursion |
| 代码随想录 | [206. 翻转链表](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0206.翻转链表.md)（链表章節） |
| 練到的 C++ | `ListNode*` 指標操作、`nullptr`、遞迴 |
| 對應前置練習 | 010 pointer-linkedlist |

> 執行：`make run Q=016`。卡住時可以用 `/hint 016`，完成後用 `/check 016`。

## 題目摘要
給一個單向鏈結串列的 `head`，把整條串列反轉，回傳新的 head。

```
輸入：1 -> 2 -> 3 -> 4 -> 5 -> nullptr
輸出：5 -> 4 -> 3 -> 2 -> 1 -> nullptr
```

## 範例
| head | 輸出 |
|---|---|
| `[1,2,3,4,5]` | `[5,4,3,2,1]` |
| `[1,2]` | `[2,1]` |
| `[]` | `[]` |

## 限制
- 節點數 `[0, 5000]`
- `-5000 <= Node.val <= 5000`

## 任務
- **Task A**：迭代版 `reverseList`（O(n) 時間、O(1) 空間）
- **Task B**：遞迴版 `reverseListRecursive`（Follow-up）

## 練習重點
- 迭代版需要幾個指標？畫圖追蹤每一步 `next` 的變化
- 改 `cur->next` **之前**要先存好下一個節點，不然會斷鏈
- 遞迴版：base case 是什麼？回傳的新 head 怎麼一路往上傳？
- `ListNode` 的定義在 `include/lc/structures.hpp`，和 LeetCode 一樣，不用自己寫

## 我的筆記
- 思路：
- 時間 / 空間複雜度：
- 卡住的地方：
