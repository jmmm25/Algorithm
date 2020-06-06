#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int current_weight = 0;
    queue<int> q;

    for (int i = 0; i < truck_weights.size(); i++)
    {
        while (true)
        {
            if (truck_weights[i] + current_weight <= weight)
            {
                q.push(truck_weights[i]);
                current_weight += truck_weights[i];
                answer++;
                if (q.size() >= bridge_length)
                {
                    current_weight -= q.front();
                    q.pop();
                }
                break;
            }
            else
            {
                q.push(0);
            }

            if (q.size() >= bridge_length)
            {
                current_weight -= q.front();
                q.pop();
            }
            answer++;
        }
    }

    return answer + bridge_length;
}

int main(int argc, char const *argv[])
{
    int bridge_length = 100;
    int weight = 100;

    vector<int> truck_weights;

    // truck_weights.push_back(7);
    // truck_weights.push_back(4);
    // truck_weights.push_back(5);
    // truck_weights.push_back(6);

    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);
    truck_weights.push_back(10);

    cout << solution(bridge_length, weight, truck_weights) << endl;
    return 0;
}
