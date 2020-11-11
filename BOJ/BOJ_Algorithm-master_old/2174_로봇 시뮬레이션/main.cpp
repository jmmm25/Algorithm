#include <iostream>
using namespace std;

int A, B, N, M, what_cur;
int map[101][101], pos_idx[101];
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
int flag;   // 0 : success, 1: crush wall, 2: crush robot

// 배열을 x 축 대칭으로 짰기에 회전도 반대로 함. (원래대로 처럼 하기 위함)
int change_left_pos (int pos) {
    switch(pos) {
        case 1 : return 3;
        case 2 : return 4;
        case 3 : return 2;
        case 4 : return 1;
    }
    return 0;
}

int change_right_pos (int pos) {
    switch(pos) {
        case 1 : return 4;
        case 2 : return 3;
        case 3 : return 1;
        case 4 : return 2;
    }
    return 0;
}

int return_pos(char pos) {
    switch(pos) {
        case 'E' : return 1;
        case 'W' : return 2;
        case 'S' : return 4;
        case 'N' : return 3;
    }
    return 0;
}

void set_init() {
    int x, y;
    char pos;
    for (int i = 1; i <= N; i++) {
        cin >> x >> y >> pos;
        // cout << x << ", " << y << ", " << pos << endl;
        if (pos == 'W' || pos == 'E') {
            map[y][x] = i;
            pos_idx[i] = return_pos(pos);
        }
        else {
            map[y][x] = i;
            pos_idx[i] = return_pos(pos);
        }
    }
}

bool bfs(int x, int y, int cur, char order, int cnt) {
    int next_pos, nx, ny;
    nx = x, ny = y;
    if (order == 'F') {
        next_pos = pos_idx[cur];
        for (int i = 0; i < cnt; i++) {
            nx = nx + (dx[next_pos]);
            ny = ny + (dy[next_pos]);

            if (nx <= 0 || ny <= 0 || nx > B || ny > A) {
                flag = 1;
                return false;
            }

            else if (map[nx][ny] != 0) {
                flag = 2;
                what_cur = map[nx][ny];
                return false;
            }
        }
        map[x][y] = 0;
        map[nx][ny] = cur;
    }

    else if (order == 'L') {
        for (int i = 0; i < cnt; i++) {
            next_pos = change_left_pos(pos_idx[cur]);
            pos_idx[cur] = next_pos;
        }
    }

    else {
        for (int i = 0; i < cnt; i++) {
            next_pos = change_right_pos(pos_idx[cur]);
            pos_idx[cur] = next_pos;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    cin >> A >> B >> N >> M;
    set_init();
    int cur, cnt;
    char order;

    for (int i = 1; i <= M; i++) {
        cin >> cur >> order >> cnt;
        int brk_flag = 0, x, y;
        for (int i = 1; i <= B; i++) {
            for (int j = 1; j <= A; j++) {
                if (map[i][j] == cur) {
                    x = i, y = j;
                    brk_flag = 1;
                    break;
                }
            }
            if (brk_flag) {
                break;
            }
        }

        flag = 0, what_cur = 0;
        bfs(x, y, cur, order, cnt);
        if (flag == 1) {
            cout << "Robot " << cur << " crashes into the wall" << "\n";
            return 0;
        }
        else if (flag == 2) {
            cout << "Robot " << cur << " crashes into robot " << what_cur << "\n";
            return 0;
        }
    }
    cout << "OK" << "\n";
    return 0;
}

// #include <iostream>
// using namespace std;
//
// int A, B, N, M, what_cur;
// int map[101][101], pos_idx[101];
// int dx[5] = {0, 0, 0, 1, -1};
// int dy[5] = {0, 1, -1, 0, 0};
// int flag;   // 0 : success, 1: crush wall, 2: crush robot
//
// 배열을 x 축 대칭으로 짰기에 회전도 반대로 함. (원래대로 처럼 하기 위함)

// int change_left_pos (int pos) {
//     switch(pos) {
//         case 1 : return 3;
//         case 2 : return 4;
//         case 3 : return 2;
//         case 4 : return 1;
//     }
//     return 0;
// }
//
// int change_right_pos (int pos) {
//     switch(pos) {
//         case 1 : return 4;
//         case 2 : return 3;
//         case 3 : return 1;
//         case 4 : return 2;
//     }
//     return 0;
// }
//
// int return_pos(char pos) {
//     switch(pos) {
//         case 'E' : return 1;
//         case 'W' : return 2;
//         case 'S' : return 4;
//         case 'N' : return 3;
//     }
//     return 0;
// }
//
// void set_init() {
//     int x, y;
//     char pos;
//     for (int i = 1; i <= N; i++) {
//         cin >> x >> y >> pos;
//         // cout << x << ", " << y << ", " << pos << endl;
//         if (pos == 'W' || pos == 'E') {
//             map[y][x] = i;
//             pos_idx[i] = return_pos(pos);
//         }
//         else {
//             map[y][x] = i;
//             pos_idx[i] = return_pos(pos);
//         }
//     }
// }
//
// bool bfs(int x, int y, int cur, char order, int cnt) {
//     int next_pos, nx, ny;
//     nx = x, ny = y;
//     if (order == 'F') {
//         next_pos = pos_idx[cur];
//         // cout << "x, y, order : " << x << ", " << y << ", " << order << endl;
//         for (int i = 0; i < cnt; i++) {
//             nx = nx + (dx[next_pos]);
//             ny = ny + (dy[next_pos]);
//             // cout << "nx, ny : " <<  nx << ", " << ny << endl;
//
//             if (nx <= 0 || ny <= 0 || nx > B || ny > A) {
//                 flag = 1;
//                 return false;
//             }
//
//             else if (map[nx][ny] != 0) {
//                 flag = 2;
//                 what_cur = map[nx][ny];
//                 return false;
//             }
//         }
//         map[x][y] = 0;
//         map[nx][ny] = cur;
//     }
//
//     else if (order == 'L') {
//         for (int i = 0; i < cnt; i++) {
//             next_pos = change_left_pos(pos_idx[cur]);
//             pos_idx[cur] = next_pos;
//             // cout << "cur _ pos " << cur << " : " << pos_idx[cur] << endl;
//         }
//     }
//
//     else {
//         for (int i = 0; i < cnt; i++) {
//             next_pos = change_right_pos(pos_idx[cur]);
//             pos_idx[cur] = next_pos;
//             // cout << "cur _ pos " << cur << " : " << pos_idx[cur] << endl;
//         }
//     }
//     return true;
// }
//
// int main(int argc, char const *argv[]) {
//     // freopen("input.txt", "r", stdin);
//     cin >> A >> B >> N >> M;
//
//     // cout << N << M << endl;
//
//     set_init();
//     // for (int i = 1; i <= B; i++) {
//     //     for (int j = 1; j <= A; j++) {
//     //         cout << map[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }
//     // for (int i = 1; i <= N; i++) {
//     //     cout << pos_idx[i] << " ";
//     // }
//     // cout << endl;
//
//     int cur, cnt;
//     char order;
//
//     for (int i = 1; i <= M; i++) {
//         cin >> cur >> order >> cnt;
//         int brk_flag = 0, x, y;
//         // cout << "cur : " << cur << endl;
//         for (int i = 1; i <= B; i++) {
//             for (int j = 1; j <= A; j++) {
//                 if (map[i][j] == cur) {
//                     x = i, y = j;
//                     brk_flag = 1;
//                     break;
//                 }
//             }
//             if (brk_flag) {
//                 break;
//             }
//         }
//
//         flag = 0, what_cur = 0;
//         bfs(x, y, cur, order, cnt);
//         if (flag == 1) {
//             cout << "Robot " << cur << " crashes into the wall" << "\n";
//             return 0;
//         }
//         else if (flag == 2) {
//             cout << "Robot " << cur << " crashes into robot " << what_cur << "\n";
//             return 0;
//         }
//     }
//     cout << "OK" << "\n";
//     return 0;
// }
