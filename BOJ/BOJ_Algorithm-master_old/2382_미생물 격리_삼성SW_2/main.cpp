#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// class Info {
// public:
//     int x, y, cnt, pos;
//     Info() {};
//     Info(int _x, int _y, int _cnt, int _pos):
//         x(_x), y(_y), cnt(_cnt), pos(_pos) {};
// };
class Info {
public:
    int cnt, pos, visit;
    Info() {};
    Info(int _cnt, int _pos, int _visit):
        cnt(_cnt), pos(_pos), visit(_visit) {};
};

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
int N, M, K;
vector<Info> map[101][101];

int change_pos(int pos) {
    switch(pos) {
        case 1 : return 2;
        case 2 : return 1;
        case 3 : return 4;
        case 4 : return 3;
    }
    return 0;
}

void unify_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j].size() > 0) {
                if (map[i][j].size() == 1) {
                    map[i][j].at(0).visit = 0;
                }
                else {
                    int max_val = -98765431;
                    int pos = 0, total_cnt = 0;
                    for (int cur = 0; cur < map[i][j].size(); cur++) {
                        total_cnt += map[i][j].at(cur).cnt;
                        if (max_val < map[i][j].at(cur).cnt) {
                            max_val = map[i][j].at(cur).cnt;
                            pos = map[i][j].at(cur).pos;
                        }
                    }
                    map[i][j].clear();
                    map[i][j].push_back(Info(total_cnt, pos, 0));
                }
            }
        }
    }
}

int half(int x, int y) {
    int cnt;
    cnt = map[x][y].at(0).cnt / 2;

    return cnt;
}

void sol(int r, int c) {
    int x, y;
    x = r, y = c;
    for (int i = 0; i < 1; i++) {
        int next_pos = map[r][c].at(0).pos;
        int nx = x + dx[next_pos];
        int ny = y + dy[next_pos];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

        // 약품이 칠해진 곳에 이동할 경우 -> cnt / 2
        if (nx == 0 || ny == 0 || nx == (N-1) || ny == (N-1)) {
            int half_cnt = half(x, y);
            int pos = change_pos(map[x][y].at(0).pos);
            int visit = map[x][y].at(0).visit + 1;
            // cout << "half , pos " << half_cnt << ", " << pos << endl;
            if (half_cnt > 0) {
                map[nx][ny].push_back(Info(half_cnt, pos, visit));
                // cout << "push : " << nx << ", " << ny << " cnt : " << half_cnt  << " pos : " << pos << " visit : " << visit << endl;

                if (map[x][y].size() > 0) {
                    map[x][y].erase(map[x][y].begin());
                    // cout << x << ", " << y << "  delete  !" << endl;
                }
            }
            else {
                if (map[x][y].size() > 0) {
                    map[x][y].erase(map[x][y].begin());
                    // cout << x << ", " << y;
                    // cout << " disappear " << endl;
                }
            }

        }

        // 미생물이 그냥 이동할 경우
        else {
            int cnt = map[x][y].at(0).cnt;
            int pos = map[x][y].at(0).pos;
            int visit = map[x][y].at(0).visit + 1;
            map[nx][ny].push_back(Info(cnt, pos, visit));
            // cout << "push : " << nx << ", " << ny << " cnt : " << cnt  << " pos : " << pos << " visit : " << visit << endl;
            if (map[x][y].size() > 0) {
                map[x][y].erase(map[x][y].begin());
                // cout << x << ", " << y << "  delete  !" << endl;
            }
        }
    }

}


int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    int tt = 0;
    while (tt++ < tc) {
        cin >> N >> M >> K;
        int x, y, cnt, pos;
        for (int i = 0; i < K; i++) {
            cin >> x >> y >> cnt >> pos;
            map[x][y].push_back(Info(cnt, pos, 0));
        }

        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j< N; j++) {
        //         for (int k = 0; k < map[i][j].size(); k++) {
        //             cout << i << ", " << j << " : ";
        //             cout << map[i][j][k].cnt << endl;
        //         }
        //     }
        // }
        int ret = 0;
        for (int t = 1; t <= M; t++) {
            // cout << endl;
            // cout << "Time : " << t << endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (map[i][j].size() != 0 && !map[i][j].at(0).visit) {
                        // cout << "sol(i,j) : " << i << ", " << j << " start !" << "visit : " << map[i][j].at(0).visit << endl;
                        sol(i, j);
                    }
                }
            }

            unify_map();
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j< N; j++) {
                for (int k = 0; k < map[i][j].size(); k++) {
                    // cout << i << ", " << j << " : ";
                    // cout << map[i][j][k].cnt << ", " << map[i][j][k].pos << ", " << map[i][j][k].visit << endl;
                    ret += map[i][j].at(k).cnt;
                    map[i][j].clear();
                }
            }
        }
        cout << "#" << tt << " " << ret << "\n";

    }

    return 0;
}
