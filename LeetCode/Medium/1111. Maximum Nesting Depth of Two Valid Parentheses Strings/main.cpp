#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> answer(seq.size());
        stack<int> s;

        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') {
                if (s.empty()) {
                    s.push(0);
                } else {
                    s.push(1 - s.top());
                }
                answer[i] = s.top();
            } else {
                answer[i] = s.top();
                s.pop();
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[]) {
    string seq = "(()())";
    Solution s;
    vector<int> v = s.maxDepthAfterSplit(seq);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    cout << endl;
    return 0;
}
