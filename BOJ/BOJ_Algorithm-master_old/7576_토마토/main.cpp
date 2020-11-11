#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define MIN_INF     (-987654)
using namespace std;

class Info {
public:
  int x, y, cnt;
  Info(){};
  Info(int _x, int _y, int _cnt) :
    x(_x), y(_y), cnt(_cnt) {};
};

int n,m;
int map[1001][1001];
bool isVisited[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<Info> q;

int bfs() {
  Info info;
  int x=0, y=0, cnt=0;
  while (!q.empty()) {
    info = q.front();
    x = info.x;
    y = info.y;
    cnt = info.cnt;
    // cout << x << "," << y << ", " << cnt << " pop 되었음" << endl;
    q.pop();
    isVisited[x][y] = true;
    for (size_t i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      // cout << nx << ", " << ny << endl;
      if (nx < 0 || ny < 0 || nx >= m || ny >= n || isVisited[nx][ny] || map[nx][ny] == -1 || map[nx][ny] == 1) {
        continue;
      }
      info.x = nx;  info.y = ny;  info.cnt = cnt + 1;
      // cout << nx  << ", "  << ny << "일 때 push ,,,, cnt : " <<  cnt + 1 << endl;
      q.push(info);
      map[nx][ny] = 1;
      isVisited[nx][ny] = true;
    }
  }
  return cnt;
}

int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  int ret = MIN_INF, count = 0;
  cin >> n >> m;
  Info info;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  // 토마토가 모두 익은 상태일 때의 조건을 확인.
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] == 1 || map[i][j] == -1) {
        count++;
      }
    }
  }
  // cout << "count : "<<count << endl;
  if (count == m*n) {
    // 토마토가 모두 다 익은 상태였다면, 0 출력
    cout << "0" << "\n";
    return 0;
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] == 1 && !isVisited[i][j]) {
        q.push(Info(i,j,0));
      }
    }
  }

  ret = bfs();

  if (ret > 0) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (map[i][j] == 0) {
          cout << "-1" << "\n";
          return 0;
        }
      }
    }
  }
  cout << ret << "\n";

  return 0;
}
