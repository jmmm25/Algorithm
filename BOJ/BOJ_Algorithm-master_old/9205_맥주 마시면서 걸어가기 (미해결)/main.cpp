#include <iostream>
#include <queue>
#include <cstring>

#define SANG_GEUN   1
#define CONVENIENCE   2
#define FESTIVAL    3

using namespace std;

class Info {
public:
  int x, y, cnt;
  Info() {};
  Info(int _x, int _y, int _cnt) :
    x(_x), y(_y), cnt(_cnt) {};
};

// 상근이네 1, 편의점 2, 락페스티벌 3
int map[32767][32767];
int n, sx, sy, px, py, lx, ly;
bool isVisited[32767][32767];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0 ,0};

int bfs(int sx, int sy, int scnt) {
  queue<Info> q;
  Info m;
  int x = -1, y = -1, cnt = -1;
  q.push(Info(sx, sy, scnt));

  while (!q.empty()) {
    m = q.front();
    q.pop();
    x = m.x;  y = m.y;  cnt = m.cnt;

    for (size_t i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= 32767 || ny >= 32767) {
        continue;
      }

      if (nx ) {
        /* code */
      }

    }

  }

  return 0;
}

int main(int argc, char const *argv[]) {
  freopen("input.txt", "r", stdin);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> sx >> sy;
    map[sx][sy] = SANG_GEUN;
    for (int i = 0; i < n; i++) {
      cin >> px >> py;
      map[px][py] = CONVENIENCE;
    }
    cin >> lx >> ly;
    map[lx][ly] = FESTIVAL;
    bfs(sx, sy, 20);
  }


  return 0;
}
