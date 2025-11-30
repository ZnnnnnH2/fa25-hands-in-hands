#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef int* intt;
typedef char* charr;

const int inf = 0x3f3f3f3f;
const int N = 2005;

struct node {
  int neighbor[6];
  bool connect[6];
  void lRotation() {
    bool t_connect = connect[0];
    for (int i = 0; i < 5; i++) {
      connect[i] = connect[i + 1];
    }
    connect[5] = t_connect;
  }
  void lRotation(int times) {
    times %= 6;
    bool t_connect[6];
    for (int i = 0; i < 6; i++) {
      t_connect[i] = connect[(i + times) % 6];
    }
    for (int i = 0; i < 6; i++) {
      connect[i] = t_connect[i];
    }
  }
  void rRotation() {
    bool t_connect = connect[5];
    for (int i = 5; i > 0; i--) {
      connect[i] = connect[i - 1];
    }
    connect[0] = t_connect;
  }
};
vector<node> graph;
int n;
int waterIndex;
int treeIndex;
bool visited[N];
vector<pair<int, int>> path;
void dfs(int currentIndex, int prevIndex = -1) {
  if (currentIndex == treeIndex) {
    int prevDir = 0;
    while (graph[currentIndex].neighbor[prevDir] != prevIndex) {  // 找到父亲的方位
      prevDir++;
    }
    int i = 0;
    while (prevIndex != -1 and i < 6 and !graph[currentIndex].connect[prevDir]) {  // 联通父节点
      graph[currentIndex].lRotation();
      i++;
    }
    path.push_back({currentIndex, i});
    cout << path.size() << endl;
    for (auto p : path) {
      cout << p.first << " L " << p.second << endl;
    }
    exit(0);
  }
  int prevDir = 0;
  if (prevIndex != -1) {
    while (graph[currentIndex].neighbor[prevDir] != prevIndex) {  // 找到父亲的方位
      prevDir++;
    }
  }
  int i = 0;
  for (; i < 6;) {                                                                 // for 选择 in 选择列表:
    while (prevIndex != -1 and i < 6 and !graph[currentIndex].connect[prevDir]) {  // 联通父节点
      graph[currentIndex].lRotation();
      i++;
    }
    if (i >= 6) break;
    for (int j = 0; j < 6; j++) {                                                                                                     // 遍历邻居
      if (graph[currentIndex].connect[j] and graph[currentIndex].neighbor[j] > 0 and graph[currentIndex].neighbor[j] != prevIndex) {  // 查找连接
        int nextIndex = graph[currentIndex].neighbor[j];
        if (!visited[nextIndex]) {
          visited[nextIndex] = true;  //选择该邻居
          if (i != 0)
            path.push_back({currentIndex, i});
          dfs(nextIndex, currentIndex);  // 继续查找
          if (i != 0)
            path.pop_back();  //回溯
          visited[nextIndex] = false;
        }
      }
    }
    graph[currentIndex].lRotation();
    i++;
  }
  for (; i % 6 != 0; i++) {  // 恢复原状
    graph[currentIndex].lRotation();
  }
}
int main() {
  // freopen("input.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  graph.reserve(n + 1);
  path.reserve(n);
  node tmp;
  graph.push_back(tmp);  // 下标从1开始
  for (int i = 1; i <= n; i++) {
    int op;
    cin >> op;
    switch (op) {
      case 0:
        waterIndex = i;
        break;
      case 2:
        treeIndex = i;
        break;
    }
    node t;
    for (int j = 0; j < 6; j++) {
      cin >> t.neighbor[j];
    }
    for (int j = 0; j < 6; j++) {
      cin >> t.connect[j];
    }
    graph.push_back(t);
  }
  visited[waterIndex] = true;
  dfs(waterIndex);
  return 0;
}