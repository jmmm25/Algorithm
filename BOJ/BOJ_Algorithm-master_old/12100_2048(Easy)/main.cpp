#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<vector<int> > mat(21);
bool isVisited[21][21];
// vector<vector<int> > copy_map;
int ret = -9876541;

void move_right(vector<vector<int> >& copy_map) {
    memset(isVisited, false, sizeof(isVisited));
    for (int i = N-1; i >= 0; i--) {
        int cur = i;
        while (cur != N-1) {
            for (int j = 0; j < N; j++) {
                if (copy_map[j][cur] == copy_map[j][cur + 1] && copy_map[j][cur+1] != 0 && copy_map[j][cur+1] != 0) {
                    if (isVisited[j][cur+1] || isVisited[j][cur]) {
                        continue;
                    }
                    copy_map[j][cur+1] += copy_map[j][cur];
                    isVisited[j][cur+1] = true;
                    copy_map[j][cur] = 0;
                }
                else if (copy_map[j][cur + 1] == 0) {
                    copy_map[j][cur+1] += copy_map[j][cur];
                    copy_map[j][cur] = 0;
                }
                else
                    continue;
            }
            cur++;
        }
    }
    // return copy_map;
}

void move_left(vector<vector<int> >& copy_map) {
    memset(isVisited, false, sizeof(isVisited));
    for (int i = 0; i < N; i++) {
        int cur = i;
        while (cur != 0) {
            for (int j = 0; j < N; j++) {
                if (copy_map[j][cur] == copy_map[j][cur-1] && copy_map[j][cur] != 0 && copy_map[j][cur-1] != 0) {
                    if (isVisited[j][cur] || isVisited[j][cur-1]) {
                        continue;
                    }
                    copy_map[j][cur-1] += copy_map[j][cur];
                    isVisited[j][cur-1] = true;
                    copy_map[j][cur] = 0;
                }
                else if (copy_map[j][cur-1] == 0) {
                    copy_map[j][cur-1] += copy_map[j][cur];
                    copy_map[j][cur] = 0;
                }
                else
                    continue;
            }
            cur--;
        }
    }
}

void move_bottom(vector<vector<int> >& copy_map) {
    memset(isVisited, false, sizeof(isVisited));
    for (int i = N-1; i >= 0; i--) {
        int cur = i;
        while (cur != N-1) {
            for (int j = 0; j < N; j++) {
                if (copy_map[cur][j] == copy_map[cur+1][j] && copy_map[cur][j] != 0 && copy_map[cur+1][j] != 0) {
                    if (isVisited[cur][j] || isVisited[cur+1][j]) {
                        continue;
                    }
                    copy_map[cur+1][j] += copy_map[cur][j];
                    isVisited[cur+1][j] = true;
                    copy_map[cur][j] = 0;
                }
                else if (copy_map[cur+1][j] == 0) {
                    copy_map[cur+1][j] += copy_map[cur][j];
                    copy_map[cur][j] = 0;
                }
                else
                    continue;
            }
            cur++;
        }
    }
}

void move_up(vector<vector<int> >& copy_map) {
    memset(isVisited, false, sizeof(isVisited));
    for (int i = 0; i < N; i++) {
        int cur = i;
        while (cur != 0) {
            for (int j = 0; j < N; j++) {
                if (copy_map[cur][j] == copy_map[cur-1][j] && copy_map[cur][j] != 0 && copy_map[cur-1][j] != 0) {
                    if (isVisited[cur][j] || isVisited[cur-1][j]) {
                        continue;
                    }
                    copy_map[cur-1][j] += copy_map[cur][j];
                    isVisited[cur-1][j] = true;
                    // cout << "visit : " << cur-1 <<", " << j << "     "<< isVisited[cur-1][j] << endl;
                    copy_map[cur][j] = 0;
                }
                else if (copy_map[cur-1][j] == 0) {
                    copy_map[cur-1][j] += copy_map[cur][j];
                    copy_map[cur][j] = 0;
                    // if (isVisited[cur][j])
                    //     isVisited[cur][j] = false;
                }
                else
                    continue;
            }
            cur--;
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << isVisited[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void dfs(vector<vector<int> > mat, int depth) {
    // memcpy(copy_map, map, sizeof(map));
    if (depth == 5) {
        // cout << "depth finissh " << endl;
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "depth!" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ret = max(ret, mat[i][j]);
            }
            // cout << endl;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        vector<vector<int> > temp = mat;

        // cout << "pos : " << i << "\t" << endl;
        // cout << "======change 전=======" << endl;
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) {
        //         cout << temp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        switch(i) {
            case 0:
                    move_right(temp);
                    // cout << " right " << " ";
                    break;
            case 1:
                    move_left(temp);
                    // cout << " left " << " ";
                    break;
            case 2:
                    move_bottom(temp);
                    // cout << " bottom " << " ";
                    break;
            case 3:
                    move_up(temp);
                    // cout << " up " << " ";
                    break;
        }

        // cout << "======change 후=======" <<endl;
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) {
        //         cout << temp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        dfs(temp, depth + 1);
    }
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> N;
    int temp;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> temp;
            mat.at(i).push_back(temp);
        }
    }

    dfs(mat, 0);
    cout << ret << endl;
    return 0;
}
