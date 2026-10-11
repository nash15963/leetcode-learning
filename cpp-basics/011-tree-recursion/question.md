# 011 · 二元樹與遞迴 — 練習題

> 先讀 notes.md。完成後執行 `make run Q=011`，全部 PASS 即完成。

所有程式碼都在 `main.cpp` 裡，把 `// TODO: 實作` 換成你的程式碼即可。這一題**不使用** `lc/structures.hpp`，`TreeNode` 由你自己完成。需要 helper 函式的話，直接加在 `main.cpp` 裡（放在使用它的函式上面）。

⚠️ 請**照順序**做：Task B 的 `buildTree` / `freeTree` 會被後面所有測試使用。

`TreeNode::alive` 是測試用的計數器（建構子 +1、解構子 -1），測試靠它檢查「有沒有 delete 乾淨」。**不要刪掉建構子裡的 `alive++`。**

本題用 `const int NUL = INT_MIN;` 代表 LeetCode 輸入裡的 `null`。

---

## Task A：TreeNode 建構子與計數（★）

完成兩個建構子（預設建構子已完成，當作範例），以及遞迴計數：

```cpp
TreeNode(int x);                              // val = x，左右都是 nullptr
TreeNode(int x, TreeNode* l, TreeNode* r);    // val = x, left = l, right = r

int countNodes(const TreeNode* root);         // 節點總數，空樹是 0
```

範例：

```
        1
       / \
      2   3          countNodes(root)        → 5
     / \             countNodes(節點 2)      → 3
    4   5            countNodes(nullptr)     → 0
```

練到的概念：member initializer list、遞迴三步驟（base case / 子問題 / 合併）

---

## Task B：從 level-order 陣列建樹，以及釋放（★★）

```cpp
TreeNode* buildTree(const vector<int>& vals);   // LeetCode 格式；空陣列或 vals[0] == NUL 回傳 nullptr
void freeTree(TreeNode* root);                  // delete 每一個節點
```

範例：

```
{1, 2, 3, NUL, 4, 5}           {1, NUL, 2, 3}

        1                        1
       / \                        \
      2   3                        2
       \  /                       /
        4 5                      3
```

- `{}` 或 `{NUL}` → `nullptr`
- 建好之後 `TreeNode::alive` 要等於節點數；`freeTree` 之後要回到 0

練到的概念：`new`、`queue<TreeNode*>`（`push` / `front` / `pop`）、索引邊界檢查、後序 `delete`

提示：

- `buildTree`：用一個 queue 記住「還在等孩子的節點」。每次從 queue 取出一個節點，依序讀接下來的兩個值當它的左、右孩子；新建立的孩子也要排進 queue。注意陣列可能在讀到右孩子之前就用完了。
- `freeTree`：想想看為什麼一定要「先刪孩子、再刪自己」。
- 測試用的 `valAt(root, "LR")` 代表「從 root 往左再往右」那個節點的值，走不到時回傳 `NUL`。

---

## Task C：前序 / 中序 / 後序（遞迴）（★★）

```cpp
vector<int> preorder(const TreeNode* root);    // 根 → 左 → 右
vector<int> inorder(const TreeNode* root);     // 左 → 根 → 右
vector<int> postorder(const TreeNode* root);   // 左 → 右 → 根
```

範例：

```
        1
       / \               preorder  → {1, 2, 4, 5, 3, 6}
      2   3              inorder   → {4, 2, 5, 1, 3, 6}
     / \   \             postorder → {4, 5, 2, 6, 3, 1}
    4   5   6

{1, NUL, 2, 3}           inorder   → {1, 3, 2}
```

練到的概念：helper 函式 + `vector<int>& out`、三種走訪只差在 `push_back` 的位置

提示：三個函式的 helper 長得幾乎一模一樣。

---

## Task D：所有 root-to-leaf 路徑（★★★）

LeetCode 257。回傳每一條從根走到**葉子**（左右都是 `nullptr`）的路徑，格式為 `"1->2->5"`，左子樹的路徑排在前面。

```cpp
vector<string> binaryTreePaths(const TreeNode* root);
```

範例：

```
        1
       / \               → {"1->2->5", "1->3"}
      2   3
       \
        5

{42}                     → {"42"}
{-1, 2, -3, 4, NUL, NUL, -5}  → {"-1->2->4", "-1->-3->-5"}
nullptr                  → {}
```

練到的概念：由上往下傳參數（目前的路徑）、判斷葉子、`to_string`、字串串接、傳值 vs 傳參考

提示：helper 可以長得像 `void dfs(const TreeNode* node, string path, vector<string>& out)`。`"->"` 什麼時候該加？只有「後面還有節點」的時候。

---

## Task E：用 stack 做迭代中序（★★★）

結果要和 Task C 的 `inorder` 一樣，但**不能用遞迴**，改用 `stack<const TreeNode*>`。

```cpp
vector<int> inorderIterative(const TreeNode* root);
```

範例：

```
{1, 2, 3, 4, 5, NUL, 6}                          → {4, 2, 5, 1, 3, 6}
{8, 3, 10, 1, 6, NUL, 14, NUL, NUL, 4, 7, 13}    → {1, 3, 4, 6, 7, 8, 10, 13, 14}   （BST → 由小到大）
一路往左、長度 2000 的長鏈                         → {2000, 1999, ..., 1}
```

練到的概念：`stack` 的 `push` / `top` / `pop` / `empty`、用 stack 模擬遞迴的呼叫堆疊、`while` 條件設計

提示：遞迴版的中序其實在做「一路往左走到底（沿路記住經過的節點）→ 處理最後記住的那個 → 轉向它的右子樹，重複」。外層迴圈要在「還有路可以走 **或** stack 裡還有東西」時繼續。

---

## 完成檢查

- [ ] `make run Q=011` 全部 PASS
- [ ] 沒有任何 sanitizer 錯誤訊息（`runtime error` / `AddressSanitizer`）
- [ ] 能說出每個 Task 用到的概念（特別是：遞迴的 base case 是什麼？為什麼 `freeTree` 要用後序？為什麼 helper 的 vector 要傳參考？）
