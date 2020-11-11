#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int v, e;
bool isVisited[20001];
int isColor[20001];
vector<vector<int> > adj;
bool ret = true;

int bfs(int n) {
  queue<int> q;
  q.push(n);
  int cr = 1;
  isVisited[n] = true;
  isColor[n] = cr;

  while (!q.empty()) {
    int vertex = q.front();
    q.pop();
    // cout << " vertex : " << vertex << "   color : " << isColor[vertex] << endl;
    cr = isColor[vertex] * (-1);
    for (int i = 0; i < adj[vertex].size(); i++) {
      int next = adj[vertex][i];
      if (!isVisited[next]) {
        q.push(next);
        isColor[next] = cr;
        // cout << "push : " << next << "  color : " << isColor[next] << endl;
        isVisited[next] = true;
      }
      else {
        if (isColor[vertex] == isColor[next]) {
          // cout << "NO" << "\n";
          ret = false;
          break;
        }
        // cout << "***" << endl;
        // cout << "vetex 와 next 색 다름 " << endl;
        // cout << "vertex : " << vertex << "   color : " << isColor[vertex] << endl;
        // cout << "next : " << next << "  color : " << isColor[next] << endl;
        // cout << "*** " << endl;
      }
    }
    if (!ret) {
      break;
    }
  }

  // cout << "YES" << "\n";
  return ret;
}



int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  int tc, x, y;
  cin >> tc;
  while (tc--) {
    ret = true;
    cin >> v >> e;
    adj.clear();
    adj.resize(v+1);
    for (int i = 0; i < e; i++) {
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    for (int i = 1; i < v+1; i++) {
      if (!isVisited[i] && isColor[i] == 0) {
        // cout << "bfs go " << endl;
        ret = bfs(i);
      }
      if (!ret) {
        break;
      }
      // cout << i << " : " << ret << endl;
    }

    memset(isVisited, false, sizeof(isVisited));
    memset(isColor, 0, sizeof(isColor));

    if (ret) {
      cout << "YES" << "\n";
    }
    else
      cout << "NO" << "\n";
  }
  return 0;
}
