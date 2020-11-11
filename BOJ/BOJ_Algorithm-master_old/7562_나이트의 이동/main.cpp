#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

class Info{
public:
  int x, y, cnt;
  Info() {};
  Info(int _x, int _y, int _cnt) :
    x(_x), y(_y), cnt(_cnt){};
};

int l;
bool isVisited[301][301];
int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };
int cur_x, cur_y, move_x, move_y;

int bfs(int cur_x, int cur_y, int cnt) {
  queue<Info> q;
  Info info;
  q.push(Info(cur_x, cur_y, cnt));
  isVisited[cur_x][cur_y] = true;

  while (!q.empty()) {
    info = q.front();
    int x = info.x;
    int y = info.y;
    int cnt = info.cnt;
    q.pop();
    if (x == move_x && y == move_y) {
      return cnt;
    }

    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= l || ny >= l || isVisited[nx][ny]) {
        continue;
      }
      isVisited[nx][ny] = true;
      q.push(Info(nx, ny, cnt+1));
    }
  }

  return 0;
}

int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  int tc = 0;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    int ret = 0;
    cin >> l >> cur_x >> cur_y >> move_x >> move_y;
    // q.push(make_pair(cur_x, cur_y));
    ret = bfs(cur_x, cur_y, 0);
    memset(isVisited, false, sizeof(isVisited));
    cout << ret << "\n";
  }
  return 0;
}
