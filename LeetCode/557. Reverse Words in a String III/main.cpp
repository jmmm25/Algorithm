#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string result;
        size_t pos;
        while ((pos = s.find(' ')) != string::npos)
        {
            string str = s.substr(0, pos);
            reverse(str.begin(), str.end());
            result += str + ' ';
            s = s.substr(pos + 1);
        }
        reverse(s.begin(), s.end());
        result += s;

        return result;
    }
};

int main(int argc, char const *argv[])
{
    string str = "Let's take LeetCode contest";
    Solution solution;

    cout << solution.reverseWords(str) << endl;

    return 0;
}
