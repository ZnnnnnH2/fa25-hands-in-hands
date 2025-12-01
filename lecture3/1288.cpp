#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// - 六边形有 6 条边，编号 0..5（从上面开始顺时针数）。
// - 每条边可能有水渠，也可能没有；有水渠就能和邻居传水。
// - 可以把一个格子整体旋转，相当于把 6 条边的水渠位置循环移动。
// - 目标：从“水源格子”把水顺着水渠传到“生命之树格子”。
//
// - 题目保证有解，所以找到第一条路就行。
// - 用 DFS 找路：走到一个格子时，先把它旋到能接上“来水”的那条边，再看看还能往哪些邻居继续流。
// - 一个六边形旋 6 次又回到原样，所以只需要尝试 0..5 次逆时针旋转这 6 个状态。
// - 记录下每个格子需要旋转多少次。旋转方向统一输出 L（逆时针）；如果想顺时针 k 次，就是逆时针 (6-k) 次。

const int kMaxCells = 2005;

struct Cell {
  int neighbor[6];   // 邻居格子 id（0 表示无邻居）
  bool hasPipe[6];   // 本格子某个方向是否有水渠

  // 逆时针旋转一次（边 0->5，1->0 ...）
  void RotateLeft() {
    bool first = hasPipe[0];
    for (int i = 0; i < 5; ++i) hasPipe[i] = hasPipe[i + 1];
    hasPipe[5] = first;
  }

  // 逆时针旋转指定次数（只关心 times % 6）
  void RotateLeft(int times) {
    times %= 6;
    if (times == 0) return;
    bool rotated[6];
    for (int i = 0; i < 6; ++i) rotated[i] = hasPipe[(i + times) % 6];
    for (int i = 0; i < 6; ++i) hasPipe[i] = rotated[i];
  }
};

vector<Cell> board;                  // 1-indexed
bool visited[kMaxCells];             // DFS 标记
vector<pair<int, int>> operations;   // (cellId, rotateTimes) 方向统一用 L
int cellCount;
int sourceId;
int treeId;

// DFS：一边找路一边记下当前格子要旋几次才能接上父亲
// currentDirFromParent 表示“水是从父亲的哪条边流出来的”（-1 说明这是起点）
// 六边形对边相差 3，所以水进入当前格子的边 = (currentDirFromParent + 3) % 6
void Dfs(int cellId, int currentDirFromParent = -1) {
  if (cellId == treeId) {
    int needConnectDir = (currentDirFromParent + 3) % 6;  // 进入树的方向
    int rotateTimes = 0;
    // 把树格旋到能接上来水的方向（最多 6 次就会回到原样）
    while (rotateTimes < 6 && !board[cellId].hasPipe[needConnectDir]) {
      board[cellId].RotateLeft();
      ++rotateTimes;
    }
    operations.push_back({cellId, rotateTimes});

    cout << operations.size() << "\n";
    for (auto [id, times] : operations) cout << id << " L " << times << "\n";
    exit(0);  // 题目保证有解，找到即可退出
  }

  int needConnectDir = (currentDirFromParent + 3) % 6;  // 父->子方向的对边
  int rotateTimes = 0;

  // 尝试当前格子的 6 种旋转状态
  for (; rotateTimes < 6;) {
    // 先旋到能接上父亲的位置（起点没有父亲就不用管）
    while (currentDirFromParent != -1 && rotateTimes < 6 &&
           !board[cellId].hasPipe[needConnectDir]) {
      board[cellId].RotateLeft();
      ++rotateTimes;
    }
    if (rotateTimes >= 6) break;

    // 在当前状态下，看看水能不能往别的邻居流
    for (int dir = 0; dir < 6; ++dir) {
      if (board[cellId].hasPipe[dir] && board[cellId].neighbor[dir] > 0) {
        int nextId = board[cellId].neighbor[dir];
        if (!visited[nextId]) {
          visited[nextId] = true;
          // 记录：这个格子从初始状态逆时针转了多少次
          if (rotateTimes != 0) operations.push_back({cellId, rotateTimes});

          Dfs(nextId, dir);  // dir 是当前格子出水方向

          if (rotateTimes != 0) operations.pop_back();
          visited[nextId] = false;
        }
      }
    }

    board[cellId].RotateLeft();
    ++rotateTimes;
  }

  // 恢复到初始朝向，方便回溯
  for (; rotateTimes % 6 != 0; ++rotateTimes) board[cellId].RotateLeft();
}

int main() {
  freopen("input.txt", "r", stdin);  // 本地调试可用，在线评测可注释掉
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> cellCount;
  board.reserve(cellCount + 1);
  operations.reserve(cellCount);

  board.push_back(Cell());  // 让下标从 1 开始，0 号不用
  for (int id = 1; id <= cellCount; ++id) {
    int type;
    cin >> type;
    if (type == 0) sourceId = id;
    if (type == 2) treeId = id;

    Cell cell;
    for (int d = 0; d < 6; ++d) cin >> cell.neighbor[d];
    for (int d = 0; d < 6; ++d) cin >> cell.hasPipe[d];
    board.push_back(cell);
  }

  visited[sourceId] = true;
  Dfs(sourceId);
  return 0;
}
