#include<iostream>
#include<queue>
using namespace std;

struct Info{
  int x;  int y;  int cnt;
};

int N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char map[101][101];
bool isVisited[101][101];
queue<Info> q;

int bfs(int x, int y, int cnt) {
  Info info;
  info.x = x;
  info.y = y;
  info.cnt = cnt;
  q.push(info);
  isVisited[x][y] = true;

  while (!q.empty()) {
    info = q.front();
    x = info.x; y = info.y; cnt = info.cnt;
    q.pop();
    // cout << "queue pop  !!!!! " <<"(x, y, cnt) = " << x <<  " " << y << " " << cnt << endl;
    if (x == N-1 && y == M-1) {
      // cout << "result : " << cnt << endl;
      return cnt;
    }

    for (size_t i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      // cout << "nx, ny : " << nx << " " << ny << endl;
      if (nx < 0 || ny < 0 || nx >= N || ny >= M || isVisited[nx][ny] || map[nx][ny] == '0') {
        continue;
      }

      info.x = nx;  info.y = ny; info.cnt = cnt + 1;
      // cout << "nx, ny     push : " << nx << " " << ny << endl;
      q.push(info);
      isVisited[nx][ny] = true;
    }
  }

  return 0;
}


int main(int argc, char *argv[]) {
  // freopen("input.txt", "r", stdin);
  // freopen("input2.txt", "r", stdin);
  int ret = 1;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
    }
  }

  ret = bfs(0, 0 , ret);
  cout << ret << "\n";
  return 0;
}
