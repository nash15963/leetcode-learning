// 010 · 指標與 Linked List（ListNode / new / delete / dummy head / 快慢指標）
// 執行：make run Q=010
// 題目說明見 question.md
//
// 這一題「不」使用 lc/structures.hpp，ListNode 由你自己定義。

#include <numeric>  // iota（測試用）
#include <vector>

#include "lc/test.hpp"

using namespace std;

// ===== Task A：ListNode 建構子與走訪 =====

struct ListNode {
    int val = 0;               // = 0 / = nullptr 是保險用的預設值（default member initializer）
    ListNode* next = nullptr;  // initializer list 有寫的話會以 initializer list 為準

    // 測試用，不用改：目前「建構了但還沒解構」的節點數。建構子 +1、解構子 -1
    inline static int alive = 0;

    // 預設建構子（範例，已完成）
    ListNode() : val(0), next(nullptr) { alive++; }

    // TODO: 實作 — 用 member initializer list：val = x、next = nullptr（alive++ 那行保留）
    ListNode(int x) { alive++; }

    // TODO: 實作 — 用 member initializer list：val = x、next = nxt（alive++ 那行保留）
    ListNode(int x, ListNode* nxt) { alive++; }

    ~ListNode() { alive--; }  // 解構子：delete 節點時自動呼叫，不用改
};

// 回傳串列長度（head 可能是 nullptr）
int length(const ListNode* head) {
    // TODO: 實作
    return 0;
}

// 回傳第一個 val == target 的節點；找不到回傳 nullptr
ListNode* findFirst(ListNode* head, int target) {
    // TODO: 實作
    return nullptr;
}

// ===== Task B：vector ↔ linked list，以及 delete =====

// 依序用 new 建立節點，回傳 head；vals 為空時回傳 nullptr
ListNode* buildList(const vector<int>& vals) {
    // TODO: 實作
    return nullptr;
}

// 依序把每個節點的 val 放進 vector
vector<int> toVector(const ListNode* head) {
    // TODO: 實作
    return {};
}

// delete 串列中的每一個節點
void freeList(ListNode* head) {
    // TODO: 實作
}

// ===== Task C：快慢指標找中點 =====

// 回傳中間的節點；長度為偶數時回傳「第二個」中間節點；空串列回傳 nullptr
ListNode* middleNode(ListNode* head) {
    // TODO: 實作
    return nullptr;
}

// ===== Task D：插入節點（head 會變怎麼辦？）=====

// 在最前面插入 val。注意參數是 ListNode*&：你可以直接改呼叫端的 head
void pushFront(ListNode*& head, int val) {
    // TODO: 實作
}

// 插入 val，讓它成為第 pos 個節點（0-based），回傳新的 head
// pos == 長度 → 接在最後；pos < 0 或 pos > 長度 → 不插入，原樣回傳
ListNode* insertAt(ListNode* head, int pos, int val) {
    // TODO: 實作
    return head;
}

// ===== Task E：dummy head — 刪除所有指定值 =====

// 刪掉所有 val == target 的節點（被刪的節點要 delete），回傳新的 head
ListNode* removeElements(ListNode* head, int target) {
    // TODO: 實作
    return head;
}

int main() {
    lc::section("Task A：ListNode 建構子與走訪");
    ListNode::alive = 0;  // 測試用：每個 Task 重新計數
    {
        ListNode c(3);
        ListNode b(2, &c);
        ListNode a(1, &b);  // a → b → c → nullptr（節點在 stack 上，離開 {} 自動解構，不用 delete）
        CHECK_EQ(a.val, 1);
        CHECK_EQ(c.val, 3);
        CHECK(a.next == &b);
        CHECK(b.next == &c);
        CHECK(c.next == nullptr);
        CHECK_EQ(length(&a), 3);
        CHECK_EQ(length(&c), 1);
        CHECK_EQ(length(nullptr), 0);
        CHECK(findFirst(&a, 2) == &b);
        CHECK(findFirst(&a, 3) == &c);
        CHECK(findFirst(&a, 9) == nullptr);
    }
    CHECK_EQ(ListNode::alive, 0);

    lc::section("Task B：vector ↔ linked list，以及 delete");
    ListNode::alive = 0;
    {
        ListNode* head = buildList({1, 2, 3});
        CHECK_EQ(toVector(head), {1, 2, 3});
        CHECK_EQ(ListNode::alive, 3);  // new 了 3 個節點
        freeList(head);
        CHECK_EQ(ListNode::alive, 0);  // 全部 delete 掉了

        ListNode* one = buildList({42});
        CHECK_EQ(toVector(one), {42});
        freeList(one);

        CHECK(buildList({}) == nullptr);
        CHECK_EQ(toVector(nullptr), {});

        vector<int> big(1000);
        iota(big.begin(), big.end(), -500);  // -500, -499, ..., 499
        ListNode* bigList = buildList(big);
        CHECK_EQ(length(bigList), 1000);
        CHECK(toVector(bigList) == big);
        freeList(bigList);
        CHECK_EQ(ListNode::alive, 0);
    }

    lc::section("Task C：快慢指標找中點");
    ListNode::alive = 0;
    {
        ListNode* h = buildList({1, 2, 3, 4, 5});
        ListNode* mid = middleNode(h);
        CHECK_EQ(toVector(mid), {3, 4, 5});  // 回傳的是原串列裡的節點
        CHECK_EQ(ListNode::alive, 5);        // 找中點不應該 new 任何節點
        freeList(h);

        h = buildList({1, 2, 3, 4, 5, 6});
        CHECK_EQ(toVector(middleNode(h)), {4, 5, 6});  // 偶數長度 → 第二個中間節點
        freeList(h);

        h = buildList({1, 2});
        CHECK_EQ(toVector(middleNode(h)), {2});
        freeList(h);

        h = buildList({7});
        CHECK_EQ(toVector(middleNode(h)), {7});
        freeList(h);

        CHECK(middleNode(nullptr) == nullptr);
    }

    lc::section("Task D：插入節點（head 會變怎麼辦？）");
    ListNode::alive = 0;
    {
        ListNode* h = nullptr;
        pushFront(h, 3);
        pushFront(h, 2);
        pushFront(h, 1);
        CHECK_EQ(toVector(h), {1, 2, 3});

        h = insertAt(h, 0, 0);  // 插在最前面 → head 換人
        CHECK_EQ(toVector(h), {0, 1, 2, 3});
        h = insertAt(h, 2, 9);
        CHECK_EQ(toVector(h), {0, 1, 9, 2, 3});
        h = insertAt(h, 5, 4);  // pos == 長度 → 接在最後
        CHECK_EQ(toVector(h), {0, 1, 9, 2, 3, 4});
        h = insertAt(h, 7, 8);   // 超出範圍 → 不變
        h = insertAt(h, -1, 8);  // 負數 → 不變
        CHECK_EQ(toVector(h), {0, 1, 9, 2, 3, 4});
        CHECK_EQ(ListNode::alive, 6);  // 無效的插入不能 new 節點
        freeList(h);

        ListNode* e = insertAt(nullptr, 0, 5);  // 空串列插在位置 0
        CHECK_EQ(toVector(e), {5});
        freeList(e);
        CHECK_EQ(ListNode::alive, 0);
    }

    lc::section("Task E：dummy head — 刪除所有指定值");
    ListNode::alive = 0;
    {
        ListNode* h = buildList({1, 2, 6, 3, 4, 5, 6});
        h = removeElements(h, 6);
        CHECK_EQ(toVector(h), {1, 2, 3, 4, 5});
        CHECK_EQ(ListNode::alive, 5);  // 被刪掉的 2 個節點要 delete
        freeList(h);

        h = buildList({1, 1, 2, 1, 3});  // 連續好幾個要刪，而且包含 head
        h = removeElements(h, 1);
        CHECK_EQ(toVector(h), {2, 3});
        CHECK_EQ(ListNode::alive, 2);
        freeList(h);

        h = buildList({7, 7, 7, 7});  // 全部刪光
        h = removeElements(h, 7);
        CHECK(h == nullptr);

        h = buildList({1, 2, 3});  // 沒有要刪的
        h = removeElements(h, 9);
        CHECK_EQ(toVector(h), {1, 2, 3});
        freeList(h);

        CHECK(removeElements(nullptr, 1) == nullptr);
        CHECK_EQ(ListNode::alive, 0);
    }

    return lc::summary();
}
