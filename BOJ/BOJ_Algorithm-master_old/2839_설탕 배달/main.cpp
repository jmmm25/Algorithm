#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int N, cnt5 = 5, cnt3 = 3, ret = -1;
    cin >> N;
    if (N >= 3 && N <= 5000) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (N == cnt5 * i + cnt3 * j) {
                    ret = i + j;
                    break;
                }
            }
        }
        if (ret > 0)
            cout << ret << "\n";
        else
            cout << ret << "\n";
    }
    return 0;
}
