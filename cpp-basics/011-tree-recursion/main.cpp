// 011 · 二元樹與遞迴（TreeNode / 建樹 / 前中後序 / 迭代中序 / 釋放）
// 執行：make run Q=011
// 題目說明見 question.md
//
// 這一題「不」使用 lc/structures.hpp，TreeNode 由你自己定義。

#include <climits>  // INT_MIN
#include <queue>    // Task B 建樹會用到
#include <stack>    // Task E 會用到
#include <string>   // to_string
#include <vector>

#include "lc/test.hpp"

using namespace std;

// level-order 陣列裡代表「這個位置沒有節點」的值（LeetCode 上寫成 null）
const int NUL = INT_MIN;

// ===== Task A：TreeNode 建構子與計數 =====

struct TreeNode {
    int val = 0;                // = 0 / = nullptr 是保險用的預設值
    TreeNode* left = nullptr;   // initializer list 有寫的話會以 initializer list 為準
    TreeNode* right = nullptr;

    // 測試用，不用改：目前「建構了但還沒解構」的節點數。建構子 +1、解構子 -1
    inline static int alive = 0;

    // 預設建構子（範例，已完成）
    TreeNode() : val(0), left(nullptr), right(nullptr) { alive++; }

    // TODO: 實作 — 用 member initializer list：val = x，左右都是 nullptr（alive++ 那行保留）
    TreeNode(int x) { alive++; }

    // TODO: 實作 — 用 member initializer list：val = x、left = l、right = r（alive++ 那行保留）
    TreeNode(int x, TreeNode* l, TreeNode* r) { alive++; }

    ~TreeNode() { alive--; }  // 解構子：delete 節點時自動呼叫，不用改
};

// 回傳整棵樹的節點數（遞迴）
int countNodes(const TreeNode* root) {
    // TODO: 實作
    return 0;
}

// ===== Task B：從 level-order 陣列建樹，以及釋放 =====

// 依照 LeetCode 的 level-order 格式建樹，NUL 代表沒有節點；空陣列或 vals[0] == NUL 回傳 nullptr
TreeNode* buildTree(const vector<int>& vals) {
    // TODO: 實作
    return nullptr;
}

// delete 整棵樹的每一個節點（後序：先處理孩子，再刪自己）
void freeTree(TreeNode* root) {
    // TODO: 實作
}

// 測試用，不用改：從 root 照 path 走（'L' 往左、'R' 往右），回傳到達節點的 val；走不到回傳 NUL
int valAt(const TreeNode* root, const string& path) {
    const TreeNode* cur = root;
    for (char c : path) {
        if (cur == nullptr) return NUL;
        cur = (c == 'L') ? cur->left : cur->right;
    }
    return cur == nullptr ? NUL : cur->val;
}

// ===== Task C：前序 / 中序 / 後序（遞迴）=====
// 可以自己在上面加 helper 函式，例如 void preorderHelper(const TreeNode* node, vector<int>& out)

// 前序：根 → 左 → 右
vector<int> preorder(const TreeNode* root) {
    // TODO: 實作
    return {};
}

// 中序：左 → 根 → 右
vector<int> inorder(const TreeNode* root) {
    // TODO: 實作
    return {};
}

// 後序：左 → 右 → 根
vector<int> postorder(const TreeNode* root) {
    // TODO: 實作
    return {};
}

// ===== Task D：所有 root-to-leaf 路徑 =====

// 回傳每一條「根 → 葉子」路徑，格式 "1->2->5"；順序：左子樹的路徑在前
vector<string> binaryTreePaths(const TreeNode* root) {
    // TODO: 實作
    return {};
}

// ===== Task E：用 stack 做迭代中序 =====

// 和 inorder 結果相同，但「不能用遞迴」，改用 stack<const TreeNode*>
vector<int> inorderIterative(const TreeNode* root) {
    // TODO: 實作
    return {};
}

int main() {
    lc::section("Task A：TreeNode 建構子與計數");
    TreeNode::alive = 0;  // 測試用：每個 Task 重新計數
    {
        // 節點在 stack 上，離開 {} 自動解構，不用 delete
        //        n1(1)
        //       /    \        （n1 的左孩子 n2、右孩子 n3）
        //    n2(2)   n3(3)
        //    /   \            （n2 的左孩子 n4、右孩子 n5）
        // n4(4)  n5(5)
        TreeNode n4(4), n5(5), n3(3);
        TreeNode n2(2, &n4, &n5);
        TreeNode n1(1, &n2, &n3);
        CHECK_EQ(n1.val, 1);
        CHECK_EQ(n4.val, 4);
        CHECK(n1.left == &n2 && n1.right == &n3);
        CHECK(n2.left == &n4 && n2.right == &n5);
        CHECK_EQ(countNodes(&n1), 5);
        CHECK_EQ(countNodes(&n2), 3);
        CHECK_EQ(countNodes(&n4), 1);
        CHECK_EQ(countNodes(nullptr), 0);
    }
    CHECK_EQ(TreeNode::alive, 0);

    lc::section("Task B：從 level-order 陣列建樹，以及釋放");
    TreeNode::alive = 0;
    {
        // {1, 2, 3, NUL, 4, 5}：1 的孩子是 2、3；2 的孩子是 NUL、4；3 的孩子是 5、（沒寫）
        TreeNode* t = buildTree({1, 2, 3, NUL, 4, 5});
        CHECK_EQ(valAt(t, ""), 1);
        CHECK_EQ(valAt(t, "L"), 2);
        CHECK_EQ(valAt(t, "R"), 3);
        CHECK_EQ(valAt(t, "LL"), NUL);
        CHECK_EQ(valAt(t, "LR"), 4);
        CHECK_EQ(valAt(t, "RL"), 5);
        CHECK_EQ(TreeNode::alive, 5);  // new 了 5 個節點
        freeTree(t);
        CHECK_EQ(TreeNode::alive, 0);  // 全部 delete 掉了

        // NUL 節點的孩子「不會」出現在陣列裡（LeetCode 格式，不是 heap 的 2i+1）
        TreeNode* s = buildTree({1, NUL, 2, 3});
        CHECK_EQ(valAt(s, "R"), 2);
        CHECK_EQ(valAt(s, "RL"), 3);
        CHECK_EQ(countNodes(s), 3);
        freeTree(s);

        TreeNode* neg = buildTree({-1, -2, NUL, -3});
        CHECK_EQ(valAt(neg, "LL"), -3);
        freeTree(neg);

        CHECK(buildTree({}) == nullptr);
        CHECK(buildTree({NUL}) == nullptr);
        CHECK_EQ(TreeNode::alive, 0);
    }

    lc::section("Task C：前序 / 中序 / 後序（遞迴）");
    TreeNode::alive = 0;
    {
        //        1
        //      2   3
        //     4 5    6
        TreeNode* t = buildTree({1, 2, 3, 4, 5, NUL, 6});
        CHECK_EQ(preorder(t), {1, 2, 4, 5, 3, 6});
        CHECK_EQ(inorder(t), {4, 2, 5, 1, 3, 6});
        CHECK_EQ(postorder(t), {4, 5, 2, 6, 3, 1});
        freeTree(t);

        TreeNode* chain = buildTree({1, NUL, 2, 3});  // 1 的右孩子是 2，2 的左孩子是 3
        CHECK_EQ(preorder(chain), {1, 2, 3});
        CHECK_EQ(inorder(chain), {1, 3, 2});
        CHECK_EQ(postorder(chain), {3, 2, 1});
        freeTree(chain);

        TreeNode* one = buildTree({7});
        CHECK_EQ(inorder(one), {7});
        freeTree(one);

        CHECK_EQ(preorder(nullptr), {});
        CHECK_EQ(TreeNode::alive, 0);
    }

    lc::section("Task D：所有 root-to-leaf 路徑");
    TreeNode::alive = 0;
    {
        TreeNode* t = buildTree({1, 2, 3, NUL, 5});
        CHECK_EQ(binaryTreePaths(t), {"1->2->5", "1->3"});
        freeTree(t);

        TreeNode* one = buildTree({42});
        CHECK_EQ(binaryTreePaths(one), {"42"});
        freeTree(one);

        TreeNode* neg = buildTree({-1, 2, -3, 4, NUL, NUL, -5});
        CHECK_EQ(binaryTreePaths(neg), {"-1->2->4", "-1->-3->-5"});
        freeTree(neg);

        TreeNode* full = buildTree({1, 2, 3, 4, 5, 6, 7});
        CHECK_EQ(binaryTreePaths(full), {"1->2->4", "1->2->5", "1->3->6", "1->3->7"});
        freeTree(full);

        CHECK_EQ(binaryTreePaths(nullptr), {});
        CHECK_EQ(TreeNode::alive, 0);
    }

    lc::section("Task E：用 stack 做迭代中序");
    TreeNode::alive = 0;
    {
        TreeNode* t = buildTree({1, 2, 3, 4, 5, NUL, 6});
        CHECK_EQ(inorderIterative(t), {4, 2, 5, 1, 3, 6});
        freeTree(t);

        TreeNode* chain = buildTree({1, NUL, 2, 3});
        CHECK_EQ(inorderIterative(chain), {1, 3, 2});
        freeTree(chain);

        // BST（二元搜尋樹）的中序走訪會由小到大
        TreeNode* bst = buildTree({8, 3, 10, 1, 6, NUL, 14, NUL, NUL, 4, 7, 13});
        CHECK_EQ(inorderIterative(bst), {1, 3, 4, 6, 7, 8, 10, 13, 14});
        freeTree(bst);

        CHECK_EQ(inorderIterative(nullptr), {});

        // 一路往左的長鏈：1 → 2 → ... → 2000（全部是左孩子），中序是 2000, 1999, ..., 1
        vector<int> vals = {1};
        for (int i = 2; i <= 2000; i++) {
            vals.push_back(i);
            vals.push_back(NUL);
        }
        vector<int> want;
        for (int i = 2000; i >= 1; i--) want.push_back(i);
        TreeNode* deep = buildTree(vals);
        CHECK(inorderIterative(deep) == want);
        freeTree(deep);
        CHECK_EQ(TreeNode::alive, 0);
    }

    return lc::summary();
}
