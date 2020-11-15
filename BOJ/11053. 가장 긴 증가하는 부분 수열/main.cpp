#include <iostream>
using namespace std;

int n;
int arr[1001];
int dp[1001];

int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    fill_n(dp, 1001, 1);
    int res = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << "\n";

    return 0;
}
