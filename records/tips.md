# 學習 Tips

> 規則：先用自己的方式寫完、測試 PASS，再回來看「更好的寫法」。
> 寫的過程中學到的語法 / 觀念記在「學到的事」；「更好的寫法」等完成後導師才補上。

## 查文件去哪裡

| 想做什麼 | 去哪裡 |
|---|---|
| 這一題的語法 | 該題的 `notes.md`「語法速查」 |
| 第一次學某個語法（教學） | [learncpp.com](https://www.learncpp.com/)（英文，有範例和練習） |
| 想看中文 | [Microsoft Learn C++（zh-tw）](https://learn.microsoft.com/zh-tw/cpp/cpp/cpp-language-reference) |
| 查函式 / 容器的精確規格 | [cppreference](https://en.cppreference.com/)（忽略標 `(since C++20)` 以後的東西） |

---

## 001 Task A-1 `print1To10()`

- 日期：2026-10-12
- 我的拆解：陣列、迴圈、print、空白、換行
- 第一版想法：先把要印的東西全部放進一個陣列，再用 for 迴圈依序印出
- 實際寫法（看到 Copilot 提示後調整）：`for` 從 1 到 10，每次 `cout << i`，`i < 10` 時多印一個空白，迴圈結束後換行
- 結果：2026-10-12 PASS

### 學到的事

- C++ 的 `vector` / 陣列只能放**同一種型別**，不能像 JS / Python 那樣把 `1` 和 `" "` 混在一起
- `""` 是空字串（長度 0），`" "` 才是一個空白字元
- `cout` 不會自動加空白或換行，要印什麼就得自己寫出來；換行用 `cout << "\n";`
- `v.size()` 回傳無號整數 `size_t`，迴圈變數也用 `size_t`，避免 signed / unsigned 比較的 warning
- `cout` 是 `<iostream>` 裡的標準輸出物件（`std::cout`），`<<` 把右邊的值送進去，可以一直串接
- Python 的 `print(x)` 預設會在結尾加換行（`end="\n"`）；C++ 的 `cout << x` 只印 `x`，比較像 `print(x, end="")`
  → 在迴圈裡用 Python 那種 `print` 會變成一行一個數字，所以換行要放在迴圈**外面**、只印一次

### 更好的寫法（完成後再補）

- （待完成）
