//
//  main.cpp
//  1260_DFS와 BFS
//
//  Created by JEONGMIN on 2018. 1. 16..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

#define TRUE    1
#define FALSE   0

using namespace std;
int N, M, V;
int graph[1001][1001];
int isVisited[1001];
queue<int> q;

void bfs(int V) {
    int u = 0;
    q.push(V);
    isVisited[V] = TRUE;

    while (!q.empty()) {
        u = q.front();
        cout << u << " ";
        q.pop();
        for (int i=1; i<=N; i++) {
            if (graph[u][i] && !isVisited[i]) {
                q.push(i);
                isVisited[i] = TRUE;
            }
        }
    }
}

void dfs(int V) {
    isVisited[V] = TRUE;
    cout << V << " ";

    for (int i=1; i<=N; i++) {
        if (graph[V][i] && !isVisited[i]) {
            dfs(i);
        }
    }
}


void add_edge() {
    int u, v;
    for (int i=0; i<M; i++) {
        cin >> u >> v;
        graph[u][v] = TRUE;
        graph[v][u] = TRUE;
    }
}

int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    cin >> N >> M >> V;
    add_edge();

    dfs(V);
    cout << "\n";
    memset(isVisited, FALSE, sizeof(isVisited));
    bfs(V);
    cout << "\n";

    return 0;
}
