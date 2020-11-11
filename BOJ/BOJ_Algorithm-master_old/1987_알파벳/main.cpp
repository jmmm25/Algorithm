#include <iostream>
#include <vector>

using namespace std;

// class Info {
// public:
//   int x, y, cnt;
//   Info() {};
//   Info(int _x, int _y, int _cnt) :
//     x(_x), y(_y), cnt(_cnt) {};
// };

int r, c, ret = 1;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
char map[22][22];
// bool isVisited[22][22];
vector<pair<char, bool> > isChecked;

void dfs(int x, int y, int cnt) {
  if (cnt > ret) {
    ret = cnt;
  }
  int j = 0;
  for (int i = 0; i < isChecked.size(); i++) {
    if (isChecked[i].first == map[x][y]) {
      isChecked[i].second = true;
      j = i;
      break;
    }
  }
  // cout << "ch : " << map[x][y] << ", " << "Check : " << isChecked[j].second << endl;
  for (int i = 0; i < 4; i++) {
    bool flag = false;
    int nx = x + dx[i];
    int ny = y + dy[i];

    // cout << "nx, ny : " << nx << ", " << ny << "일 때 --> " ;
    if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
      // cout << "first continue " << endl;
      continue;
    }

    for (int i = 0; i < isChecked.size(); i++) {
      if (isChecked[i].first == map[nx][ny] && isChecked[i].second) {
        // cout << "isChecked.first : " << isChecked[i].first << "     " << "flag 변경 전 : " << flag;
        flag = true;
        // cout << " -- >   flag 변경 후 " << flag << endl;
        break;
      }
    }
    if (!flag) {
      // cout << "nx , ny " << map[nx][ny] << "    dfs go     : " << cnt+1 << endl;
      dfs(nx, ny, cnt + 1);
      for (int i = 0; i < isChecked.size(); i++) {
        if (isChecked[i].first == map[nx][ny] && isChecked[i].second) {
          // cout << isChecked[i].first << ", " << isChecked[i].second << "   ->  " <<  " false 변경 " << endl;
          isChecked[i].second = false;
          break;
        }
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  // freopen("input0.txt", "r", stdin);
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> map[i][j];
    }
  }
  for (int i = 0; i < 26; i++) {
    char c = 65 + i;
    isChecked.push_back(make_pair(c, false));
  }

  // for (int i = 0; i < isChecked.size(); i++) {
  //   cout << isChecked[i].first << ", " << isChecked[i].second << endl;
  // }

  // cout << map[0][0] << "   dfs go " << 1 << endl;
  dfs(0, 0, 1);

  // 말이 지나는 칸은 좌측 상단의 칸도 포함된다.
  cout << ret << "\n";

  return 0;
}
