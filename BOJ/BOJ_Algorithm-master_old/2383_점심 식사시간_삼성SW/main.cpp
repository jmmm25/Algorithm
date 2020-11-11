#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <queue>

#define PAIR(data)      pair<data, data >
#define PEOPLE      1
using namespace std;

int N, map[11][11];
bool bit_check[10];
vector<PAIR(int)> v;
queue<int> q1_stair, q2_stair;

int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    int tc, people_cnt = 0;
    cin >> tc;
    while (tc--) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                if (map[i][j] != PEOPLE && map[i][j] != 0) {
                    v.push_back(make_pair(i, j));
                }
                if (map[i][j] == PEOPLE) {
                    people_cnt++;
                }
            }
        }

        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) {
        //         cout <<  map[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // for (size_t i = 0; i < v.size(); i++) {
        //     cout << v[i].first << ", " << v[i].second << endl;
        // }
        // cout << people_cnt << endl;
    }

    return 0;
}
