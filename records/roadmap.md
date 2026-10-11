# 刷題地圖：代码随想录

> 來源：[youngyangyang04/leetcode-master](https://github.com/youngyangyang04/leetcode-master)（《代码随想录》，簡體中文，題解以 C++ 為主）
> 由上而下依序刷；每章先讀 📖 理論基礎，再做題，最後讀總結篇。
> 下一題用 `/new-question next` 建立；完成後把 `[ ]` 改成 `[x]`（`/check` 會自動更新）。

## 圖例

| 符號 | 意義 |
|---|---|
| 📖 | 閱讀：理論基礎 / 總結篇 |
| 🟢 | LeetCode 題（核心，必做） |
| 🔁 | 前面章節出現過的題目，換個角度複習 |
| 🅰️ | 卡码网 ACM 模式題（選做；要自己處理輸入輸出，可練 `cin`/`cout`） |
| ⭐ | 已在前置練習 013–017 做過，可以直接打勾或當成複習 |

統計：🟢 131 題 ・ 🔁 12 題 ・ 🅰️ 30 題 ・ 📖 43 篇

> ⚠️ 圖論章節在代码随想录全部是卡码网 ACM 題；做到那裡時再請導師補上對應的 LeetCode 題（例如 #200 Number of Islands）。

## 00 演算法效能分析 Complexity（前序）

- [ ] 📖 [关于时间复杂度，你不知道的都在这里！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%89%8D%E5%BA%8F/%E6%97%B6%E9%97%B4%E5%A4%8D%E6%9D%82%E5%BA%A6.md)
- [ ] 📖 [O(n)的算法居然超时了，此时的n究竟是多大？](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%89%8D%E5%BA%8F/%E7%AE%97%E6%B3%95%E8%B6%85%E6%97%B6.md)
- [ ] 📖 [通过一道面试题目，讲一讲递归算法的时间复杂度！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%89%8D%E5%BA%8F/%E9%80%92%E5%BD%92%E7%AE%97%E6%B3%95%E7%9A%84%E6%97%B6%E9%97%B4%E5%A4%8D%E6%9D%82%E5%BA%A6.md)
- [ ] 📖 [关于空间复杂度，可能有几个疑问？](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%89%8D%E5%BA%8F/%E7%A9%BA%E9%97%B4%E5%A4%8D%E6%9D%82%E5%BA%A6.md)
- [ ] 📖 [递归算法的时间与空间复杂度分析！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%89%8D%E5%BA%8F/%E9%80%92%E5%BD%92%E7%AE%97%E6%B3%95%E7%9A%84%E6%97%B6%E9%97%B4%E4%B8%8E%E7%A9%BA%E9%97%B4%E5%A4%8D%E6%9D%82%E5%BA%A6%E5%88%86%E6%9E%90.md)
- [ ] 📖 [刷了这么多题，你了解自己代码的内存消耗么？](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%89%8D%E5%BA%8F/%E5%86%85%E5%AD%98%E6%B6%88%E8%80%97.md)

## 01 陣列 Array（数组）

- [ ] 📖 [数组过于简单，但你该了解这些！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E6%95%B0%E7%BB%84%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.md)
- [ ] 🟢 LC 704 [704.二分查找](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.md)
- [ ] 🟢 LC 27 [27.移除元素](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.md)
- [ ] 🟢 LC 977 [977.有序数组的平方](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.md)
- [ ] 🟢 LC 209 [209.长度最小的子数组](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.md)
- [ ] 🅰️ ACM [区间和](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0058.%E5%8C%BA%E9%97%B4%E5%92%8C.md)
- [ ] 🅰️ ACM [开发商购买土地](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0044.%E5%BC%80%E5%8F%91%E5%95%86%E8%B4%AD%E4%B9%B0%E5%9C%9F%E5%9C%B0.md)
- [ ] 🟢 LC 59 [59.螺旋矩阵II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.md)
- [ ] 📖 [总结篇](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E6%95%B0%E7%BB%84%E6%80%BB%E7%BB%93%E7%AF%87.md)

## 02 鏈結串列 Linked List（链表）

- [ ] 📖 [关于链表，你该了解这些！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E9%93%BE%E8%A1%A8%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.md)
- [ ] 🟢 LC 203 [203.移除链表元素](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.md)
- [ ] 🟢 LC 707 [707.设计链表](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.md)
- [ ] 🟢 LC 206 [206.翻转链表](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.md) ⭐ 前置練習 016 已做過
- [ ] 🟢 LC 24 [24.两两交换链表中的节点](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.md)
- [ ] 🟢 LC 19 [19.删除链表的倒数第 N 个结点](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.md)
- [ ] 🟢 面試題 02.07 [链表相交](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.md)
- [ ] 🟢 LC 142 [142.环形链表](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.md)
- [ ] 📖 [总结篇！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E9%93%BE%E8%A1%A8%E6%80%BB%E7%BB%93%E7%AF%87.md)

## 03 雜湊表 Hash Table（哈希表）

- [ ] 📖 [关于哈希表，你该了解这些！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%93%88%E5%B8%8C%E8%A1%A8%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.md)
- [ ] 🟢 LC 242 [242.有效的字母异位词](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.md)
- [ ] 🟢 LC 1002 [1002.查找常用字符](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/1002.%E6%9F%A5%E6%89%BE%E5%B8%B8%E7%94%A8%E5%AD%97%E7%AC%A6.md)
- [ ] 🟢 LC 349 [349.两个数组的交集](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.md)
- [ ] 🟢 LC 202 [202.快乐数](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.md)
- [ ] 🟢 LC 1 [1.两数之和](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.md) ⭐ 前置練習 013 已做過
- [ ] 🟢 LC 454 [454.四数相加II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.md)
- [ ] 🟢 LC 383 [383.赎金信](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0383.%E8%B5%8E%E9%87%91%E4%BF%A1.md)
- [ ] 🟢 LC 15 [15.三数之和](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.md)
- [ ] 🟢 LC 18 [18.四数之和](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.md)
- [ ] 📖 [总结篇！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%93%88%E5%B8%8C%E8%A1%A8%E6%80%BB%E7%BB%93.md)

## 04 字串 String（字符串）

- [ ] 🟢 LC 344 [344.反转字符串](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.md)
- [ ] 🟢 LC 541 [541.反转字符串II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.md)
- [ ] 🅰️ ACM [替换数字](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0054.%E6%9B%BF%E6%8D%A2%E6%95%B0%E5%AD%97.md)
- [ ] 🟢 LC 151 [151.翻转字符串里的单词](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.md)
- [ ] 🅰️ ACM [右旋字符串](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0055.%E5%8F%B3%E6%97%8B%E5%AD%97%E7%AC%A6%E4%B8%B2.md)
- [ ] 🟢 LC 28 [帮你把KMP算法学个通透](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0028.%E5%AE%9E%E7%8E%B0strStr.md)
- [ ] 🟢 LC 459 [459.重复的子字符串](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.md)
- [ ] 📖 [总结篇！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%80%BB%E7%BB%93.md)

## 05 雙指標 Two Pointers（双指针法）

- [ ] 🔁 LC 27 [27.移除元素](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.md)（複習，前面章節做過）
- [ ] 🔁 LC 344 [344.反转字符串](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.md)（複習，前面章節做過）
- [ ] 🅰️ ACM [替换数字](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0054.%E6%9B%BF%E6%8D%A2%E6%95%B0%E5%AD%97.md)
- [ ] 🔁 LC 151 [151.翻转字符串里的单词](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.md)（複習，前面章節做過）
- [ ] 🔁 LC 206 [206.翻转链表](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.md)（複習，前面章節做過）
- [ ] 🔁 LC 19 [19.删除链表的倒数第 N 个结点](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.md)（複習，前面章節做過）
- [ ] 🟢 面試題 02.07 [链表相交](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.md)
- [ ] 🔁 LC 142 [142.环形链表](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.md)（複習，前面章節做過）
- [ ] 🔁 LC 15 [15.三数之和](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.md)（複習，前面章節做過）
- [ ] 🔁 LC 18 [18.四数之和](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.md)（複習，前面章節做過）
- [ ] 📖 [总结篇！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%8F%8C%E6%8C%87%E9%92%88%E6%80%BB%E7%BB%93.md)

## 06 堆疊與佇列 Stack & Queue（栈与队列）

- [ ] 📖 [理论基础](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.md)
- [ ] 🟢 LC 232 [232.用栈实现队列](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.md)
- [ ] 🟢 LC 225 [225.用队列实现栈](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.md)
- [ ] 🟢 LC 20 [20.有效的括号](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0020.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.md) ⭐ 前置練習 014 已做過
- [ ] 🟢 LC 1047 [1047.删除字符串中的所有相邻重复项](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/1047.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89%E7%9B%B8%E9%82%BB%E9%87%8D%E5%A4%8D%E9%A1%B9.md)
- [ ] 🟢 LC 150 [150.逆波兰表达式求值](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0150.%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC.md)
- [ ] 🟢 LC 239 [239.滑动窗口最大值](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.md)
- [ ] 🟢 LC 347 [347.前K个高频元素](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0347.%E5%89%8DK%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0.md)
- [ ] 📖 [总结篇！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E6%A0%88%E4%B8%8E%E9%98%9F%E5%88%97%E6%80%BB%E7%BB%93.md)

## 07 二元樹 Binary Tree（二叉树）

- [ ] 📖 [关于二叉树，你该了解这些！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.md)
- [ ] 📖 [二叉树的递归遍历](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.md)
- [ ] 📖 [二叉树的迭代遍历](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.md)
- [ ] 📖 [二叉树的统一迭代法](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E7%BB%9F%E4%B8%80%E8%BF%AD%E4%BB%A3%E6%B3%95.md)
- [ ] 🟢 LC 102 [二叉树的层序遍历](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.md) ⭐ 前置練習 017 已做過
- [ ] 🟢 LC 226 [226.翻转二叉树](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0226.%E7%BF%BB%E8%BD%AC%E4%BA%8C%E5%8F%89%E6%A0%91.md)
- [ ] 🟢 LC 101 [101.对称二叉树](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0101.%E5%AF%B9%E7%A7%B0%E4%BA%8C%E5%8F%89%E6%A0%91.md)
- [ ] 🟢 LC 104 [104.二叉树的最大深度](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0104.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%A4%A7%E6%B7%B1%E5%BA%A6.md)
- [ ] 🟢 LC 111 [111.二叉树的最小深度](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0111.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E6%B7%B1%E5%BA%A6.md)
- [ ] 🟢 LC 222 [222.完全二叉树的节点个数](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0222.%E5%AE%8C%E5%85%A8%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%8A%82%E7%82%B9%E4%B8%AA%E6%95%B0.md)
- [ ] 🟢 LC 110 [110.平衡二叉树](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0110.%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91.md)
- [ ] 🟢 LC 257 [257.二叉树的所有路径](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0257.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%89%80%E6%9C%89%E8%B7%AF%E5%BE%84.md)
- [ ] 🟢 LC 404 [404.左叶子之和](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0404.%E5%B7%A6%E5%8F%B6%E5%AD%90%E4%B9%8B%E5%92%8C.md)
- [ ] 🟢 LC 513 [513.找树左下角的值](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0513.%E6%89%BE%E6%A0%91%E5%B7%A6%E4%B8%8B%E8%A7%92%E7%9A%84%E5%80%BC.md)
- [ ] 🟢 LC 112 [112.路径总和](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0112.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C.md)
- [ ] 🟢 LC 106 [106.构造二叉树](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0106.%E4%BB%8E%E4%B8%AD%E5%BA%8F%E4%B8%8E%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91.md)
- [ ] 🟢 LC 654 [654.最大二叉树](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0654.%E6%9C%80%E5%A4%A7%E4%BA%8C%E5%8F%89%E6%A0%91.md)
- [ ] 🟢 LC 617 [617.合并两个二叉树](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0617.%E5%90%88%E5%B9%B6%E4%BA%8C%E5%8F%89%E6%A0%91.md)
- [ ] 🟢 LC 700 [700.二叉搜索树登场！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0700.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E6%90%9C%E7%B4%A2.md)
- [ ] 🟢 LC 98 [98.验证二叉搜索树](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0098.%E9%AA%8C%E8%AF%81%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.md)
- [ ] 🟢 LC 530 [530.搜索树的最小绝对差](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0530.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E7%BB%9D%E5%AF%B9%E5%B7%AE.md)
- [ ] 🟢 LC 501 [501.二叉搜索树中的众数](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0501.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E4%BC%97%E6%95%B0.md)
- [ ] 🟢 LC 236 [236.公共祖先问题](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0236.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.md)
- [ ] 🟢 LC 235 [235.搜索树的最近公共祖先](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0235.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.md)
- [ ] 🟢 LC 701 [701.搜索树中的插入操作](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0701.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E6%8F%92%E5%85%A5%E6%93%8D%E4%BD%9C.md)
- [ ] 🟢 LC 450 [450.搜索树中的删除操作](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0450.%E5%88%A0%E9%99%A4%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.md)
- [ ] 🟢 LC 669 [669.修剪二叉搜索树](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0669.%E4%BF%AE%E5%89%AA%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.md)
- [ ] 🟢 LC 108 [108.将有序数组转换为二叉搜索树](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0108.%E5%B0%86%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E8%BD%AC%E6%8D%A2%E4%B8%BA%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.md)
- [ ] 🟢 LC 538 [538.把二叉搜索树转换为累加树](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0538.%E6%8A%8A%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E8%BD%AC%E6%8D%A2%E4%B8%BA%E7%B4%AF%E5%8A%A0%E6%A0%91.md)
- [ ] 📖 [总结篇！（需要掌握的二叉树技能都在这里了）](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E4%BA%8C%E5%8F%89%E6%A0%91%E6%80%BB%E7%BB%93%E7%AF%87.md)

## 08 回溯 Backtracking（回溯算法）

- [ ] 📖 [关于回溯算法，你该了解这些！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%9B%9E%E6%BA%AF%E7%AE%97%E6%B3%95%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.md)
- [ ] 🟢 LC 77 [77.组合](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0077.%E7%BB%84%E5%90%88.md)
- [ ] 🔁 LC 77 [77.组合优化](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0077.%E7%BB%84%E5%90%88%E4%BC%98%E5%8C%96.md)（複習，前面章節做過）
- [ ] 🟢 LC 216 [216.组合总和III](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0216.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CIII.md)
- [ ] 🟢 LC 17 [17.电话号码的字母组合](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0017.%E7%94%B5%E8%AF%9D%E5%8F%B7%E7%A0%81%E7%9A%84%E5%AD%97%E6%AF%8D%E7%BB%84%E5%90%88.md)
- [ ] 🟢 LC 39 [39.组合总和](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0039.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C.md)
- [ ] 🟢 LC 40 [40.组合总和II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0040.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CII.md)
- [ ] 🟢 LC 131 [131.分割回文串](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0131.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2.md)
- [ ] 🟢 LC 93 [93.复原IP地址](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0093.%E5%A4%8D%E5%8E%9FIP%E5%9C%B0%E5%9D%80.md)
- [ ] 🟢 LC 78 [78.子集](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0078.%E5%AD%90%E9%9B%86.md)
- [ ] 🟢 LC 90 [90.子集II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0090.%E5%AD%90%E9%9B%86II.md)
- [ ] 🟢 LC 491 [491.递增子序列](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0491.%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97.md)
- [ ] 🟢 LC 46 [46.全排列](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0046.%E5%85%A8%E6%8E%92%E5%88%97.md)
- [ ] 🟢 LC 47 [47.全排列II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0047.%E5%85%A8%E6%8E%92%E5%88%97II.md)
- [ ] 📖 [回溯算法去重问题的另一种写法](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%9B%9E%E6%BA%AF%E7%AE%97%E6%B3%95%E5%8E%BB%E9%87%8D%E9%97%AE%E9%A2%98%E7%9A%84%E5%8F%A6%E4%B8%80%E7%A7%8D%E5%86%99%E6%B3%95.md)
- [ ] 🟢 LC 332 [332.重新安排行程](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0332.%E9%87%8D%E6%96%B0%E5%AE%89%E6%8E%92%E8%A1%8C%E7%A8%8B.md)
- [ ] 🟢 LC 51 [51.N皇后](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0051.N%E7%9A%87%E5%90%8E.md)
- [ ] 🟢 LC 37 [37.解数独](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0037.%E8%A7%A3%E6%95%B0%E7%8B%AC.md)
- [ ] 📖 [回溯算法总结篇](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%9B%9E%E6%BA%AF%E6%80%BB%E7%BB%93.md)

## 09 貪婪 Greedy（贪心算法）

- [ ] 📖 [关于贪心算法，你该了解这些！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E8%B4%AA%E5%BF%83%E7%AE%97%E6%B3%95%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.md)
- [ ] 🟢 LC 455 [455.分发饼干](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0455.%E5%88%86%E5%8F%91%E9%A5%BC%E5%B9%B2.md)
- [ ] 🟢 LC 376 [376.摆动序列](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0376.%E6%91%86%E5%8A%A8%E5%BA%8F%E5%88%97.md)
- [ ] 🟢 LC 53 [53.最大子序和](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0053.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C.md)
- [ ] 🟢 LC 122 [122.买卖股票的最佳时机II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0122.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAII.md)
- [ ] 🟢 LC 55 [55.跳跃游戏](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0055.%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8F.md)
- [ ] 🟢 LC 45 [45.跳跃游戏II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0045.%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8FII.md)
- [ ] 🟢 LC 1005 [1005.K次取反后最大化的数组和](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/1005.K%E6%AC%A1%E5%8F%96%E5%8F%8D%E5%90%8E%E6%9C%80%E5%A4%A7%E5%8C%96%E7%9A%84%E6%95%B0%E7%BB%84%E5%92%8C.md)
- [ ] 🟢 LC 134 [134.加油站](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0134.%E5%8A%A0%E6%B2%B9%E7%AB%99.md)
- [ ] 🟢 LC 135 [135.分发糖果](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0135.%E5%88%86%E5%8F%91%E7%B3%96%E6%9E%9C.md)
- [ ] 🟢 LC 860 [860.柠檬水找零](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0860.%E6%9F%A0%E6%AA%AC%E6%B0%B4%E6%89%BE%E9%9B%B6.md)
- [ ] 🟢 LC 406 [406.根据身高重建队列](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0406.%E6%A0%B9%E6%8D%AE%E8%BA%AB%E9%AB%98%E9%87%8D%E5%BB%BA%E9%98%9F%E5%88%97.md)
- [ ] 📖 [406.根据身高重建队列（续集）](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E6%A0%B9%E6%8D%AE%E8%BA%AB%E9%AB%98%E9%87%8D%E5%BB%BA%E9%98%9F%E5%88%97%EF%BC%88vector%E5%8E%9F%E7%90%86%E8%AE%B2%E8%A7%A3%EF%BC%89.md)
- [ ] 🟢 LC 452 [452.用最少数量的箭引爆气球](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0452.%E7%94%A8%E6%9C%80%E5%B0%91%E6%95%B0%E9%87%8F%E7%9A%84%E7%AE%AD%E5%BC%95%E7%88%86%E6%B0%94%E7%90%83.md)
- [ ] 🟢 LC 435 [435.无重叠区间](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0435.%E6%97%A0%E9%87%8D%E5%8F%A0%E5%8C%BA%E9%97%B4.md)
- [ ] 🟢 LC 763 [763.划分字母区间](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0763.%E5%88%92%E5%88%86%E5%AD%97%E6%AF%8D%E5%8C%BA%E9%97%B4.md)
- [ ] 🟢 LC 56 [56.合并区间](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0056.%E5%90%88%E5%B9%B6%E5%8C%BA%E9%97%B4.md)
- [ ] 🟢 LC 738 [738.单调递增的数字](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0738.%E5%8D%95%E8%B0%83%E9%80%92%E5%A2%9E%E7%9A%84%E6%95%B0%E5%AD%97.md)
- [ ] 🟢 LC 968 [968.监控二叉树](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0968.%E7%9B%91%E6%8E%A7%E4%BA%8C%E5%8F%89%E6%A0%91.md)
- [ ] 📖 [总结篇！（每逢总结必经典）](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E8%B4%AA%E5%BF%83%E7%AE%97%E6%B3%95%E6%80%BB%E7%BB%93%E7%AF%87.md)

## 10 動態規劃 Dynamic Programming（动态规划）

- [ ] 📖 [关于动态规划，你该了解这些！](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.md)
- [ ] 🟢 LC 509 [509.斐波那契数](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0509.%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0.md)
- [ ] 🟢 LC 70 [70.爬楼梯](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0070.%E7%88%AC%E6%A5%BC%E6%A2%AF.md)
- [ ] 🟢 LC 746 [746.使用最小花费爬楼梯](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0746.%E4%BD%BF%E7%94%A8%E6%9C%80%E5%B0%8F%E8%8A%B1%E8%B4%B9%E7%88%AC%E6%A5%BC%E6%A2%AF.md)
- [ ] 🟢 LC 62 [62.不同路径](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0062.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84.md)
- [ ] 🟢 LC 63 [63.不同路径II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0063.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84II.md)
- [ ] 🟢 LC 343 [343.整数拆分](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0343.%E6%95%B4%E6%95%B0%E6%8B%86%E5%88%86.md)
- [ ] 🟢 LC 96 [96.不同的二叉搜索树](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0096.%E4%B8%8D%E5%90%8C%E7%9A%84%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.md)

### 背包问题系列

- [ ] 📖 [01背包理论基础（二维dp数组）](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-1.md)
- [ ] 📖 [01背包理论基础（一维dp数组）](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-2.md)
- [ ] 🟢 LC 416 [416.分割等和子集](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0416.%E5%88%86%E5%89%B2%E7%AD%89%E5%92%8C%E5%AD%90%E9%9B%86.md)
- [ ] 🟢 LC 1049 [1049.最后一块石头的重量II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/1049.%E6%9C%80%E5%90%8E%E4%B8%80%E5%9D%97%E7%9F%B3%E5%A4%B4%E7%9A%84%E9%87%8D%E9%87%8FII.md)
- [ ] 🟢 LC 494 [494.目标和](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0494.%E7%9B%AE%E6%A0%87%E5%92%8C.md)
- [ ] 🟢 LC 474 [474.一和零](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0474.%E4%B8%80%E5%92%8C%E9%9B%B6.md)
- [ ] 📖 [完全背包理论基础（二维dp数组）](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85.md)
- [ ] 📖 [完全背包理论基础（一维dp数组）](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85%E4%B8%80%E7%BB%B4.md)
- [ ] 🟢 LC 518 [518.零钱兑换II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0518.%E9%9B%B6%E9%92%B1%E5%85%91%E6%8D%A2II.md)
- [ ] 🟢 LC 377 [377.组合总和Ⅳ](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0377.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C%E2%85%A3.md)
- [ ] 🔁 LC 70 [70.爬楼梯（完全背包版本）](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0070.%E7%88%AC%E6%A5%BC%E6%A2%AF%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85%E7%89%88%E6%9C%AC.md)（複習，前面章節做過）
- [ ] 🟢 LC 322 [322.零钱兑换](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0322.%E9%9B%B6%E9%92%B1%E5%85%91%E6%8D%A2.md)
- [ ] 🟢 LC 279 [279.完全平方数](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0279.%E5%AE%8C%E5%85%A8%E5%B9%B3%E6%96%B9%E6%95%B0.md)
- [ ] 🟢 LC 139 [139.单词拆分](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0139.%E5%8D%95%E8%AF%8D%E6%8B%86%E5%88%86.md)
- [ ] 📖 [多重背包理论基础](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80%E5%A4%9A%E9%87%8D%E8%83%8C%E5%8C%85.md)
- [ ] 📖 [背包问题总结篇](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E8%83%8C%E5%8C%85%E6%80%BB%E7%BB%93%E7%AF%87.md)

### 打家劫舍系列

- [ ] 🟢 LC 198 [198.打家劫舍](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0198.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8D.md)
- [ ] 🟢 LC 213 [213.打家劫舍II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0213.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8DII.md)
- [ ] 🟢 LC 337 [337.打家劫舍III](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0337.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8DIII.md)

### 股票系列

- [ ] 🟢 LC 121 [121.买卖股票的最佳时机](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0121.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA.md)
- [ ] 🔁 LC 122 [122.买卖股票的最佳时机II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0122.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAII%EF%BC%88%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%EF%BC%89.md)（複習，前面章節做過）
- [ ] 🟢 LC 123 [123.买卖股票的最佳时机III](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0123.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAIII.md)
- [ ] 🟢 LC 188 [188.买卖股票的最佳时机IV](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0188.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAIV.md)
- [ ] 🟢 LC 309 [309.最佳买卖股票时机含冷冻期](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0309.%E6%9C%80%E4%BD%B3%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E6%97%B6%E6%9C%BA%E5%90%AB%E5%86%B7%E5%86%BB%E6%9C%9F.md)
- [ ] 🟢 LC 714 [714.买卖股票的最佳时机含手续费](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0714.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA%E5%90%AB%E6%89%8B%E7%BB%AD%E8%B4%B9%EF%BC%88%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%EF%BC%89.md)
- [ ] 📖 [股票系列总结篇](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92-%E8%82%A1%E7%A5%A8%E9%97%AE%E9%A2%98%E6%80%BB%E7%BB%93%E7%AF%87.md)

### 子序列系列

- [ ] 🟢 LC 300 [300.最长递增子序列](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0300.%E6%9C%80%E9%95%BF%E4%B8%8A%E5%8D%87%E5%AD%90%E5%BA%8F%E5%88%97.md)
- [ ] 🟢 LC 674 [674.最长连续递增序列](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0674.%E6%9C%80%E9%95%BF%E8%BF%9E%E7%BB%AD%E9%80%92%E5%A2%9E%E5%BA%8F%E5%88%97.md)
- [ ] 🟢 LC 718 [718.最长重复子数组](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0718.%E6%9C%80%E9%95%BF%E9%87%8D%E5%A4%8D%E5%AD%90%E6%95%B0%E7%BB%84.md)
- [ ] 🟢 LC 1143 [1143.最长公共子序列](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/1143.%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E5%BA%8F%E5%88%97.md)
- [ ] 🟢 LC 1035 [1035.不相交的线](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/1035.%E4%B8%8D%E7%9B%B8%E4%BA%A4%E7%9A%84%E7%BA%BF.md)
- [ ] 🔁 LC 53 [53.最大子序和](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0053.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C%EF%BC%88%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%EF%BC%89.md)（複習，前面章節做過）
- [ ] 🟢 LC 392 [392.判断子序列](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0392.%E5%88%A4%E6%96%AD%E5%AD%90%E5%BA%8F%E5%88%97.md)
- [ ] 🟢 LC 115 [115.不同的子序列](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0115.%E4%B8%8D%E5%90%8C%E7%9A%84%E5%AD%90%E5%BA%8F%E5%88%97.md)
- [ ] 🟢 LC 583 [583.两个字符串的删除操作](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0583.%E4%B8%A4%E4%B8%AA%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E5%88%A0%E9%99%A4%E6%93%8D%E4%BD%9C.md)
- [ ] 🟢 LC 72 [72.编辑距离](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0072.%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.md)
- [ ] 📖 [编辑距离总结篇](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E4%B8%BA%E4%BA%86%E7%BB%9D%E6%9D%80%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB%EF%BC%8C%E5%8D%A1%E5%B0%94%E5%81%9A%E4%BA%86%E4%B8%89%E6%AD%A5%E9%93%BA%E5%9E%AB.md)
- [ ] 🟢 LC 647 [647.回文子串](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0647.%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.md)
- [ ] 🟢 LC 516 [516.最长回文子序列](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0516.%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E5%BA%8F%E5%88%97.md)
- [ ] 📖 [动态规划总结篇](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E6%80%BB%E7%BB%93%E7%AF%87.md)

## 11 單調堆疊 Monotonic Stack（单调栈）

- [ ] 🟢 LC 739 [739.每日温度](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0739.%E6%AF%8F%E6%97%A5%E6%B8%A9%E5%BA%A6.md)
- [ ] 🟢 LC 496 [496.下一个更大元素I](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0496.%E4%B8%8B%E4%B8%80%E4%B8%AA%E6%9B%B4%E5%A4%A7%E5%85%83%E7%B4%A0I.md)
- [ ] 🟢 LC 503 [503.下一个更大元素II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0503.%E4%B8%8B%E4%B8%80%E4%B8%AA%E6%9B%B4%E5%A4%A7%E5%85%83%E7%B4%A0II.md)
- [ ] 🟢 LC 42 [42.接雨水](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0042.%E6%8E%A5%E9%9B%A8%E6%B0%B4.md)
- [ ] 🟢 LC 84 [84.柱状图中最大的矩形](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0084.%E6%9F%B1%E7%8A%B6%E5%9B%BE%E4%B8%AD%E6%9C%80%E5%A4%A7%E7%9A%84%E7%9F%A9%E5%BD%A2.md)

## 12 圖論 Graph（图论）

- [ ] 📖 [理论基础](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/%E5%9B%BE%E8%AE%BA%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.md)
- [ ] 📖 [深度优先搜索理论基础](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/%E5%9B%BE%E8%AE%BA%E6%B7%B1%E6%90%9C%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.md)
- [ ] 🅰️ ACM [所有可达路径](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0098.%E6%89%80%E6%9C%89%E5%8F%AF%E8%BE%BE%E8%B7%AF%E5%BE%84.md)
- [ ] 📖 [广度优先搜索理论基础](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/%E5%9B%BE%E8%AE%BA%E5%B9%BF%E6%90%9C%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.md)
- [ ] 🅰️ ACM [岛屿数量.深搜版](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0099.%E5%B2%9B%E5%B1%BF%E7%9A%84%E6%95%B0%E9%87%8F%E6%B7%B1%E6%90%9C.md)
- [ ] 🅰️ ACM [岛屿数量.广搜版](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0099.%E5%B2%9B%E5%B1%BF%E7%9A%84%E6%95%B0%E9%87%8F%E5%B9%BF%E6%90%9C.md)
- [ ] 🅰️ ACM [岛屿的最大面积](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0100.%E5%B2%9B%E5%B1%BF%E7%9A%84%E6%9C%80%E5%A4%A7%E9%9D%A2%E7%A7%AF.md)
- [ ] 🅰️ ACM [孤岛的总面积](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0101.%E5%AD%A4%E5%B2%9B%E7%9A%84%E6%80%BB%E9%9D%A2%E7%A7%AF.md)
- [ ] 🅰️ ACM [沉没孤岛](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0102.%E6%B2%89%E6%B2%A1%E5%AD%A4%E5%B2%9B.md)
- [ ] 🅰️ ACM [水流问题](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0103.%E6%B0%B4%E6%B5%81%E9%97%AE%E9%A2%98.md)
- [ ] 🅰️ ACM [建造最大岛屿](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0104.%E5%BB%BA%E9%80%A0%E6%9C%80%E5%A4%A7%E5%B2%9B%E5%B1%BF.md)
- [ ] 🅰️ ACM [岛屿的周长](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0106.%E5%B2%9B%E5%B1%BF%E7%9A%84%E5%91%A8%E9%95%BF.md)
- [ ] 🅰️ ACM [字符串接龙](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0110.%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%8E%A5%E9%BE%99.md)
- [ ] 🅰️ ACM [有向图的完全可达性](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0105.%E6%9C%89%E5%90%91%E5%9B%BE%E7%9A%84%E5%AE%8C%E5%85%A8%E5%8F%AF%E8%BE%BE%E6%80%A7.md)
- [ ] 📖 [并查集理论基础](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/%E5%9B%BE%E8%AE%BA%E5%B9%B6%E6%9F%A5%E9%9B%86%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.md)
- [ ] 🅰️ ACM [寻找存在的路径](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0107.%E5%AF%BB%E6%89%BE%E5%AD%98%E5%9C%A8%E7%9A%84%E8%B7%AF%E5%BE%84.md)
- [ ] 🅰️ ACM [冗余连接](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0108.%E5%86%97%E4%BD%99%E8%BF%9E%E6%8E%A5.md)
- [ ] 🅰️ ACM [冗余连接II](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0109.%E5%86%97%E4%BD%99%E8%BF%9E%E6%8E%A5II.md)
- [ ] 🅰️ ACM [最小生成树之prim](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0053.%E5%AF%BB%E5%AE%9D-prim.md)
- [ ] 🅰️ ACM [最小生成树之kruskal](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0053.%E5%AF%BB%E5%AE%9D-Kruskal.md)
- [ ] 🅰️ ACM [拓扑排序](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0117.%E8%BD%AF%E4%BB%B6%E6%9E%84%E5%BB%BA.md)
- [ ] 🅰️ ACM [dijkstra（朴素版）](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0047.%E5%8F%82%E4%BC%9Adijkstra%E6%9C%B4%E7%B4%A0.md)
- [ ] 🅰️ ACM [dijkstra（堆优化版）](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0047.%E5%8F%82%E4%BC%9Adijkstra%E5%A0%86.md)
- [ ] 🅰️ ACM [Bellman_ford 算法](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0094.%E5%9F%8E%E5%B8%82%E9%97%B4%E8%B4%A7%E7%89%A9%E8%BF%90%E8%BE%93I.md)
- [ ] 🅰️ ACM [Bellman_ford 队列优化算法（又名SPFA）](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0094.%E5%9F%8E%E5%B8%82%E9%97%B4%E8%B4%A7%E7%89%A9%E8%BF%90%E8%BE%93I-SPFA.md)
- [ ] 🅰️ ACM [Bellman_ford之判断负权回路](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0095.%E5%9F%8E%E5%B8%82%E9%97%B4%E8%B4%A7%E7%89%A9%E8%BF%90%E8%BE%93II.md)
- [ ] 🅰️ ACM [Bellman_ford之单源有限最短路](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0096.%E5%9F%8E%E5%B8%82%E9%97%B4%E8%B4%A7%E7%89%A9%E8%BF%90%E8%BE%93III.md)
- [ ] 🅰️ ACM [Floyd 算法](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0097.%E5%B0%8F%E6%98%8E%E9%80%9B%E5%85%AC%E5%9B%AD.md)
- [ ] 🅰️ ACM [A * 算法](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0126.%E9%AA%91%E5%A3%AB%E7%9A%84%E6%94%BB%E5%87%BBastar.md)
- [ ] 📖 [最短路算法总结篇](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/%E6%9C%80%E7%9F%AD%E8%B7%AF%E9%97%AE%E9%A2%98%E6%80%BB%E7%BB%93%E7%AF%87.md)
- [ ] 📖 [图论总结篇](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/%E5%9B%BE%E8%AE%BA%E6%80%BB%E7%BB%93%E7%AF%87.md)
