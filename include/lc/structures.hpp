// LeetCode 常用資料結構 + 測試用的建構/轉換工具
//
// ListNode / TreeNode 的定義和 LeetCode 一致（放在全域），
// 所以 class Solution 可以直接貼到 LeetCode 送出。
//
// 用法：
//   ListNode* head = lc::make_list({1, 2, 3});
//   std::vector<int> v = lc::to_vector(head);
//   lc::free_list(head);
//
//   TreeNode* root = lc::make_tree({3, 9, 20, lc::null, lc::null, 15, 7});
//   lc::free_tree(root);
#pragma once

#include <climits>
#include <queue>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

namespace lc {

// level-order 陣列裡代表「沒有節點」的值（LeetCode 上寫成 null）
inline constexpr int null = INT_MIN;

// ---------- Linked List ----------
inline ListNode* make_list(const std::vector<int>& vals) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int x : vals) {
        tail->next = new ListNode(x);
        tail = tail->next;
    }
    return dummy.next;
}

inline std::vector<int> to_vector(const ListNode* head) {
    std::vector<int> out;
    for (const ListNode* p = head; p != nullptr; p = p->next) out.push_back(p->val);
    return out;
}

inline void free_list(ListNode* head) {
    while (head != nullptr) {
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

// ---------- Binary Tree ----------
// 依照 LeetCode 的 level-order 格式建樹，例如 {1, lc::null, 2, 3}
inline TreeNode* make_tree(const std::vector<int>& vals) {
    if (vals.empty() || vals[0] == null) return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* cur = q.front();
        q.pop();
        if (i < vals.size() && vals[i] != null) {
            cur->left = new TreeNode(vals[i]);
            q.push(cur->left);
        }
        i++;
        if (i < vals.size() && vals[i] != null) {
            cur->right = new TreeNode(vals[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

// 轉回 LeetCode 的 level-order 格式（去掉結尾多餘的 null）
inline std::vector<int> to_level_vector(const TreeNode* root) {
    std::vector<int> out;
    std::queue<const TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        const TreeNode* cur = q.front();
        q.pop();
        if (cur == nullptr) {
            out.push_back(null);
            continue;
        }
        out.push_back(cur->val);
        q.push(cur->left);
        q.push(cur->right);
    }
    while (!out.empty() && out.back() == null) out.pop_back();
    return out;
}

inline void free_tree(TreeNode* root) {
    if (root == nullptr) return;
    free_tree(root->left);
    free_tree(root->right);
    delete root;
}

}  // namespace lc
