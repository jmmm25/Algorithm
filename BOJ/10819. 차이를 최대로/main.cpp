#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;

int sol()
{
    int max_val = 0;
    sort(v.begin(), v.end());

    do
    {
        int res = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            res += abs(v[i] - v[i + 1]);
        }
        max_val = max(res, max_val);
    } while (next_permutation(v.begin(), v.end()));

    return max_val;
}

int main(int argc, char const *argv[])
{
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        scanf("%d", &num);
        v.push_back(num);
    }

    int res = sol();
    printf("%d\n", res);

    return 0;
}
