#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isVisited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > q;
int cnt, sz;

void bfs(int x, int y, int m, int n, vector<vector<int> > picture) {
    q.push(make_pair(x, y));
    isVisited[x][y] = true;

    while (!q.empty()) {
        int first = q.front().first;
        int second = q.front().second;
        q.pop();
        sz++;

        for (int i = 0; i < 4; i++) {
            int nx = first + dx[i];
            int ny = second + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n || isVisited[nx][ny] || picture[nx][ny] != picture[first][second]) {
                continue;
            }
            q.push(make_pair(nx, ny));
            isVisited[nx][ny] = true;
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int> > picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    cnt = 0, sz = 0;

    memset(isVisited, false, sizeof(isVisited));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] == 0 || isVisited[i][j]) {
                continue;
            }
            bfs(i, j, m, n, picture);
            cnt++;
            max_size_of_one_area = max(max_size_of_one_area, sz);
            sz = 0;
        }
    }
    number_of_area = cnt;
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(int argc, char const *argv[]) {
    int m = 6, n = 4;
    vector<vector<int> > picture = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};

    vector<int> answer = solution(m, n, picture);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}
