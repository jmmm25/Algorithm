#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement)
{
    int answer = 0;
    stack<char> s;

    for (int i = 0; i < arrangement.length(); i++)
    {
        if (arrangement[i] == '(')
        {
            s.push(arrangement[i]);
        }
        else
        {
            s.pop();
            if (arrangement[i - 1] == ')')
            {
                answer++;
            }
            else
            {
                answer += s.size();
            }
        }
    }

    return answer;
}

int main(int argc, const char *argv[])
{
    string arrangement = "()(((()())(())()))(())";
    int answer = solution(arrangement);
    cout << answer << endl;
    return 0;
}
