#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
vector<pair<int, int>> v;

void move(int N, int A, int B)
{
    // cout << A << " " << B << "\n";
    cnt++;
    v.push_back(make_pair(A, B));
}

void hanoi(int N, int A, int B, int C)
{
    if (N == 1)
    {
        move(N, A, B);
    }
    else
    {
        hanoi(N - 1, A, C, B);
        move(N, A, B);
        hanoi(N - 1, C, B, A);
    }
}

int main(int argc, char const *argv[])
{
    // freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    hanoi(N, 1, 3, 2);

    cout << cnt << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}
