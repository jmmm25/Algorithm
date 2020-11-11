#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

class Info {
public:
    int id, desk_id ,t;
    Info() {};
    Info(int _id, int _desk_id, int _t):
        id(_id), desk_id(_desk_id), t(_t) {};
};

Info rec_desk[10], rep_desk[10];
int a[10], b[10];
int N, M, K, rec_num, rep_num;
queue<Info> rec_q, rep_q, wait_q;

int sol() {
    Info first_pos = rec_q.front();
    int t = first_pos.t;
    int cnt = 0, ret = -1, total = 0;

    while (cnt < K) {
        // cout << "============== time " << t << " ==============" << endl;

        for (int i = 1; i <= N; i++) {
            if (rec_desk[i].t > 0) {
                rec_desk[i].t--;
                // cout << "rec_desk[" << i << "] -1 감소 " << rec_desk[i].t << endl;
                if (rec_desk[i].t == 0) {
                    rep_q.push(Info(rec_desk[i].id, rec_desk[i].desk_id, 0));
                    // cout << "repair queue push " << rec_desk[i].id << ", " <<  rec_desk[i].desk_id << ", " << 0 << endl;
                    rec_desk[i].id = 0;
                }
            }

            if (rec_desk[i].t == 0) {
                Info client = rec_q.front();
                if (!rec_q.empty() && client.t <= t) {
                    rec_desk[i] = Info(client.id, i, a[i]);
                    // cout << "rec_desk[" << i << "] = " << client.id << ", " << i << ", " << a[i] << endl;
                    rec_q.pop();
                }
            }
        }

        for (int i = 1; i <= M; i++) {
            if (rep_desk[i].t > 0) {
                rep_desk[i].t--;
                // cout << "rep_desk[" << i << "] -1 감소 " << rep_desk[i].t << endl;

                if (rep_desk[i].t == 0) {
                    cnt++;
                    // cout << "repair finish  " << rep_desk[i].id << ", " <<  rep_desk[i].desk_id << ", " << rep_desk[i].t << endl;
                    // cout << "cnt : " << cnt << endl;
                    rep_desk[i].id = 0;

                }
            }

            if (rep_desk[i].t == 0) {
                if (!rep_q.empty()) {
                    Info client = rep_q.front();
                    rep_q.pop();
                    rep_desk[i] = Info(client.id, client.desk_id, b[i]);
                    // cout << "rep_desk[" << i << "] = " << client.id << ", " << client.desk_id << ", " << b[i] << endl;


                    if (i == rep_num && rep_desk[i].desk_id == rec_num) {
                        total += rep_desk[i].id;
                        // cout << "ret find : " << rep_desk[i].id << endl;
                    }
                }
            }

        }
        // cout << "============== result ====================" << endl;
        // for (int i = 1; i <= N; i++) {
        //     cout << "rec_desk[" << i << "] :   " << rec_desk[i].id << endl;
        // }
        // cout << "rec_size : " << rec_q.size() << endl;
        //
        // for (int i = 1; i <= M; i++) {
        //     cout << "rep_desk[" << i << "] :   " << rep_desk[i].id << endl;
        //     cout << "rep_size : " << rep_q.size() << endl;
        // }
        t++;
    }
    ret = total;

    if (ret == -1) {
        return -1;
    }
    else
        return ret;
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    int tc, tt = 1;
    cin >> tc;
    Info m;
    while (tt <= tc) {
        cin >> N >> M >> K >> rec_num >> rep_num;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        for (int j = 1; j <= M; j++) {
            cin >> b[j];
        }
        for (int i = 1; i <= K; i++) {
            int t;
            cin >> t;
            rec_q.push(Info(i, 0, t));
            // cout << "reception queue push : (" << i << ", " << 0 << ", " << t << ")" << endl;
        }

        int ret = sol();
        if (ret > 0)
            cout << "#" << tt << " " << ret << "\n";
        else
            cout << "#" << tt << " " << "-1" << "\n";

        while (!rec_q.empty()) rec_q.pop();
        while (!rep_q.empty()) rep_q.pop();
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        tt++;
    }

    return 0;
}
