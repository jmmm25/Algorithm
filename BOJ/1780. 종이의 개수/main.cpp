#include <iostream>

using namespace std;

int arr[2200][2200];
int zero = 0, minus_one = 0, plus_one = 0;

void sol(int x, int y, int n) {
    int first_number = arr[x][y];
    bool flag = true;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (first_number != arr[i][j]) {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        if (first_number == -1)
            minus_one++;
        else if (first_number == 0)
            zero++;
        else if (first_number == 1)
            plus_one++;
    } else {
        for (int i = x; i < x + n; i += n / 3) {
            for (int j = y; j < y + n; j += n / 3) {
                sol(i, j, n / 3);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    sol(0, 0, N);

    printf("%d\n%d\n%d", minus_one, zero, plus_one);

    return 0;
}
