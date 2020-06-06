#include <iostream>

using namespace std;

int gcd(int m, int n)
{
    if (m == 0)
    {
        return n;
    }
    else
    {
        return gcd(n % m, m);
    }
}

long long solution(int w, int h)
{
    long long answer = 1;
    long long sum = (long long)w * (long long)h;

    int gcdVal = gcd(w, h);

    answer = sum - (gcdVal * ((w / gcdVal) + (h / gcdVal) - 1));
    return answer;
}

int main(int argc, char const *argv[])
{
    int w = 3;
    int h = 4;

    cout << solution(w, h) << endl;

    return 0;
}
