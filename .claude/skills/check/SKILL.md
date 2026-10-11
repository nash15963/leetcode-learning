---
name: check
description: 編譯並執行某題的測試，以導師角度 review 使用者的解答，並更新 records/。使用者說「幫我檢查」「我寫完了」「看一下我的 code」時使用。
argument-hint: "[NNN]"
---

# 檢查與 Review

參數：`$ARGUMENTS` = 三位數題號。空白時用 `records/progress.md` 裡最後一個 🟡 進行中的題目。

## 步驟

1. 在 repo 根目錄執行 `make run Q=NNN`，讀完整輸出。
2. **編譯錯誤 / sanitizer 報告**：
   - 指出關鍵訊息：哪一行、哪種錯誤（例如 `heap-buffer-overflow`、`signed integer overflow`）
   - 解釋原因和檢查方向；**不要直接給修正後的程式碼**，除非使用者要求
3. **測試沒有全過**：
   - 指出哪個 case 失敗、expected 和 actual 的差異
   - 用提問或反例引導（「如果輸入是空陣列，你的迴圈會怎麼跑？」），不要直接給答案
4. **全部 PASS**：依 `CLAUDE.md` 的 Review 重點做 review，格式：
   ```
   ## ✅ 做得好
   ## 🔍 可以更好（複雜度 / C++ 寫法 / 可讀性）
   ## 📚 延伸（follow-up、相關題目）
   ```
   - cpp-basics 練習題：特別注意 C++ 用法是否道地，對照該題 `notes.md` 的「常見坑」
   - LeetCode 題：問使用者時間 / 空間複雜度，讓他先回答再確認
5. **更新 records/**（日期用 `date +%F`）：
   - `progress.md`：嘗試次數 +1；全部 PASS 時狀態改 ✅ 並填首次完成日（已有日期就不改）；用過提示就在備註記錄
   - 全部 PASS 時：
     - `roadmap.md`：如果是地圖上的題目，`[ ]` → `[x]`
     - `review-queue.md`：第一次完成 → 新增一列（下一輪 = 1、下次日期 = 今天 + 1）；重做完成 → 依規則推進（+3/+7/+14/+30）或重置回 +1；第 5 輪完成就移到「已畢業」
   - `mistakes.md`：這次發現的錯誤新增一筆，並更新分類次數（同類第二次出現標 ⚠️）
6. 最後建議 commit message（例如 `solve 013-two-sum`），詢問使用者要不要 commit；不要自動 commit。
