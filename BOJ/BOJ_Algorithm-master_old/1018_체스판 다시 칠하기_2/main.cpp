#include <iostream>

using namespace std;

string white = "WBWBWBWB";
string black = "BWBWBWBW";
string white_chess[8], black_chess[8];
char map[51][51];
int n, m;

int sol(int x, int y) {
    int white_cnt = 0, black_cnt = 0, ret = 987654321;
    for (size_t i = x; i < x+8; i++) {
        for (size_t j = y; j < y+8; j++) {
            if (map[i][j] != white_chess[i-x][j-y]) {
                white_cnt++;
            }
            if (map[i][j] != black_chess[i-x][j-y]) {
                // cout << "differ " <<  i << ", " << j << endl;
                black_cnt++;
            }
        }
    }
    ret = min(white_cnt, black_cnt);

    return ret;
}

void set_white_init() {
    for (int i = 0; i < 7; i+=2) {
        white_chess[i] = white;
    }
    for (int i = 1; i < 8; i+=2) {
        white_chess[i] = black;
    }
}

void set_black_init() {
    for (int i = 0; i < 7; i+=2) {
        black_chess[i] = black;
    }
    for (int i = 1; i < 8; i+=2) {
        black_chess[i] = white;
    }
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    set_black_init();
    set_white_init();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int ret = 98765421;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (j+7 < m && i+7 < n) {
                // cout << "i, j : " << i << j << endl;
                ret = min(ret, sol(i,j));
                // ret = sol(i, j);
                // cout << "result: " << ret << endl;
            }
        }
    }

    cout << ret << "\n";

    return 0;
}
