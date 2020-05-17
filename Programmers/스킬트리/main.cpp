#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    vector<string> datas;
    for (int i = 0; i < skill_trees.size(); i++)
    {
        string data;
        for (int j = 0; j < skill_trees[i].size(); j++)
        {
            for (int k = 0; k < skill.size(); k++)
            {
                if (skill_trees[i][j] == skill[k])
                {
                    data += skill_trees[i][j];
                    break;
                }
            }
        }
        datas.push_back(data);
    }
    // for (int i = 0; i < datas.size(); i++)
    // {
    //     cout << datas[i] << endl;
    // }

    for (int i = 0; i < datas.size(); i++)
    {
        if (datas[i].length() == 0)
        {
            answer++;
        }
        else
        {
            int check = true;
            for (int j = 0; j < datas[i].size(); j++)
            {
                if (datas[i][j] != skill[j])
                {
                    check = false;
                    break;
                }
            }
            if (check == true)
            {
                answer++;
            }
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    string skill = "CBD";
    vector<string> skill_trees;

    skill_trees.push_back("BACDE");
    skill_trees.push_back("CBADF");
    skill_trees.push_back("AECB");
    skill_trees.push_back("BDA");
    // skill_trees.push_back("OIUJ");

    cout << solution(skill, skill_trees) << endl;

    return 0;
}
