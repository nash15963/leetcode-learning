---
name: new-question
description: 建立新的 LeetCode 練習題目錄 questions/NNN-slug/（question.md + 含測試的 main.cpp stub）。使用者說「下一題」「開新題」「開一題 LC 704」時使用。
argument-hint: "[next | LeetCode 題號]"
---

# 建立新題目

參數：`$ARGUMENTS`（空白或 `next` = 依地圖取下一題；數字 = 指定 LeetCode 題號）

## 步驟

1. **決定題目**
   - `next`：讀 `records/roadmap.md`，由上往下找第一個未打勾的項目：
     - 📖 閱讀：提醒使用者先讀（附連結），讀完可以打勾，再繼續往下找題目
     - ⭐ 已在前置練習做過：直接打勾、跳過
     - 🅰️ ACM：預設跳過，除非使用者想做
     - 🟢 / 🔁：就是這一題
   - 前置練習 001–017 還沒全部完成時，先提醒使用者（但使用者堅持就照做）
   - 題號：直接用該題；已經存在於 `questions/` 就告訴使用者位置，不重複建立
2. **取得題目資訊**：題名、難度、主題、函式簽名、範例、限制。可以讀 roadmap 連結的代码随想录題解（改用 `raw.githubusercontent.com` 讀 md）取得 LeetCode 連結和題意，但**不要把解法寫進 question.md**
3. **編號**：`questions/` 中最大流水號 + 1；slug = LeetCode 英文題名的 kebab-case
4. **建立 `question.md`**：照 `questions/013-two-sum/question.md` 的格式，題目用自己的話摘要
5. **建立 `main.cpp`**：照 `questions/013-two-sum/main.cpp`（陣列題）、`016-reverse-linked-list/main.cpp`（鏈結串列）、`017-binary-tree-level-order-traversal/main.cpp`（樹）的格式；範例 + 至少 3 個邊界測試
6. **驗證**
   - 在 **repo 外**的暫存目錄（`mktemp -d`）寫參考解，複製同一份測試，在 repo 根目錄執行 `make run DIR=<暫存目錄>` 確認全部 PASS；參考解不要給使用者看
   - `make run Q=NNN` 確認 stub 零 warning、沒有 sanitizer 報告、測試是 FAIL
7. **更新紀錄**：在 `records/progress.md` 的「主線」表格新增一列，狀態 🟡
8. **回報**（簡短）：題目名稱與連結、檔案位置、執行指令 `make run Q=NNN`，提醒卡住時可以用 `/hint NNN`
   - 建議先 commit stub（之後 `make redo` 才能還原）：`git add questions/NNN-slug records/ && git commit -m "add NNN-slug"`，詢問使用者要不要由你執行
