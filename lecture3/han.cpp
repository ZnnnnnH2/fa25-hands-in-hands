#include <bits/stdc++.h>
using namespace std;

// 递归函数：打印从 from 到 to 的移动步骤，借助 aux 作为辅助柱子
void hanoi(int n, char from, char aux, char to, unsigned long long& step_count) {
  if (n <= 0) return;  // 没有盘子，无动作
  if (n == 1) {
    // 直接将一个盘子从 from 移动到 to
    step_count++;
    cout << "Move disk 1 from " << from << " to " << to << '\n';
    return;
  }
  // 1) 把 n-1 个盘子从 from 移到 aux（把 to 当作辅助）
  hanoi(n - 1, from, to, aux, step_count);
  // 2) 把第 n 个盘子从 from 移到 to
  step_count++;
  cout << "Move disk " << n << " from " << from << " to " << to << '\n';
  // 3) 把 n-1 个盘子从 aux 移到 to（把 from 当作辅助）
  hanoi(n - 1, aux, from, to, step_count);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // 读取盘子数 n
  long long n;
  cin >> n;
  unsigned long long step_count = 0;

  hanoi((int)n, 'A', 'B', 'C', step_count);

  cout << "Total moves: " << step_count << '\n';

  return 0;
}
