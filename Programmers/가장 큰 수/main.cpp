#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(string x, string y) {
    if (x + y > y + x) {
        return true;
    }
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for (auto number : numbers) {
        v.push_back(to_string(number));
    }
    sort(v.begin(), v.end(), compare);
    if (v[0] == "0") {
        return "0";
    }
    for (auto str : v) {
        answer += str;
    }
    return answer;
}

int main(int argc, const char** argv) {
    vector<int> numbers;
    numbers = {6, 2, 10};
    cout << solution(numbers) << endl;

    return 0;
}