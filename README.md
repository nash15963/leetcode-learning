# LeetCode C++ 練習紀錄

用 C++ 刷 LeetCode 的學習紀錄。先用 17 題前置練習建立 C++ 語感，再沿著 [代码随想录](https://github.com/youngyangyang04/leetcode-master) 的地圖系統化刷題；Claude Code 在這個專案裡擔任程式導師（規則見 [CLAUDE.md](CLAUDE.md)）。

## 學習路線

```
前置 A：C++ 語言練習（cpp-basics/001–012，每題 4–5 個子任務）
   Stage A 基礎語法   001 I/O 與流程控制 → 002 函式與參考 → 003 字串與字元
   Stage B 容器演算法 004 vector → 005 STL 演算法 → 006 雜湊容器 → 007 stack/queue/heap
   Stage C 抽象記憶體 008 lambda → 009 struct/class → 010 鏈結串列 → 011 樹與遞迴 → 012 數值/位元/template
        │
        ▼
前置 B：LeetCode 實戰（questions/013–017）
   #1 Two Sum → #20 Valid Parentheses → #49 Group Anagrams → #206 Reverse Linked List → #102 Level Order
        │
        ▼
主線：代码随想录（records/roadmap.md，questions/018 之後）
   陣列 → 鏈結串列 → 雜湊表 → 字串 → 雙指標 → 堆疊佇列 → 二元樹 → 回溯 → 貪婪 → 動態規劃 → 單調堆疊 → 圖論
```

整個過程搭配**間隔重做**（+1 / +3 / +7 / +14 / +30 天），把寫過的題目變成肌肉記憶。

## 快速開始

```bash
make env          # 確認編譯器：Apple clang 14、__cplusplus = 202002
make run Q=001    # 編譯並執行第 001 題的測試
```

1. 讀 `cpp-basics/001-io-control-flow/notes.md`（概念）和 `question.md`（題目）
2. 在 `main.cpp` 的 `// TODO` 處實作
3. `make run Q=001`，直到全部 ✅ PASS
4. 在 Claude Code 輸入 `/check 001` 請導師 review，並自動更新紀錄

在 VS Code 裡打開任一 `main.cpp`，按 `⇧⌘B` 會執行目前這一題；按 `F5` 可以下中斷點除錯。

## 常用指令

| 指令 | 說明 |
|---|---|
| `make run Q=NNN` | 編譯並執行測試（開啟 AddressSanitizer + UndefinedBehaviorSanitizer） |
| `make build Q=NNN` | 只編譯 |
| `make redo Q=NNN` | 重做：備份目前答案到 `tmp/redo/`，`main.cpp` 還原成最初 commit 的 stub |
| `make env` | 顯示編譯器版本與 C++ 標準 |
| `make clean` | 清除編譯產物 |

## Claude Code Skills

| Skill | 用途 |
|---|---|
| `/today` | 今天要做什麼：到期的重做題、進行中的題目、下一題、整體進度 |
| `/new-question next` | 依地圖建立下一題（也可以指定題號：`/new-question 704`） |
| `/hint NNN` | 分級提示：L1 方向 → L2 工具 → L3 虛擬碼，不直接給答案 |
| `/check NNN` | 跑測試 + 導師 review + 更新 `records/` |

## 專案結構

```
.
├── CLAUDE.md               導師規則與專案慣例
├── Makefile                建置 / 執行 / 重做
├── cpp-basics/             001–012 C++ 語言練習（notes.md、question.md、main.cpp）
├── questions/              013 之後的 LeetCode 題（question.md、main.cpp）
├── include/lc/
│   ├── test.hpp            迷你測試框架（CHECK / CHECK_EQ / capture）
│   └── structures.hpp      LeetCode 的 ListNode / TreeNode 與建構工具
├── records/
│   ├── progress.md         進度總表
│   ├── roadmap.md          代码随想录刷題地圖（checklist）
│   ├── review-queue.md     間隔重做排程
│   └── mistakes.md         C++ 錯誤本
├── .claude/skills/         Claude Code skills（skills/ 是它的 symlink）
├── .vscode/                clangd、CodeLLDB 設定
└── tmp/                    草稿與編譯產物（不進 git）
```

## 開發環境

| 項目 | 設定 |
|---|---|
| 編譯器 | Apple clang 14（Xcode Command Line Tools 內建） |
| C++ 標準 | `-std=c++20`（練習內容只用 C++17 等級的基礎語法） |
| 檢查 | `-Wall -Wextra -Wpedantic -Wshadow`、`-fsanitize=address,undefined` |
| 編輯器 | VS Code + [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd) + [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb) |

> 本機沒有 `<bits/stdc++.h>`，請自己寫需要的 `#include`（也是練習的一部分）。
> 之後如果要升級編譯器（例如 `brew install llvm`），只需要改 `Makefile` 的 `CXX` 和 `.vscode/settings.json` 的 `clangd.path`。

## 參考資源

- [代码随想录 leetcode-master](https://github.com/youngyangyang04/leetcode-master)：刷題地圖與 C++ 題解
- [Hello 算法](https://github.com/krahets/hello-algo)：資料結構圖解教科書（有繁體中文版），概念不熟時查閱
- [cppreference](https://en.cppreference.com/)：C++ 標準函式庫查詢
