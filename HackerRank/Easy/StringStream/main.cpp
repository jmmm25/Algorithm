#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(string input, char delimiter);

vector<int> parseInts(string str) {
    vector<string> v = split(str, ',');
    vector<int> v_i;
    for (int i = 0; i < v.size(); i++) {
        v_i.push_back(stoi(v[i]));
    }

    return v_i;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int main() {
    // freopen("input.txt", "r", stdin);
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}