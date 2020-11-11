#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

class Info {
public:
  int x, y, cnt;
  Info() {};
  Info(int _x, int _y, int _cnt):
    x(_x), y(_y), cnt(_cnt) {}
};

int n, m;
char map[51][51];
bool isVisited[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0 ,0};

int bfs(int x, int y, int cnt) {
  int ret = -1;
  queue<Info> q;
  Info info;
  q.push(Info(x, y, cnt));

  while (!q.empty()) {
    int x, y, cnt;
    info = q.front();
    x = info.x;  y = info.y;  cnt = info.cnt;
    // cout << "x, y, cnt : " << x << ", " << y << ", " << cnt << endl;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m || isVisited[nx][ny]) {
        continue;
      }

      if (map[nx][ny] == 'W') {
        continue;
      }
      // cout << nx << ", "<< ny << ", "<< cnt+1 << endl;
      q.push(Info(nx, ny, cnt+1));
      isVisited[nx][ny] = true;
    }
    ret = cnt;
  }
  // cout << "queue : "<< ret << endl;
  return ret;
}

int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  cin >> n >> m;
  int ret = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 'L') {
        // cout << "i, j  : " << i <<", " << j <<" bfs go go " << endl;
        ret = max(ret, bfs(i, j, 0));
        memset(isVisited, false, sizeof(isVisited));
      }
    }
  }

  cout << ret << "\n";
  return 0;
}
