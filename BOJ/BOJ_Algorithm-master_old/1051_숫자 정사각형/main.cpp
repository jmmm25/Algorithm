#include <iostream>
#include <cstring>
#include <cstdio>

#define MAX_RANGE   50
using namespace std;

int n, m;
int map[51][51];

int sol() {
  int len = 1, ret = 0;
  for (int t = 0; t < MAX_RANGE; t++) {
    bool isChecked = false;
    // cout << "t : " << t << "       ";
    // cout << "len : " << len << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        // cout << "이중 for문 (i,j) : " << i << ", " << j << endl;
        if (i+len >= n || j+len >= m) {
          // cout << "continue (i,j) : " << i << ", " << j << endl;
          continue;
        }

        if (map[i][j] == map[i][j+len] && map[i][j+len] == map[i+len][j+len] &&
          map[i+len][j+len] == map[i+len][j]) {
            // cout << "(i , j , len) : " << i << ", " << j << ", " << len << endl;
            ret = max(ret, len);
            isChecked = true;
            break;
          }
      }
      if (isChecked) {
        break;
      }
    }
    // t++ 될 때마다, 확인할 정사각형의 한 변의 길이를 늘림.
    len++;
  }

  return ret + 1;
}


int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  int ret = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d", &map[i][j]);
    }
  }

  ret = sol();
  cout << ret * ret << "\n";
  return 0;
}
