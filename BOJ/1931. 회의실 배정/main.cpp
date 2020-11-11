#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
vector<pair<int, int> > v;
stack<pair<int, int> > s;

int sol() {
    int ret = 0;
    for (int i = 0; i < v.size(); i++) {
        if (s.empty()) {
            s.push(make_pair(v[i].first, v[i].second));
            // cout << "x, y: " << v[i].first << ", " << v[i].second << endl;
            ret++;
        } else {
            if (s.top().second <= v[i].first) {
                s.pop();
                s.push(make_pair(v[i].first, v[i].second));
                // cout << "x, y: " << v[i].first << ", " << v[i].second << endl;
                ret++;
            }
        }
    }
    while (!s.empty()) {
        s.pop();
    }

    return ret;
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second < b.second) {
        return true;
    } else if (a.second == b.second) {
        return a.first < b.first;
    }
    return false;
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), cmp);
    // for (int i = 0; i < v.size(); i++) {
    //     cout << "x, y: " << v[i].first << ", " << v[i].second << endl;
    // }
    // cout << "sol!!!" << endl;

    cout << sol() << "\n";

    return 0;
}
