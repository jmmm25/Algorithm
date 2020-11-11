#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define PAIR(data1, data2)        ( make_pair(data1, data2) )
using namespace std;

int R, C;
// char board[1501][1501];
// pair<char, int> board[1501][1501];
char board[1501][1501];
int visit[1501][1501], water[1501][1501];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int> > v;

bool bfs(int limit){
    queue<pair<int, int> > b;   // swan
    b.push(PAIR(v[0].first, v[0].second));
    visit[v[0].first][v[0].second] = 1;
    while(!b.empty()){
        int x = b.front().first;
        int y = b.front().second;
        b.pop();
        if(x == v[1].first && y == v[1].second )
            return true;

        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C || visit[nx][ny]) continue;
            if(water[nx][ny] <= limit) {
                b.push(make_pair(nx,ny));
                visit[nx][ny] = 1;
            }
        }
    }
    return false;
}

int water_bfs() {
    int cnt = 1;
    queue<pair<int, int> > q;   // water
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == '.' || board[i][j] == 'L') {
                q.push(PAIR(i, j));
                visit[i][j] = 1;
            }
        }
    }

    while(!q.empty()) {
        int q_size = q.size();
        while (q_size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            visit[x][y] = 1;
            for (size_t i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C || visit[nx][ny]) continue;
                if (board[nx][ny] != 'L'){
                    water[nx][ny] = cnt;
                    visit[nx][ny] = 1;
                    q.push(PAIR(nx, ny));
                }
            }
        }
        cnt++;
    }
    return cnt - 2;
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'L') {
                v.push_back(make_pair(i, j));
            }
        }
    }
    // for (size_t i = 0; i < v.size(); i++) {
    //     cout << v[i].first << endl;
    // }
    int l = 0, r, m = 0;
    r = water_bfs();
    // cout << r << endl;
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << water[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    while (l <= r) {
        memset(visit, 0, sizeof(visit));
        m = (l+r) / 2;
        if (bfs(m))
            r = m - 1;
        else
            l = m + 1;
    }

    cout << l << endl;
    return 0;
}
