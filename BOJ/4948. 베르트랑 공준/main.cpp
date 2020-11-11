#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 123456 * 2 + 1;

int main(int argc, char const *argv[])
{
    // freopen("input.txt", "r", stdin);
    bool arr[MAX];
    fill_n(arr, MAX, true);

    for (int i = 2; i <= sqrt(MAX); i++)
    {
        if (arr[i])
        {
            for (int j = i * 2; j <= MAX; j += i)
            {
                arr[j] = false;
            }
        }
    }

    int n;
    while (true)
    {
        int cnt = 0;
        cin >> n;
        if (n == 0)
            break;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (arr[i])
            {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}