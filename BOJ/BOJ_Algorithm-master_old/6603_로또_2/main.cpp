#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int num[14], flag[14];
void dfs(int cur, int cnt) {
    if (cur == N && cnt == 6) {
        for (int i = 0; i < N; i++) {
            if (flag[i]) {
                cout << num[i] << " ";
            }
        }
        cout << endl;
    }

    if (cur == N) return;
    flag[cur] = 1;
    dfs(cur+1, cnt+1);
    flag[cur] = 0;
    dfs(cur+1, cnt);
}

// void sol() {
//     int cnt = 0;
//     vector<int> v;
//     for (int i = 0; i < (1<<N); i++) {
//         for (int j = 0; j < N; j++) {
//             if (i & (1 << j)) {
//                 v.push_back(num[j]);
//                 // cout << num[j] << " ";
//             }
//         }
//         if (v.size() == 6) {
//             for (int i = 0; i < v.size(); i++) {
//                 cout << v[i] << " ";
//             }
//             cout << endl;
//         }
//         v.clear();
//     }
// }
int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    while (true) {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            cin >> num[i];
            // cout << num[i] << " ";
        }
        dfs(0, 0);
        memset(flag, 0, sizeof(flag));
        memset(num, 0, sizeof(num));
        cout << endl;
    }
    return 0;
}
