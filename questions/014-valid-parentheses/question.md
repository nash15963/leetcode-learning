# 014 · Valid Parentheses（LeetCode #20）

| 項目 | 內容 |
|---|---|
| LeetCode | [#20 Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) ・ [力扣](https://leetcode.cn/problems/valid-parentheses/) |
| 難度 | Easy |
| 主題 | String, Stack |
| 代码随想录 | [20. 有效的括号](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0020.有效的括号.md)（栈与队列章節） |
| 練到的 C++ | `stack<char>`、`push` / `top` / `pop` / `empty`、`for (char c : s)` |
| 對應前置練習 | 003 string-char、007 stack-queue-heap |

> 執行：`make run Q=014`。卡住時可以用 `/hint 014`，完成後用 `/check 014`。

## 題目摘要
字串 `s` 只包含 `()[]{}` 六種字元，判斷括號是否有效：
1. 左括號必須由**相同類型**的右括號關閉
2. 左括號必須以**正確順序**關閉
3. 每個右括號都要有對應的左括號

## 範例
| s | 輸出 |
|---|---|
| `"()"` | true |
| `"()[]{}"` | true |
| `"(]"` | false |
| `"([])"` | true |

## 限制
- `1 <= s.length <= 10^4`
- `s` 只包含 `()[]{}`

## 練習重點
- 為什麼這題適合用 stack（後進先出）？
- 三種失敗情況都要處理：類型不符、右括號多出來（stack 已空）、左括號多出來（結束時 stack 不空）
- ⚠️ 對空的 `stack` 呼叫 `top()` / `pop()` 是 undefined behavior，ASan 會抓到

## 我的筆記
- 思路：
- 時間 / 空間複雜度：
- 卡住的地方：
