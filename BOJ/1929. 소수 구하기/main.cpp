#include <cmath>
#include <iostream>

using namespace std;

void sol(int num) {
    bool isPrime = true;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }
    if (isPrime) {
        cout << num << "\n";
    }
}

int main(int argc, const char** argv) {
    // freopen("input.txt", "r", stdin);
    int m, n;
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        if (i == 1) {
            continue;
        }
        sol(i);
    }

    return 0;
}