#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); i++)
    {
        int progress = progresses[i];
        int speed = speeds[i];

        int day = (100 - progress) / speed;
        if ((100 - progress) % speed > 0)
        {
            day++;
        }
        q.push(day);
    }

    while (!q.empty())
    {
        int cnt = 0;
        int day = q.front();
        q.pop();
        cnt++;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            if (day >= q.front())
            {
                cnt++;
                q.pop();
            }
            else
            {
                break;
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}

int main(int argc, const char *argv[])
{
    vector<int> progresses;
    vector<int> speeds;

    progresses.push_back(93);
    progresses.push_back(30);
    progresses.push_back(55);

    speeds.push_back(1);
    speeds.push_back(30);
    speeds.push_back(5);

    vector<int> answer = solution(progresses, speeds);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}
