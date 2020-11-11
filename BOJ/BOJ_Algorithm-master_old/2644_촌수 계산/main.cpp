#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > adj(101);
bool isVisited[101];
int n, m;

int bfs(int x, int y) {
  queue<int> q;
  isVisited[x] = true;
  q.push(x);
  int level = -1;
  while (!q.empty()) {
    level++;
    int q_size = q.size();
    // cout << "=============level : " << level << endl;
    for (int i = 0; i < q_size; i++) {
      int v = q.front();
      q.pop();
      // cout << "node : " << v << endl;

      if (v == y) {
        // cout << "y : level " << level << endl;
        return level;
      }

      for (int j = 0; j < adj[v].size(); j++) {
        if (!isVisited[adj[v][j]]) {
          isVisited[adj[v][j]] = true;
          // cout << adj[v][j] << " push " << endl;
          q.push(adj[v][j]);
        }
      }
    }
  }

  return -1;
}


int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  int x, y, u, v;
  cin >> n >> x >> y >> m;

  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // for (size_t i = 0; i < n; i++) {
  //   cout << "i :" << i << " ";
  //   for (size_t j = 0; j < adj[i].size(); j++) {
  //     cout << adj[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  int ret = bfs(x, y);
  // int ret = bfs(4, 8);

  cout << ret << "\n";

  return 0;
}
