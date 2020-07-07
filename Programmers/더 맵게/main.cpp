#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int min_val = 0;
    int second_min_val = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    while (pq.top() < K) {
        if (pq.size() == 1) {
            return answer = -1;
        }
        min_val = pq.top();
        pq.pop();
        second_min_val = pq.top();
        pq.pop();

        int new_val = min_val + (second_min_val * 2);
        pq.push(new_val);
        answer++;
    }

    return answer;
}

int main(int argc, char const *argv[]) {
    vector<int> scoville;
    int K = 7;
    scoville = {1, 2, 3, 9, 10, 12};
    cout << solution(scoville, K) << endl;
    return 0;
}