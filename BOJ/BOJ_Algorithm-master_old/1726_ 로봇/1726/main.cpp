//
//  main.cpp
//  1726
//
//  Created by JEONGMIN on 2017. 9. 21..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
class mInfo {
public:
    int cr, cc, cp, cnt;
    mInfo(){};
    mInfo(int _cr, int _cc, int _cp, int _cnt) :
        cr(_cr), cc(_cc), cp(_cp), cnt(_cnt){};
};

int map[101][101] = {0,};
int isVisited[101][101][5] = {0,};
int dr[5] = { 0, 0, 0, 1, -1 };
int dc[5] = { 0, 1, -1, 0, 0 };

int opPos(int p) {
    if (p==1) {
        return 2;
    }
    if (p==2) {
        return 1;
    }
    if (p==3) {
        return 4;
    }
    if (p==4) {
        return 3;
    }
    return 0;
}

int main() {
    int r,c; cin >> r >> c;
    for (int i=1;i<=r ; i++) {
        for (int j=1; j<=c; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int sr, sc, sp, fr, fc, fp;
    cin >> sr >> sc >> sp >> fr >> fc >> fp;
    queue<mInfo> que;
    que.push(mInfo(sr, sc, sp, 0));
    isVisited[sr][sc][sp] = 1;

    while (!que.empty()) {
        mInfo m = que.front();
        int qr, qc, qp, qcnt;
        qr = m.cr; qc = m.cc; qp = m.cp; qcnt = m.cnt;
//        cout << "que pop: " << qr << " " << qc << " "<< qp << " "<< qcnt << endl;

        if (qr == fr && qc == fc && qp == fp) {
            cout << qcnt << "\n";
            break;
        }

        que.pop();
        //3번까지 움직일 수 있으므로
        for (int k=1; k<=3; k++) {
            int nr = qr + dr[qp] * k;
            int nc = qc + dc[qp] * k;
//            cout << nr <<  " " << nc << endl;
            if (nr < 1 || nc < 1 || nr > r || nc > c || map[nr][nc] == 1) {
                break;
            }
            if (isVisited[nr][nc][qp] == 1) {
                continue;
            }
            isVisited[nr][nc][qp] = 1;
//            cout << isVisited[nr][nc][qp] << endl;

            que.push(mInfo(nr, nc, qp, qcnt +1));
//            cout <<"que push: " << nr << " "<< nc << " "<< qp << " "<< qcnt + 1 << endl;
        }

        // 방향 전환 --> 동 1 서 2 남 3 북 4
        for (int i=1; i<=4; i++) {
            if (qp == i || opPos(qp) == i) {
                continue;
            }
            if (isVisited[qr][qc][i] != 1) {
                isVisited[qr][qc][i] = 1;
                que.push(mInfo(qr,qc,i,qcnt+1));
//                cout <<"que push: " <<qr << " "<< qc<< " " << i<< " " << qcnt + 1 << endl;
            }
        }
    }

    return 0;
}
