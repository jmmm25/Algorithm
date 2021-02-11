#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int minPartitions(string n) {
        int result = 0;
        for (int i = 0; i < n.length(); i++) {
            result = max(result, n[i] - '0');
        }

        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;

    // Ex) n = 32
    string n = "32";
    cout << s.minPartitions(n) << "\n";

    return 0;
}
