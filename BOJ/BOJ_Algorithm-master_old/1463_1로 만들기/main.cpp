#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[1000001];

int sol(int n) {
    int &ret = cache[n];
    if (ret != -1)
        return ret;
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 1;

    ret = sol(n-1) + 1;
    if (n % 3 == 0)
        ret = min(ret, sol(n/3)+1);
    if (n % 2 == 0)
        ret = min(ret, sol(n/2)+1);

    return ret;
}

int main(int argc, char const *argv[]) {
    memset(cache, -1, sizeof(cache));
    int N;
    cin >> N;
    cout << sol(N) << "\n";
    return 0;
}
