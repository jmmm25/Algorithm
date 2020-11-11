#include <iostream>
#include <cstring>
using namespace std;

int cache[11];
int T, N;
int sol(int n) {
    int &ret = cache[n];
    if (ret != -1)
        return ret;

    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    ret = sol(n - 3) + sol(n - 2) + sol(n - 1);

    return ret;
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> T;
    int ret = -1;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < T; i++) {
        cin >> N;
        ret = sol(N);
        cout << ret << "\n";
    }
    return 0;
}
