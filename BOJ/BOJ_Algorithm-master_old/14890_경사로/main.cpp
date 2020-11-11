#include <iostream>
#include <cstring>
using namespace std;

int mat[101][101];
bool isVisited[101][101];
bool isCline[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, L, ret;

bool decline_sol(int x, int y, int op) {
    int cnt = 0;
    if (!op) {
        if (y+1 < N && y+L < N) {
            for (int i = y+1; i <= y+L; i++) {
                if (!isCline[x][i] && (mat[x][i] == mat[x][y] - 1)) {
                    cnt++;
                    isCline[x][i] = true;
                }
            }
            if (cnt == L) {
                return true;
            }
        }
        return false;
    }
    else {
        if (x+1 < N && x+L < N) {
            for (int i = x+1; i <= x+L; i++) {
                if (!isCline[i][y] && (mat[i][y] == mat[x][y] - 1)) {
                    cnt++;
                    isCline[i][y] = true;
                }
            }
            if (cnt == L) {
                return true;
            }
        }
        return false;
    }
}

bool incline_sol(int x, int y, int op) {
    int cnt = 0;
    if (!op) {
        if (y-1 >= 0 && y-L >= 0) {
            for (int i = y-1; i >= y-L; i--) {
                if (!isCline[x][i] && (mat[x][i] == mat[x][y] - 1)) {
                    cnt++;
                    isCline[x][i] = true;
                }
            }
            if (cnt == L)
                return true;
        }
        return false;
    }

    else {
        if (x-1 >= 0 && x-L >= 0) {
            for (int i = x-1; i >= x-L; i--) {
                if (!isCline[i][y] && (mat[i][y] == mat[x][y] - 1)) {
                    cnt++;
                    isCline[i][y] = true;
                }
            }
            if (cnt == L)
                return true;
        }
        return false;
    }
}

void col_dfs(int r, int c, int depth) {
    int x = r;
    int y = c;
    isVisited[x][y] = true;
    if (depth == N-1) {
        // cout << c << " col success!!" << endl;
        ret++;
        return;
    }
    for (size_t i = 2; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || isVisited[nx][ny]) {
            continue;
        }
        if (mat[x][y] == mat[nx][ny]) {
            col_dfs(nx, ny, depth+1);
            isVisited[nx][ny] = false;
        }
        else {
            int flag = false;
            if (mat[x][y] + 1 == mat[nx][ny]) {
                flag = incline_sol(nx, ny, 1);
                if (flag) {
                    col_dfs(nx, ny, depth+1);
                    isVisited[nx][ny] = false;
                }
            }

            else if (mat[x][y] - 1 == mat[nx][ny]){
                flag = decline_sol(x, y, 1);
                if (flag) {
                    col_dfs(nx, ny, depth+1);
                    isVisited[nx][ny] = false;
                }
            }
        }
    }
}


void row_dfs(int r, int c, int depth) {
    int x = r;
    int y = c;
    isVisited[x][y] = true;

    if (depth == N-1) {
        // cout << r <<" row   success!!" << endl;
        ret++;
        return;
    }
    for (int i = 0; i < 1; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || isVisited[nx][ny]) {
            continue;
        }
        if (mat[x][y] == mat[nx][ny]) {
            row_dfs(nx, ny, depth+1);
            isVisited[nx][ny] = false;
        }
        else {
            int flag = false;
            if (mat[x][y] + 1 == mat[nx][ny]) {
                flag = incline_sol(nx, ny, 0);
                if (flag) {
                    row_dfs(nx, ny, depth+1);
                    isVisited[nx][ny] = false;
                }
            }

            else if (mat[x][y] - 1 == mat[nx][ny]){
                flag = decline_sol(x, y, 0);
                if (flag) {
                    row_dfs(nx, ny, depth+1);
                    isVisited[nx][ny] = false;
                }
            }
        }
    }
}


int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < N; i++) {
        row_dfs(i, 0, 0);
    }
    memset(isCline, false, sizeof(isCline));
    memset(isVisited, false, sizeof(isVisited));

    for (int i = 0; i < N; i++) {
        col_dfs(0, i, 0);
    }
    cout << ret << "\n";
    return 0;
}
