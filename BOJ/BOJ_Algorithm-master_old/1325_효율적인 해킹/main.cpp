#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int check[10001];
vector<vector<int> > adj(10001);
bool isVisited[10001];
int n, m;
vector<int> ans;

void push_ans() {
    int max_val = -98765432;
    for (int i = 1; i <= n; i++) {
        if (max_val < check[i]) {
            max_val = check[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (max_val == check[i]) {
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
}
void dfs(int n, int ret) {
    // int next = 0;
    isVisited[n] = true;
    for (int i = 0; i < adj[n].size() ; i++) {
        int next = adj[n][i];
        // cout << "next : " << next << endl;
        if (!isVisited[next]) {
            // cout << "next , cnt " << next << ", " << cnt << endl;
            // adj[n][i].second++;
            check[next]++;
            // if (check[next] < ret) {
            //     // cout << ret << endl;
            //     check[next] = ret;
            // }
            dfs(next, ret+1);
        }
    }
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    int u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        // adj[u].push_back(make_pair(v, 0));
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, 1);
        memset(isVisited, false, sizeof(isVisited));
        // memset(check, 0, sizeof(check));
    }
    // for (size_t i = 0; i <= n; i++) {
    //     cout << check[i] << " " ;
    // }
    // cout << endl;
    push_ans();
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
