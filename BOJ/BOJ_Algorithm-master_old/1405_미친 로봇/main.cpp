#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, visited[30][30];
double p[4];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

double dfs(int x, int y, int cnt) {
  // cout << "x , y : " << x << ", " << y << endl;
  if (cnt == 0)
    return 1.0;
  double ret = 0.0;
  visited[x][y] = true;

  for (int i = 0; i < 4; i++) {
    int cx = x + dx[i];
    int cy = y + dy[i];
    if (visited[cx][cy])continue;

    // cout << "cx , cy : " << cx << ", " << cy << endl;
    double temp = dfs(cx, cy, cnt - 1)*p[i];
    // cout << "dfs return 값 : " << temp << endl;
    ret += temp;
    // cout << ret << endl;
  }
  visited[x][y] = false;
  // cout << "return ret : " << ret << endl;
  return ret;
}
int main() {
  // freopen("input.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 0; i < 4; i++) {
    scanf("%lf", &p[i]);
    p[i] /= 100.0;
  }
  printf("%.9lf\n", dfs(15, 15, n));
  return 0;
}
