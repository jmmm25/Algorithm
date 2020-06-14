#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int answer = s.length();
    int s_len = s.length();
    // cout << "s_len: " << s_len << endl;

    for (int i = 1; i <= s_len / 2; i++)
    {
        string str = s.substr(0, i);
        // cout << "자른거 str: " << str << endl;
        string res = "";
        int cnt = 1;
        for (int j = i; j <= s.length(); j += i)
        {
            string cmp = s.substr(j, i);
            // cout << "비교 대상: cmp " << cmp << endl;
            if (str == cmp)
            {
                cnt++;
                // cout << "cnt: " << cnt << endl;
            }
            else
            {
                if (cnt == 1)
                {
                    res += str;
                    // cout << "res: " << res << endl;
                }
                else
                {
                    res += to_string(cnt) + str;
                    // cout << "toString res: " << res << endl;
                }
                str = cmp;
                cnt = 1;
            }
        }
        res += str;
        // cout << "최종 : res: " << res << endl;
        answer = min(answer, (int)res.length());
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    string s = "xababcdcdababcdcd";
    cout << solution(s) << endl;

    return 0;
}
