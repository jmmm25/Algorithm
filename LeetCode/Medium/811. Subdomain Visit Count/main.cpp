#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

vector<string> subdomainVisits(vector<string> &cpdomains)
{
    vector<string> answer;
    vector<pair<int, string> > v;

    for (int i = 0; i < cpdomains.size(); i++)
    {
        string cpdomain = cpdomains[i];
        string number = cpdomain.substr(0, cpdomain.find(" "));
        string s = cpdomain.substr(cpdomain.find(" ") + 1);

        char *temp = &s[0];
        vector<string> domain;
        char *str = strtok(temp, ".");
        while (str != NULL)
        {
            domain.push_back(str);
            str = strtok(NULL, ".");
        }

        for (int j = 0; j < domain.size(); j++)
        {
            string s;
            for (int k = j; k < domain.size(); k++)
            {
                s += domain[k];
                if (k != domain.size() - 1)
                {
                    s.append(".");
                }
            }
            v.push_back(make_pair(atoi(number.c_str()), s));
        }
    }
    vector<string> v2;
    for (int i = 0; i < v.size(); i++)
    {
        v2.push_back(v[i].second);
    }

    sort(v2.begin(), v2.end()); //정렬
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    for (int i = 0; i < v2.size(); i++)
    {
        int number = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (v2[i] == v[j].second)
            {
                number += v[j].first;
            }
        }
        answer.push_back(to_string(number) + " " + v2[i]);
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<string> cpdomains;
    cpdomains.push_back("900 google.mail.com");
    cpdomains.push_back("50 yahoo.com");
    cpdomains.push_back("1 intel.mail.com");
    cpdomains.push_back("5 wiki.org");

    vector<string> answer = subdomainVisits(cpdomains);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}
