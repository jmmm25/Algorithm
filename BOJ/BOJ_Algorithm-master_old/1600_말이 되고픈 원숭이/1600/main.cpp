//
//  main.cpp
//  1600
//
//  Created by JEONGMIN on 2017. 9. 21..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
int k, w, h, state;
int map[202][202] = {0,};
int isVisited[202][202][32] = {0,};
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
int kdx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int kdy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };
int nr, nc;
class info {
public:
    int cr, cc, cm ,cnt;
    info() {};
    info(int _cr, int _cc, int _cm, int _cnt):
        cr(_cr), cc(_cc), cm(_cm), cnt(_cnt) {};
};
int bfs(int k);

int main(int argc, const char * argv[]) {
    cin >> k >> w >> h;
    //    cout << k << w << h << endl;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            scanf("%d", &state);
            map[i][j] = state;
            //            printf("%d ", state);
        }
        //        printf("\n");
    }
    cout << bfs(k) << "\n";
    return 0;
}



int bfs(int k) {
    queue<info> que;
    que.push(info(0, 0, k, 0));
    isVisited[0][0][0] = 1;
    isVisited[0][0][1] = 1;
    
    
    while (!que.empty()) {
        info mInfo = que.front();
        int r = mInfo.cr;
        int c = mInfo.cc;
        int m = mInfo.cm;
        int cnt = mInfo.cnt;
        que.pop();
        isVisited[r][c][m] = 1;
        
//        cout << "queue pop! : " << r << c << m << cnt << endl;
        
        // 종료 조건
        if (c == w-1 && r == h-1) {
            return cnt;
        }
        
        for (int i=1; i<=4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
//            cout << nr<<"   "<<nc << endl;
            if (nr < 0 || nc<0 || nr >= h || nc >= w || map[nr][nc] == 1) {
                continue;
            }
            if (isVisited[nr][nc][m] == 1) {
                continue;
            }
            isVisited[nr][nc][m] = 1;
//            cout << nr << nc << m << "방문1" << endl;
            que.push(info(nr,nc, m, cnt+1));
//            cout << "queue push!! : " << nr << nc << m << cnt+1 << endl;
        }
        
        if(m == 0) continue;
        
        for (int i = 0; i < 8; i++) {
            int nr = r + kdx[i];
            int nc = c + kdy[i];
//            cout << nr<<"   "<<nc << endl;
            if (nr < 0 || nc<0 || nr >= h || nc >= w || map[nr][nc] == 1) {
                continue;
            }
            if (isVisited[nr][nc][m-1] == 1) {
                continue;
            }
            isVisited[nr][nc][m-1] = 1;
//            cout << nr << nc << m-1 << "방문1" << endl;
            
            que.push(info(nr, nc, m - 1, cnt + 1));
//            cout << "queue push!! : " << nr << nc << m-1 << cnt+1 << endl;
        }
    }
    
    if (que.empty()) {
        return -1;
    }
    
    return 0;
}

