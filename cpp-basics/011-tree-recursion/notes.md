# 011 · 二元樹與遞迴

## 這一課學什麼

- 自己定義 `TreeNode`（`val` / `left` / `right` + 建構子），就是 LeetCode 給你的那個 struct
- 遞迴的三個步驟：**base case → 交給子樹 → 合併結果**
- 把 LeetCode 的 level-order 陣列（例如 `[1,2,3,null,4]`）建成一棵樹；用 `NUL = INT_MIN` 代表 null
- 前序 / 中序 / 後序走訪，以及「helper 函式 + `vector<int>& out`」的寫法
- 由上往下傳參數（路徑）vs 由下往上回傳值（節點數）
- 不用遞迴，用 `stack` 模擬中序走訪
- 後序 `delete` 釋放整棵樹

## 語法速查

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};
const int NUL = INT_MIN;   // #include <climits>

// ---- 由下往上：回傳值（例：整棵樹的總和）----
long long sumTree(const TreeNode* root) {
    if (root == nullptr) return 0;                  // 1. base case：空樹
    long long l = sumTree(root->left);              // 2. 相信遞迴會算好子樹
    long long r = sumTree(root->right);
    return l + r + root->val;                       // 3. 合併
}

// ---- 收集結果：helper + 傳參考的 vector（例：收集所有葉子）----
void collectLeaves(const TreeNode* node, vector<int>& out) {
    if (node == nullptr) return;
    if (node->left == nullptr && node->right == nullptr) out.push_back(node->val);
    collectLeaves(node->left, out);
    collectLeaves(node->right, out);
}
vector<int> leaves(const TreeNode* root) {
    vector<int> out;
    collectLeaves(root, out);     // 整個遞迴共用同一個 out
    return out;
}

// ---- 由上往下：把資訊當參數往下傳（例：每個節點的深度）----
void visit(const TreeNode* node, int depth) {
    if (node == nullptr) return;
    // 這裡 depth 就是 node 的深度
    visit(node->left, depth + 1);
    visit(node->right, depth + 1);
}

// ---- queue / stack 速查（007 學過）----
queue<TreeNode*> q;  q.push(root);  TreeNode* f = q.front();  q.pop();   // 先進先出
stack<const TreeNode*> st;  st.push(root);  auto t = st.top();  st.pop(); // 後進先出
string s = to_string(-12) + "->";   // "-12->"
```

### 圖解：level-order 陣列 → 樹

```
vals = {1, 2, 3, NUL, 4, 5}

            1                 第 0 層：1
          /   \
         2     3              第 1 層：2, 3（1 的左、右）
          \   /
           4 5                第 2 層：NUL, 4（2 的左、右），5（3 的左），3 的右沒寫 = NUL

規則：依序「把下一個（或兩個）值分給目前還沒分配孩子的節點」。
NUL 的位置不會產生節點，所以它也「不會」有孩子出現在陣列裡（不是 heap 的 2i+1）。
```

### 圖解：指標長什麼樣

```
 root
  |
  v
 +------+---+-------+
 | left | 1 | right |
 +--+---+---+---+---+
    |           |
    v           v
 +------+---+-------+       +------+---+------+
 | null | 2 | right |       | left | 3 | null |
 +------+---+---+---+       +--+---+---+------+
                |              |
                v              v
           [null|4|null]  [null|5|null]
```

### 三種走訪（只差在「處理自己」放在哪）

| 走訪 | 順序 | 用途 |
|---|---|---|
| 前序 preorder | 根 → 左 → 右 | 複製樹、序列化、由上往下傳資訊 |
| 中序 inorder | 左 → 根 → 右 | BST 會得到由小到大的序列 |
| 後序 postorder | 左 → 右 → 根 | 先處理完孩子才處理自己：釋放樹、計算高度 / 子樹大小 |

## 常見坑

1. **忘了 base case** → 對 `nullptr` 用 `->`，UBSan：`member access within null pointer of type 'TreeNode'`

   ```cpp
   int f(const TreeNode* root) { return 1 + f(root->left) + f(root->right); }  // ❌
   if (root == nullptr) return 0;                                               // ✅ 第一行先寫這個
   ```

2. **helper 的 vector 傳值** → 每一層都在改自己的複本，最後拿到空陣列

   ```cpp
   void helper(const TreeNode* node, vector<int> out);    // ❌
   void helper(const TreeNode* node, vector<int>& out);   // ✅
   ```

3. **先 delete 自己才去刪孩子** → use-after-free（ASan：`heap-use-after-free`）

   ```cpp
   delete root; freeTree(root->left);                     // ❌ root 已經沒了
   freeTree(root->left); freeTree(root->right); delete root;  // ✅ 後序
   ```

4. **用 heap 的索引公式建 LeetCode 的樹**：`{1, NUL, 2, 3}` 裡的 `3` 是 `2` 的孩子，不是 `NUL` 的孩子

   ```cpp
   node->left = build(vals, 2 * i + 1);   // ❌ 只適用「完全二元樹」格式
   // ✅ 用 queue 依序分配孩子（見上面的圖解）
   ```

5. **讀 `vals[i]` 前沒檢查 `i < vals.size()`** → 越界（ASan 可能報 `heap-buffer-overflow`，沒報也是錯的）

   ```cpp
   if (vals[i] != NUL) { ... }                      // ❌ 陣列可能已經用完了
   if (i < vals.size() && vals[i] != NUL) { ... }   // ✅
   ```

6. **路徑用 `string&` 傳卻沒有「復原」** → 左子樹的內容殘留到右子樹

   ```cpp
   void dfs(const TreeNode* n, string& path, ...) { path += ...; dfs(n->left, path, ...); dfs(n->right, path, ...); }  // ❌
   void dfs(const TreeNode* n, string path, ...);   // ✅ 傳值最簡單；傳參考的話 return 前要把 path 改回去
   ```

7. **樹退化成一條長鏈時遞迴太深** → `stack-overflow`。節點數 1e5 以上又可能退化時，改用 `stack` 的迭代寫法。

## 在 LeetCode 會怎麼用

- 樹的題目 90% 是遞迴：先寫 `if (root == nullptr) return ...;`，再想「左右子樹的答案怎麼合併成我的答案」。
- 要收集一串結果時用「helper + `vector<int>& out`」；需要記錄路徑時把路徑當參數往下傳。
- BST 題（第 k 小、驗證 BST、BST iterator）常用**迭代中序**，因為可以隨時停下來。
- LeetCode 已經定義好 `TreeNode`，題目給的 `[1,2,3,null,4]` 就是本課的 level-order 格式；之後的 017 會用 `queue` 做「一層一層」的走訪。

## 參考

- [Pointer declaration](https://en.cppreference.com/w/cpp/language/pointer)
- [std::queue](https://en.cppreference.com/w/cpp/container/queue)
- [std::stack](https://en.cppreference.com/w/cpp/container/stack)
- [std::to_string](https://en.cppreference.com/w/cpp/string/basic_string/to_string)
- [delete expression](https://en.cppreference.com/w/cpp/language/delete)
- [Tree traversal（Wikipedia）](https://en.wikipedia.org/wiki/Tree_traversal)
