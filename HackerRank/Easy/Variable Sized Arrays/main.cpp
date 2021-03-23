#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n, q, k;
    vector<vector<int> > v;
    vector<int> temp;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            int data;
            cin >> data;
            temp.push_back(data);
        }
        v.push_back(temp);
        temp.clear();
    }
    int x, y;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        cout << v[x][y] << "\n";
    }

    return 0;
}