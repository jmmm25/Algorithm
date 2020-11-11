#include <iostream>
#include <queue>
#include <cstring>

#define MAX_INF     1100000
using namespace std;

class Info {
public:
  int pos, cnt;
  Info() {};
  Info(int _pos, int _cnt):
    pos(_pos), cnt(_cnt) {};
};

int f, s, g, u, d;
queue<Info> q;
bool isVisited[MAX_INF];

void bfs() {
  Info m;
  while (!q.empty()) {
    m = q.front();
    q.pop();
    int pos, cnt;
    pos = m.pos;  cnt = m.cnt;

    if (pos == g) {
      // cout << "result : " << cnt << "\n";
      cout << cnt << "\n";
      return;
    }

    // down
    if (pos - d > 0 && !isVisited[pos-d]) {
      q.push(Info((pos - d), cnt + 1));
      isVisited[pos-d] = true;
      // cout << "push : " << pos - d << "\t" << cnt + 1 << endl;
    }

    // up
    if (pos + u <= f && !isVisited[pos+u]) {
      q.push(Info((pos + u), cnt + 1));
      isVisited[pos+u] = true;
      // cout << "push : " << pos + u << "\t" << cnt + 1 << endl;
    }
  }
}


int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  cin >> f >> s >> g >> u >> d;
  if (s == g) {
    cout << "0" << "\n";
    return 0;
  }

  q.push(Info(s, 0));
  bfs();

  if (!isVisited[g]) {
    cout << "use the stairs" << "\n";
  }

  return 0;
}
