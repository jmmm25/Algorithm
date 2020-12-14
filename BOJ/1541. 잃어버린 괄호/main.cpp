#include <iostream>
using namespace std;

string str;

int sol(string str)
{
    int ret = 0;
    string s = "";
    bool isMinus = false;
    for (int i = 0; i <= str.size(); i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
        {
            if (isMinus)
            {
                ret -= stoi(s);
            }
            else
            {
                ret += stoi(s);
            }

            if (str[i] == '-')
            {
                isMinus = true;
            }
            s = "";
            continue;
        }
        s += str[i];
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    cin >> str;
    cout << sol(str) << endl;

    return 0;
}
