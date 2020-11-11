#include <iostream>
#include <algorithm>
#include <vector>
#define DEBUG       0

using namespace std;
int N;
int mat[501][501], sum;
bool check[11];

int cal_sum(vector<int> v) {
    sum = 0;
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = 0; j < v.size(); j++) {
            if (i == j) continue;
            if (DEBUG) {
                cout << "i, j " << v[i] << ", " << v[j] << endl;
            }
            sum += mat[v[i]][v[j]];
        }
    }
    return sum;
}

int find_stat(vector<int> start, vector<int> link) {
    if (DEBUG) {
        cout << endl;
        cout << "start team : " << " ";
        for (int i = 0; i < start.size(); i++) {
            cout << start[i] << " ";
        }

        cout << endl;
        cout << "link team : " << " ";
        for (int j = 0; j < link.size(); j++) {
            cout << link[j] << " ";
        }
        cout << endl;
    }

    int start_sum = cal_sum(start);
    int link_sum = cal_sum(link);
    if (DEBUG) {
        cout << "start sum : " << start_sum << endl;
        cout << "Link sum : " << link_sum << endl;
    }

    int ret = -1;
    ret = abs(start_sum - link_sum);
    // cout << "result : " << ret << endl;
    return ret;
}

int sol() {
    int ret = 987654321;
    for (int i = 0; i < (1<<N); i++) {
        // cout << i << endl;
        vector<int> start, link;
        int t_cnt = 0, f_cnt = 0, check[11] ={0,};
        for (int j = 0; j < N; j++) {
            if (i & 1 << j) {
                // cout <<"true:" << j << " ";
                check[j] = true;
                t_cnt++;
            }
            else {
                // cout << "false:" << j <<" ";
                check[j] = false;
                f_cnt++;
            }
        }
        if (t_cnt == (N/2) && f_cnt == (N/2)) {
            for (int j = 0; j < N; j++) {
                if (check[j]) {
                    start.push_back(j);
                }
                else
                    link.push_back(j);
            }
        }
        // cout << endl;
        if (start.size() > 0 && link.size() > 0) {
            ret = min(ret, find_stat(start, link));
        }
    }

    return ret;
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }

    if (DEBUG) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    int ret = -1;
    ret = sol();
    cout << ret << "\n";
    return 0;
}
