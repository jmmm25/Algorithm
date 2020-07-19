#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    string str_A(name.size(), 'A');
    int cur_idx = 0;

    while (name != str_A) {
        int next_idx = -1;
        int min_dist = 30;

        for (int i = 0; i < name.size(); i++) {
            if (name[i] != str_A[i]) {
                int dist = abs(i - cur_idx);
                dist = min(dist, (int)name.size() - dist);
                if (min_dist > dist) {
                    min_dist = dist;
                    next_idx = i;
                }
            }
        }

        cur_idx = next_idx;
        str_A[cur_idx] = name[cur_idx];
        answer += min_dist;

        int temp = name[cur_idx] - 'A';
        int up_down = min(temp, 26 - temp);
        answer += up_down;
    }

    return answer;
}

int main(int argc, char const *argv[]) {
    string name = "JEROEN";
    cout << solution(name) << endl;

    return 0;
}
