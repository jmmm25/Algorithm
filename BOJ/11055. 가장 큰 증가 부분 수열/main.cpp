#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];
int N;

int main(int argc, char const *argv[])
{
    // freopen("input.txt", "r", stdin);
    cin >> N;
    int res = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
            {
                dp[i] = dp[j] + arr[i];
            }
        }
        res = max(res, dp[i]);
    }

    cout << res << "\n";

    return 0;
}
