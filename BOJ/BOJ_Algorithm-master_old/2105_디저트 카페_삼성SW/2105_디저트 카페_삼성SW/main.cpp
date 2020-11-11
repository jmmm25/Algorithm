//
//  main.cpp
//  2105_디저트 카페_삼성SW
//
//  Created by JEONGMIN on 2017. 10. 20..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
int T, N, map[21][21], isVisited[21][21], isDessert[101], isDirected[5];
// 대각선으로 움직이는 값
int dx[4] = {-1, 1, 1, -1 }; // 우상, 우하, 좌하, 좌상
int dy[4] = {1, 1, -1, -1 }; // 우상, 우하, 좌하, 좌상
int ans = -1;

void dfs(int startr, int startc, int r, int c, int ret, int dir) {
    if (startr == r && startc == c) {
        if (ret != 2) {
            ans = max(ans, ret);
        }
        return;
    }


    for (int i=0; i<4; i++) {
        if (isDirected[i] && i != dir) {
            continue;
        }

        int nr = r + dx[i];
        int nc = c + dy[i];
        if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
            if (isVisited[nr][nc] == 0) {
                if (isDessert[map[nr][nc]] == 0 || (startr == nr && startc == nc)) {
                    isVisited[nr][nc] = 1;
                    isDirected[i] = 1;
                    isDessert[map[nr][nc]] = 1;

                    dfs(startr, startc, nr, nc, ret+1, i);

                    // 다른 곳으로 갔다가 끝나면 다시 원상태로 복귀시켜줌.
                    if (i != dir) {
                        isDirected[i] = 0;
                    }
                    if (startr != nr || startc != nc) {
                        isDessert[map[nr][nc]] = 0;
                    }

                    isVisited[nr][nc] = 0;
                }
            }
        }


    }

}



int main(int argc, const char * argv[]) {
//    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int test=1; test<=T; test++) {
        ans = -1;
        cin >> N;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                scanf("%d", &map[i][j]);
//                cout << map[i][j] << " ";
            }
//            cout << endl;
        }


        for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
                for (int i=0; i<4; i++) {
//                    cout << r << ", " << c << "시작 " << endl;
                    memset(isVisited, 0, sizeof(isVisited));
                    memset(isDessert, 0, sizeof(isDessert));
                    memset(isDirected, 0, sizeof(isDirected));
                    isDessert[map[r][c]] = 1;

                    int nr = r + dx[i];
                    int nc = c + dy[i];
//                    cout << "nr, nc " << nr << "," << nc << endl;
                    if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
                        if (isDessert[map[nr][nc]] == 0) {
                            // 방문 안한 디저드 카페일 때만 들어가야함.
                            isDessert[map[nr][nc]] = 1;
                            // cout << "dfs   " << nr << "," << nc << ","  <<", "<< map[nr][nc] << endl;
                            dfs(r, c, nr, nc, 1, i);  // i는 방향. 어짜피 for : 0~3
                            isDessert[map[nr][nc]] = 0;

                        }

                    }
                }
            }
        }
        cout << "#" << test << " " << ans << "\n";

    }

    return 0;
}
