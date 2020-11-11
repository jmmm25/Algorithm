#include <iostream>
using namespace std;

int R, B;
int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> R >> B;
    int L = 0, W = 0;
    for (size_t i = 3; i < 10000; i++) {
        for (size_t j = 3; j < 10000; j++) {
            int r_cnt = 0, b_cnt = 0, total = i * j;
            b_cnt = (i-2) * (j-2);
            r_cnt = total - b_cnt;

            if (r_cnt == R && b_cnt == B) {
                if (i > j) {
                    L = i;
                    W = j;
                }
                else {
                    L = j;
                    W = i;
                }
                cout << L << " " << W << "\n";
                return 0;
            }
        }
    }
    return 0;
}
