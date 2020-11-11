#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string Adrian, Bruno, Goran;
char answer[101];
int cnt[3];
vector<pair<int, int> > result;
int N;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.second > b.second;
}

void sol() {
    int temp = 0;
    // Adrian
    for (int i = 0; i < N; i++) {
        if (temp > 0) {
            temp %= 3;
        }
        if (answer[i] == Adrian[temp++]) {
            cnt[0]++;
        }
    }
    //Bruno
    temp = 0;
    for (int i = 0; i < N; i++) {
        if (temp > 0) {
            temp %= 4;
        }
        if (answer[i] == Bruno[temp++]) {
            cnt[1]++;
        }
    }
    //Goran
    temp = 0;
    for (int i = 0; i < N; i++) {
        if (temp > 0) {
            temp %= 6;
        }
        if (answer[i] == Goran[temp++]) {
            cnt[2]++;
        }
    }

    for (int i = 0; i < 3; i++) {
        result.push_back(make_pair(i, cnt[i]));
    }
    sort(result.begin(), result.end(), compare);
    // for (int i = 0; i < 3; i++) {
    //     cout << result[i].first  << " , " << result[i].second << endl;
    // }
}

void set_arr() {
    Adrian = "ABC";
    Bruno = "BABC";
    Goran = "CCAABB";
}
int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    set_arr();
    int max_val = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> answer[i];
    }

    sol();
    max_val = result[0].second;
    cout << max_val << "\n";
    int i = 0;
    while (max_val == result[i].second) {
        if (result[i].first == 0)
            cout << "Adrian" << "\n";
        else if (result[i].first == 1)
            cout << "Bruno" << "\n";
        else
            cout << "Goran" << "\n";
        i++;
    }


    return 0;
}
