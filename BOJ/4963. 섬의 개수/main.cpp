#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 51;
int w, h;
int map[MAX][MAX];
bool isVisited[MAX][MAX];
queue<pair<int, int>> q;

int dx[8] = {0, 0, 1, -1, -1, 1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};

void init_map()
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            map[i][j] = 0;
            isVisited[i][j] = false;
        }
    }
}

void bfs(int x, int y)
{
    //x : 가로, y: 세로
    q.push(make_pair(x, y));
    isVisited[x][y] = true;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                continue;

            if (map[nx][ny] == 1 && !isVisited[nx][ny])
            {
                isVisited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // freopen("input.txt", "r", stdin);

    while (true)
    {
        init_map();
        int cnt = 0;
        cin >> w >> h;
        if (w == 0 && h == 0)
        {
            break;
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (!isVisited[i][j] && map[i][j] == 1)
                {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
