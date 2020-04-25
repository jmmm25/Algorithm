#include <string>
#include <vector>

#include <iostream>

using namespace std;

string solution(int n)
{
    string answer = "";
    int arr[] = {4, 1, 2};

    int mok = 0, nam = 0;

    while (n > 0)
    {
        nam = n % 3;
        if (nam == 0)
        {
            n = n / 3 - 1;
        }
        else
        {
            n = n / 3;
        }
        answer = to_string(arr[nam]) + answer;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    int n;
    // freopen("input.txt", "r", stdin);
    cin >> n;
    cout << solution(n);
    return 0;
}
