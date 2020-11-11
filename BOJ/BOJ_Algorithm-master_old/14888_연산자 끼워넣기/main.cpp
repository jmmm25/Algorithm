#include <iostream>
#include <vector>
#include <cstring>
#define INF      1000000000
#define ll          long long
using namespace std;

int N;
int op[4];
int number[12];
ll int Max = -INF;
ll int Min = INF;

void dfs(int depth, int sum) {
    if (depth == N) {
        // cout << "sum : " << sum << endl;
        if (sum >= Max) {
            Max = sum;
        }
        if (sum <= Min) {
            Min = sum;
        }
        return;
    }
    else {
        for (size_t i = 0; i < 4; i++) {
            if (op[i] > 0) {
                op[i]--;
                switch (i) {
                    case 0 :
                        dfs(depth + 1, sum + number[depth]);
                        break;
                    case 1 :
                        dfs(depth + 1, sum - number[depth]);
                        break;
                    case 2 :
                        dfs(depth + 1, sum * number[depth]);
                        break;
                    case 3 :
                        dfs(depth + 1, sum / number[depth]);
                        break;
                }
                op[i]++;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> number[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    dfs(1, number[0]);
    cout << Max << "\n" << Min << "\n";
    return 0;
}
