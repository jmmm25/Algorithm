#include <iostream>
#include <cstring>
using namespace std;

int map[301][301];
bool isVisited[301][301];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int r, int c) {
    isVisited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (nr < 0 || nc < 0 || nr >= n || nc >= m || isVisited[nr][nc]) {
            continue;
        }
        if (map[nr][nc] == 0) {
            continue;
        }
        dfs(nr, nc);
    }
}

void dfs_time(int r, int c) {
    isVisited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        // cout << nr << ", " << nc << endl;
        if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
            // cout << nr << ", " << nc << " continue 1" << endl;
            continue;
        }
        if (map[nr][nc] == 0 && isVisited[nr][nc])  {
            // cout << nr << ", " << nc << " continue 2" << endl;
            continue;
        }

        if (map[nr][nc] > 0) {
            map[nr][nc]--;
            // cout << nr << ", " << nc << " " << map[nr][nc] << endl;
            if (map[nr][nc] == 0) {
                isVisited[nr][nc] = true;
            }
            continue;
        }
        dfs_time(nr, nc);
    }
}


int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int connected_cnt = 0, time = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    while (connected_cnt < 2) {
        connected_cnt = 0;
        cnt = 0;
        memset(isVisited, false, sizeof(isVisited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0 && !isVisited[i][j]) {
                    dfs_time(i, j);
                }
            }
        }
        time++;
        memset(isVisited, false, sizeof(isVisited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) cnt++;
                if (map[i][j] != 0 && !isVisited[i][j]) {
                    dfs(i, j);
                    connected_cnt++;
                }
            }
        }
        if (cnt == m * n) {
            time = 0;
            break;
        }
    }

    cout << time << "\n";

    return 0;
}
