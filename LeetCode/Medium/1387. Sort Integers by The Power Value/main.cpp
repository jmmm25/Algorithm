#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int> > v;
        int num = 0;
        int answer = 0;

        for (int i = lo; i <= hi; i++) {
            answer = 0;
            int num = i;
            while (num != 1) {
                if (num % 2 == 0) {
                    num /= 2;
                } else {
                    num = (3 * num) + 1;
                }
                answer++;
            }
            // cout << "ans: " << i << ", " << answer << endl;
            v.push_back(make_pair(answer, i));
        }
        sort(v.begin(), v.end());
        answer = v[k - 1].second;

        return answer;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.getKth(12, 15, 2);
    return 0;
}
