#include <iostream>
#include <queue>
using namespace std;

int check[200002];
int N, K;

void bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(N, 0));
    check[N] = 1;
    int cnt = 0, t = -9876;

    while (!q.empty()) {
        pair<int, int> m = q.front();
        // cout << "pop : " << m.first << ", " << m.second << endl;
        check[m.first] = 1;
        q.pop();

        if (t + 1 == m.second) {
            // cout << " m.second : " << m.second << endl;
            break;
        }

        if (m.first == K) {
            cnt++;
            // cout << "m.first == K -->  " << K << "\t ";
            // cout << "cnt : " << cnt << endl;
            t = m.second;
        }

        if (m.first + 1 <= 100000 && !check[m.first + 1]) {
            // cout << "push : " << m.first + 1 << endl;
            q.push(make_pair(m.first + 1, m.second + 1));
        }

        if (m.first - 1 >= 0 && !check[m.first - 1]) {
            // cout << "push : " << m.first - 1 << endl;
            q.push(make_pair(m.first - 1, m.second + 1));
        }

        if (m.first * 2 <= 200000 && !check[m.first * 2]) {
            // cout << "push : " << m.first * 2 << endl;
            q.push(make_pair(m.first * 2, m.second + 1));
        }
    }
    cout << t << "\n";
    cout << cnt << "\n";
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt","r", stdin);
    cin >> N >> K;
    bfs();
    return 0;
}
