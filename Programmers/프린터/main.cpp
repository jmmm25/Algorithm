#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<pair<int, int> > q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }

    while (!q.empty())
    {
        int first = q.front().first;
        int second = q.front().second;
        q.pop();

        if (second == pq.top())
        {
            pq.pop();
            answer++;
            if (first == location)
            {
                break;
            }
        }
        else
        {
            q.push(make_pair(first, second));
        }
    }

    return answer;
}

int main(int argc, const char *argv[])
{
    vector<int> priorities;
    // int location = 2;
    // priorities.push_back(2);
    // priorities.push_back(1);
    // priorities.push_back(3);
    // priorities.push_back(2);

    int location = 0;
    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(9);
    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(1);

    cout << solution(priorities, location) << endl;

    return 0;
}
