#include <iostream>
#include <queue>

using namespace std;

int N, x;
priority_queue<int, vector<int>, less<int>> pq;

int main(int argc, char const *argv[])
{
    // freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        if (x == 0)
        {
            if (pq.empty())
            {
                printf("%d\n", 0);
            }
            else
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else
        {
            pq.push(x);
        }
    }
    while (!pq.empty())
    {
        pq.pop();
    }

    return 0;
}