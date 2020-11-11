//
//  main.cpp
//  11724_연결 요소의 개수
//
//  Created by JEONGMIN on 2018. 1. 18..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj(1001);
vector<bool> isVisited(1001);
int N, M, ret;

void dfs(int v) {
    isVisited[v] = true;
    for (int i=0; i<adj[v].size(); i++) {
        if (!isVisited[adj[v][i]]) {
            dfs(adj[v][i]);
        }
    }
}

// 리스트의 인접한 정점 정렬
void sort_list() {
    for (int i=0; i<N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
}


int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    int u, v;
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    sort_list();
    fill(isVisited.begin(), isVisited.end(), false);
    
    for (int i=1; i<=N; i++) {
        if (!isVisited[i]) {
            dfs(i);
            ret++;
        }
    }
    cout << ret << "\n";
    
    return 0;
}
