//
//  main.cpp
//  9372
//
//  Created by JEONGMIN on 2017. 2. 27..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

queue<int> q;

int visit[MAX];
int matrix[MAX][MAX];

int t,n,m,u,v;

void init() {
    
    for (int j=1; j<=n; j++) {
        for(int k=1; j<=n; j++) {
            matrix[j][k] = 0;
        }
    }
    for(int k=1; k<=n; k++)
        visit[k] = 0;
    
}

void bfs(int d) {
    int result = 0;
    q.push(d);
    visit[d] = 1;
    
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i=1; i<=n; i++) {
            if(matrix[t][i] == 1 && visit[i] == 0) {
                q.push(i);
                visit[i] = 1;
            }
        }
        result++;
    }
    
    cout << --result << "\n";
    init();
    
}



int main(int argc, const char * argv[]) {
    
    int start = 1;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> m;
        for (int j=1; j<=m; j++) {
            cin >> u >> v;
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
        
        bfs(start);
    }

    return 0;
}
