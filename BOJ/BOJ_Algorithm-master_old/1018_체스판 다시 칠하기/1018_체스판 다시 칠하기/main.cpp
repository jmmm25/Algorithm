
//  main.cpp
//  1018_체스판 다시 칠하기
//
//  Created by JEONGMIN on 2018. 1. 8..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

#define MOVE_CNT    8
#define MAX_INF     987654321

using namespace std;


int n,m;
char map[51][51];
string white_chess[8], black_chess[8];

void make_chess() {
    for (int i=0; i<8; i++) {
        if (i%2 == 0) {
            white_chess[i] = "WBWBWBWB";
            black_chess[i] = "BWBWBWBW";
        }
        else {
            black_chess[i] = "WBWBWBWB";
            white_chess[i] = "BWBWBWBW";
        }
    }
}


int sol(int r, int c) {
    int white_ret = 0, black_ret = 0, ret = 0;
//    cout << "sol Start : " << endl;
    for (int i=r; i<r+MOVE_CNT; i++) {
        for (int j=c; j<c+MOVE_CNT; j++) {
            if (map[i][j] != white_chess[i-r][j-c]) {
                white_ret++;
            }
            
            if (map[i][j] != black_chess[i-r][j-c]) {
                black_ret++;
            }
        }
    }
    
//    cout << "결과 값 : "<< white_ret << " " << black_ret << endl;
    ret = min(white_ret, black_ret);
    
    return ret;
}

int main(int argc, const char * argv[]) {
    int ret = MAX_INF;
    cin >> n >> m;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }
    
    make_chess();
//    for (int i=0; i<n; i++) {
//        for (int j=0; j<m; j++) {
//            cout << black_chess[i][j];
//        }
//        cout << "\n";
//    }
    

    for (int i=0; i<=n - MOVE_CNT; i++) {
        for (int j=0; j<=m - MOVE_CNT; j++) {
//            cout << "ret : " << ret << endl;
            ret = min(ret, sol(i,j));
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
