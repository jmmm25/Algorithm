#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int mat[501][501];
bool isVisited[501][501];
int ret = -1;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void sol(int x, int y, int cnt) {
    // cout << "x, y " << "(" << x << "," << y << ")" << endl;
    int min_val = 987654321;
    int sum = mat[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        min_val = min(min_val, mat[nx][ny]);
        sum += mat[nx][ny];
        cnt++;
    }
    // cout << "cnt , min_val : " << cnt << ", " << min_val << endl;
    if (cnt == 4) {
        // cout << "4 ret ============ : " << sum << endl;
        ret = max(ret, sum);
    }
    else if (cnt == 5) {
        // cout << "5 ret ============ " << sum << " - " << min_val << " = "<< sum - min_val << endl;
        ret = max(ret, sum - min_val);
    }
}

void dfs(int x, int y, int depth, int val) {
    isVisited[x][y] = true;
    int sum = val;
    if (depth == 4) {
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         if (isVisited[i][j]) {
                    // cout << "(" <<  i << "," << j << ")" << " ";
        //         }
        //     }
        // }
        // cout << " = " << sum << endl;
        ret = max(ret, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M || isVisited[nx][ny]) continue;
        // cout << "nx , ny  : " << nx << ", " << ny << "dfs go " << endl;

        // sum += map[nx][ny];
        dfs(nx, ny, depth+1, sum + mat[nx][ny]);
        isVisited[nx][ny] = false;
    }

}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mat[i][j];
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dfs(i, j, 1, mat[i][j]);
            isVisited[i][j] = false;
            sol(i, j, 1);
        }
    }
    // cout << "result : " << ret << endl;
    cout << ret << "\n";

    return 0;
}
