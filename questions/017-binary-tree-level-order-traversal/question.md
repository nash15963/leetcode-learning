# 017 · Binary Tree Level Order Traversal（LeetCode #102）

| 項目 | 內容 |
|---|---|
| LeetCode | [#102 Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) ・ [力扣](https://leetcode.cn/problems/binary-tree-level-order-traversal/) |
| 難度 | Medium |
| 主題 | Tree, Breadth-First Search, Binary Tree |
| 代码随想录 | [102. 二叉树的层序遍历](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0102.二叉树的层序遍历.md)（二叉树章節） |
| 練到的 C++ | `TreeNode*`、`queue<TreeNode*>`、`vector<vector<int>>` |
| 對應前置練習 | 007 stack-queue-heap、011 tree-recursion |

> 執行：`make run Q=017`。卡住時可以用 `/hint 017`，完成後用 `/check 017`。

## 題目摘要
給二元樹的 `root`，**一層一層**由左到右回傳節點值，每一層是一個 `vector<int>`。

```
    3
   / \
  9  20
    /  \
   15   7
輸出：[[3],[9,20],[15,7]]
```

## 範例
| root（level-order） | 輸出 |
|---|---|
| `[3,9,20,null,null,15,7]` | `[[3],[9,20],[15,7]]` |
| `[1]` | `[[1]]` |
| `[]` | `[]` |

## 限制
- 節點數 `[0, 2000]`
- `-1000 <= Node.val <= 1000`

## 練習重點
- BFS 用 `queue`：怎麼知道「這一層」有幾個節點、什麼時候換下一層？
- 空樹要回傳 `{}`，不要對 `nullptr` 取 `->val`
- 這題是代码随想录「层序遍历」系列的母題，後面還有 10 題變化題
- `TreeNode` 的定義在 `include/lc/structures.hpp`，和 LeetCode 一樣

## 我的筆記
- 思路：
- 時間 / 空間複雜度：
- 卡住的地方：
