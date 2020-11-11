#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, M;
vector<vector<int> > adj(101);
vector<pair<int, int> > save_number;
bool isVisited[101];
int result[101];

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

void bfs(int v, int ret) {
  queue<pair<int, int> >q;
  q.push(make_pair(v, ret));
  isVisited[v] = true;
  while (!q.empty()) {
    int u = q.front().first;
    int cnt = q.front().second;
    // cout << "q.front() : " << u << endl;
    q.pop();
    for (size_t i = 0; i < adj[u].size(); i++) {
      if (!isVisited[adj[u][i]]) {
        // cout << "queue push " << adj[u][i] << endl;
        isVisited[adj[u][i]] = true;
        q.push(make_pair(adj[u][i], cnt + 1));
        result[adj[u][i]] = cnt + 1;
        // cout << "ret : " << result[adj[u][i]] << endl;
      }
    }
    // cout << "push finished" << endl;
  }
}


int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (size_t i = 1; i <= N; i++) {
    // cout << "bfs : " << i << " 일 때 go" << endl;
    bfs(i, 0);
    int cnt = 0;
    for (size_t i = 1; i <= N ; i++) {
      cnt += result[i];
    }
    // cout << i << ", " << cnt << endl;
    save_number.push_back(make_pair(i, cnt));
    memset(isVisited, false, sizeof(isVisited));
    memset(result, false, sizeof(isVisited));
  }

  sort(save_number.begin(), save_number.end(), compare);

  // for (size_t i = 0; i < N; i++) {
  //   cout << save_number.at(i).first << ":  " << save_number.at(i).second << endl;
  // }
  cout << save_number.at(0).first << "\n";

  return 0;
}
