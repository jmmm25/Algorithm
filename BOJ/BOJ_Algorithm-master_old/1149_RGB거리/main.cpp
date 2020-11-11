#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int board[1001][3];
int cache[1001][3];
int N;

int main(int argc, char const *argv[]) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }
    cache[0][0] = cache[0][1] = cache[0][2] = board[0][0] = board[0][1] = board[0][2] = 0;
    for (int i = 1; i <= N; i++) {
        cache[i][0] = min(cache[i-1][1], cache[i-1][2]) + board[i][0];
        cache[i][1] = min(cache[i-1][0], cache[i-1][2]) + board[i][1];
        cache[i][2] = min(cache[i-1][0], cache[i-1][1]) + board[i][2];
        // cout << cache[i][0] << ", " << cache[i][1] << ", " << cache[i][2] << endl;
    }
    cout << min( min(cache[N][0], cache[N][1]), cache[N][2]) << "\n";
    return 0;
}
