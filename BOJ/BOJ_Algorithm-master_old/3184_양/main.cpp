#include <iostream>
#include <queue>

using namespace std;

char map[251][251];
bool isVisited[251][251];
int R, C, ans_sheep, ans_wolf;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > q;

void bfs(int r, int c) {
    int x, y, wolf = 0, sheep = 0;
    q.push(make_pair(r, c));
    isVisited[r][c] = true;
    if (map[r][c] == 'v')
        wolf++;
    else if (map[r][c] == 'o')
        sheep++;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        // cout << "pop : " << x << ", " << y << endl;


        for (size_t i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C || isVisited[nx][ny] || map[nx][ny] == '#')
                continue;

            if (map[nx][ny] == 'v')
                wolf++;
            else if (map[nx][ny] == 'o')
                sheep++;

            isVisited[nx][ny] = true;
            q.push(make_pair(nx, ny));
            // cout << "push : " << nx << ", " << ny << endl;
        }
        // cout << x << ", " << y << " ::: " << sheep << ", " << wolf << endl;
    }

    if (sheep > wolf) {
        ans_sheep += sheep;
    }
    else if (sheep <= wolf) {
        ans_wolf += wolf;
    }
}


int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if ((map[i][j] == 'v' || map[i][j] == 'o') && !isVisited[i][j]) {
                // cout << "bfs : " << i << ", " << j << endl;
                bfs(i, j);
            }
        }
    }
    cout << ans_sheep << " " << ans_wolf << "\n";
    return 0;
}
