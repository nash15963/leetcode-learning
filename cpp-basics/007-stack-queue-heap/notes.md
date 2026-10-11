# 007 · 堆疊、佇列、雙端佇列、優先佇列（`stack` / `queue` / `deque` / `priority_queue`）

## 這一課學什麼

- `stack`（堆疊，後進先出 LIFO）：`push` / `top` / `pop`
- `queue`（佇列，先進先出 FIFO）：`push` / `front` / `pop`
- `deque`（雙端佇列）：兩頭都能進出，還能用 `[]` 存取，是「單調佇列」的基礎
- `priority_queue`（優先佇列 = heap 堆積）：預設是 **max-heap**，`greater<int>` 變 min-heap
- 用 lambda 自訂 `priority_queue` 的比較方式（pair 放進 heap）
- 這幾個（除了 deque）都是 container adapter：**不能走訪、沒有 `begin()`**

## 語法速查

```cpp
#include <deque>
#include <functional>  // greater
#include <queue>       // queue、priority_queue 都在這
#include <stack>
using namespace std;

// ---- stack ----
stack<int> st;
st.push(1); st.push(2);
int t = st.top();      // 2（只看不拿）
st.pop();              // 拿掉 2；pop() 回傳 void
bool e = st.empty();   // 先檢查再 top / pop

// ---- queue ----
queue<int> q;
q.push(1); q.push(2);
int f = q.front();     // 1（最早進來的）；queue 沒有 top()
int b = q.back();      // 2
q.pop();               // 拿掉 1

// ---- deque ----
deque<int> dq;
dq.push_back(3); dq.push_front(1);  // {1, 3}
dq.pop_back(); dq.pop_front();
// dq.front() / dq.back() / dq[i] / dq.size()

// ---- priority_queue ----
priority_queue<int> maxHeap;                             // top 是最大值
priority_queue<int, vector<int>, greater<int>> minHeap;  // top 是最小值（三個樣板參數都要寫）
maxHeap.push(5); maxHeap.push(9);
int big = maxHeap.top();   // 9
maxHeap.pop();
vector<int> v = {3, 1, 4};
priority_queue<int> fromVec(v.begin(), v.end());         // 一次建好，O(n)

// ---- pair 放進 heap：預設先比 first，再比 second ----
priority_queue<pair<int, int>> pq;   // (頻率, 數值)，top 是頻率最大的

// ---- 自訂比較：lambda + decltype（lambda 的細節見 008）----
auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;        // 回傳 true 代表 a 的優先權「比較低」→ 這是 min-heap
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> custom(cmp);
```

### 複雜度

| 容器 | 操作 | 時間 |
|---|---|---|
| `stack` / `queue` | `push` / `pop` / `top` / `front` | O(1) |
| `deque` | 兩端 `push_*` / `pop_*`、`[]` | O(1) |
| `priority_queue` | `push` / `pop` | O(log n) |
| `priority_queue` | `top` | O(1) |
| `priority_queue` | 用區間建構 | O(n) |

## 常見坑

1. **空的時候 `top()` / `pop()` / `front()`**：未定義行為，常見直接 crash

   ```cpp
   st.pop();                       // ❌ st 可能是空的
   if (!st.empty()) st.pop();      // ✅
   ```

2. **以為 `pop()` 會回傳值**

   ```cpp
   int bad = st.pop();             // ❌ 編譯錯誤：pop() 回傳 void
   int good = st.top(); st.pop();  // ✅ 先 top 再 pop
   ```

3. **RPN 運算元順序弄反**：先 pop 出來的是「右邊」的數

   ```cpp
   int a = st.top(); st.pop();     // ❌ 5 3 - 會算成 3 - 5
   int b = st.top(); st.pop();
   int rhs = st.top(); st.pop();   // ✅ 先拿到的是右運算元
   int lhs = st.top(); st.pop();   //    結果 = lhs - rhs
   ```

4. **把負數 token 當成運算子**

   ```cpp
   if (t[0] == '-') { }            // ❌ "-3" 也會進來
   if (t == "-") { }               // ✅ 整個字串比對
   ```

5. **min-heap 寫法**：樣板參數要的是「型別」，不能加括號；而且三個參數都要寫

   ```cpp
   priority_queue<int, greater<int>> bad1;                 // ❌ 第二個參數是底層容器
   priority_queue<int, vector<int>, greater<int>()> bad2;  // ❌ greater<int>() 是物件不是型別
   priority_queue<int, vector<int>, greater<int>> good;    // ✅
   ```

6. **比較函式的方向和 `sort` 相反**：`sort` 用 `greater` 是由大到小；`priority_queue` 用 `greater` 卻是 **min-heap**。記法：comparator 回傳 `true` 代表「a 排在 b 後面 → 比較晚被 pop」。

7. **自訂 lambda 比較時忘了把 `cmp` 傳給建構子**：C++17 的 lambda 不能預設建構（C++20 起沒有 capture 的才可以），一律寫 `(cmp)` 最保險。

   ```cpp
   priority_queue<T, vector<T>, decltype(cmp)> bad;        // ❌ C++17 編譯錯誤
   priority_queue<T, vector<T>, decltype(cmp)> good(cmp);  // ✅ 各版本都能編譯
   ```

8. **滑動視窗的 deque 存「值」**：無法判斷最前面的元素是否已經滑出視窗

   ```cpp
   dq.push_back(nums[i]);   // ❌ 不知道它是第幾個
   dq.push_back(i);         // ✅ 存索引，用 nums[dq.front()] 取值，用 dq.front() <= i - k 判斷過期
   ```

## 在 LeetCode 會怎麼用

- `stack`：運算式計算、單調堆疊（下一個更大元素、每日溫度）、用迴圈模擬遞迴。
- `queue`：BFS（樹的層序走訪、網格最短路徑）、模擬排隊、計數器。
- `deque`：滑動視窗最大／最小值（單調佇列），也可以同時當 stack 和 queue 用。
- `priority_queue`：第 k 大、top-k 頻率、合併 k 個排序串列、Dijkstra 最短路徑。
- 小技巧：只想要「頻率大的優先，數值小的優先」時，可以把 `(freq, -val)` 放進預設的 max-heap，就不用自訂比較。

## 參考

- [std::stack](https://en.cppreference.com/w/cpp/container/stack)
- [std::queue](https://en.cppreference.com/w/cpp/container/queue)
- [std::deque](https://en.cppreference.com/w/cpp/container/deque)
- [std::priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue)
- [std::greater](https://en.cppreference.com/w/cpp/utility/functional/greater)
