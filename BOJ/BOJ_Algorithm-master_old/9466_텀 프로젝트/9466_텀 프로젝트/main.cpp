//
//  main.cpp
//  9466_텀 프로젝트
//
//  Created by JEONGMIN on 2018. 1. 24..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int vertex[100001];
bool isVisited[100001], isFinished[100001];
int t, n, flag, cnt;

void dfs(int curr_v) {
    isVisited[curr_v] = true;
    int next_v = vertex[curr_v];
//    cout << "next_v : " << next_v << endl;
    if (!isVisited[next_v]) {
//        cout << "next_v dfs 재귀 go " << endl;
        dfs(next_v);
    }
    else {
        if (!isFinished[next_v]) {
            for (int x = next_v; curr_v != x ; x = vertex[x]) {
                cnt++;
            }
            cnt++;
            
//            cout << "curr_v일 때 cnt : " << cnt << endl;
        }
    }
    isFinished[curr_v] = true;
}

int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    cin >> t;
    for (int tc = 0; tc<t; tc++) {
        cin >> n;
        
        cnt = 0;
        memset(vertex, 0, sizeof(vertex));
        memset(isVisited, 0, sizeof(isVisited));
        memset(isFinished, 0, sizeof(isFinished));
        
        for (int i=1; i<=n; i++) {
            cin >> vertex[i];
        }
//        for (int i=1; i<=n; i++) {
//            cout << vertex[i] << " ";
//        }
        for (int i=1; i<=n; i++) {
            if (!isVisited[i]) {
//                cout << i << "일 때 dfs 호출 go " << endl;
                dfs(i);
            }
        }
        
        cout << n - cnt << "\n";
    }
    return 0;
}
