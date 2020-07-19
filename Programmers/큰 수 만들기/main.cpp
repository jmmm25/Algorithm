#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int num_sz = number.length() - k;
    // answer = number.substr(k);
    // cout << "answer: " << answer << endl;
    // cout << "size: " << num_sz << endl;
    int idx = 0;
    for (int i = 0; i < num_sz; i++) {
        char max_val = -1;
        int max_val_idx = idx;
        for (int j = idx; j < i + k + 1; j++) {
            if (max_val < number[j]) {
                max_val = number[j];
                max_val_idx = j;
            }
        }
        // cout << "max_val: " << max_val << endl;
        answer += number[max_val_idx];
        idx = max_val_idx + 1;
    }

    return answer;
}

int main(int argc, char const *argv[]) {
    string number = "1231434";
    int k = 3;
    cout << solution(number, k) << endl;
    return 0;
}
