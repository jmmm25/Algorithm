#include <iostream>
#include <queue>
using namespace std;

class info {
public:
  int pos, cnt;
  info(){};
  info(int _pos, int _cnt) :
    pos(_pos), cnt(_cnt){};
};

int N, K;
bool isVisited[200002];
queue<info> q;

void bfs() {
  while (!q.empty()) {
    info m = q.front();
    int pos, cnt;
    pos = m.pos;  cnt = m.cnt;
    isVisited[pos] = true;
    // cout << pos << ", " << cnt << " 일 때 queue pop()" << endl;
    q.pop();
    if (pos == K) {
      // cout << "result : " << cnt << "\n";
      cout << cnt << "\n";
      return;
    }
    // 걷기
    if (pos - 1 >= 0 && !isVisited[pos-1]) {
      isVisited[pos-1] = true;
      q.push(info(pos - 1, cnt+1));
      // cout << pos-1 << ", " << cnt << " 일 때 queue push()" << endl;
    }

    if (pos + 1 <= 100001 && !isVisited[pos+1]) {
      isVisited[pos+1] = true;
      q.push(info(pos + 1, cnt+1));
      // cout << pos+1 << ", " << cnt << " 일 때 queue push()" << endl;
    }

    if (pos*2 <= 100001  && !isVisited[pos*2]) {
      //순간이동
      isVisited[pos*2] = true;
      q.push(info(pos * 2, cnt+1));
      // cout << pos*2 << ", " << cnt << " 일 때 queue push()" << endl;
    }
  }
}

int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  cin >> N >> K;
  q.push(info(N, 0));
  bfs();

  return 0;
}
