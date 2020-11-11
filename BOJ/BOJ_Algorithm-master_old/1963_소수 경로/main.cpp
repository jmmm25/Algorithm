#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

class Info {
public:
    int data, ret;
    Info() {};
    Info(int _data, int _ret) :
        data(_data), ret(_ret) {};
};

int prime[10000];
bool check[10000];
int arrA[4], arrB[4];


int bfs(int start, int finish) {
    int data = 0, cnt = 0, ret = 0, n = 3;
    queue<Info> q;
    Info m;
    q.push(Info(start, ret));
    check[start] = true;

    while (!q.empty()) {
        m = q.front();
        data = m.data;  ret = m.ret;
        // cout << "check" << check[8179] << endl;
        q.pop();
        if (data == finish) {
            return ret;
        }

        for (size_t j = data; j > 0; j/=10) {
            arrA[n--] = j%10;
        }

        for (size_t i = 1000; i < 10000; i++) {
            if (check[i]) continue;

            cnt = 0, n = 3;
            if (prime[i] == 0) {
                continue;
            }
            else{
                for (size_t k = i; k > 0; k/=10) {
                    arrB[n--] = k%10;
                }

                for (size_t j = 0; j < 4; j++) {
                    if (arrA[j] == arrB[j]) {
                        cnt++;
                    }
                }
                if (cnt == 3) {
                    q.push(Info(i, ret+1));
                    check[i] = true;
                    // cout <<"push : " <<  i << "ret : " << ret+1 << endl;
                }
            }
        }
    }
    return -1;
}


int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    int tc, start, finish;
    cin >> tc;
    for (int i = 2; i < 10000; i++) {
        prime[i] = i;
    }
    for (int i = 2; i < sqrt(10000); i++) {
        if (prime[i] == 0) {
            continue;
        }
        for (int j = i+i; j < 10000 ; j+=i) {
            prime[j] = 0;
        }
    }

    while (tc--) {
        int ret = -1;
        cin >> start >> finish;
        if (start == finish) {
            cout << "0" << "\n";
            continue;
        }

        ret = bfs(start, finish);
        if (ret < 0)
            cout << "Impossible" << "\n";
        else
            cout << ret << endl;

        memset(check, false, sizeof(check));
    }
    return 0;
}
