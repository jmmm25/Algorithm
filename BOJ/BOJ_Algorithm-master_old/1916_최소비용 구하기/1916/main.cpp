//
//  main.cpp
//  1916
//
//  Created by JEONGMIN on 2017. 1. 27..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//
// INF의 값을 백만이상으로 해줬더니 정답.

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

#define INF 100000001

using namespace std;
//오름차순 큐.
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
vector< pair<int,int> > node[1001];

int n,m;
int dijkstra(int start, int arrive);

int main(int argc, const char * argv[]) {
    cin >> n;
    cin >> m;
    int u,v,w,start,arrive;
    
    for (int i=0; i<m; i++) {
        cin >> u >>v >> w;
        node[u].push_back(make_pair(v,w));
    }
    cin >> start >> arrive ;
    cout << dijkstra(start, arrive) << "\n";
    
    return 0;
}

int dijkstra(int start, int arrive){
    int minCost[1001] = {0,},u=0;
    for (int i=1; i<=n; i++) {
        if(i!=start)
            minCost[i] = INF;
        else{
            q.push(make_pair(minCost[i], i)); //q의 first는 weight, second는 node의 번호.
        }
    }
    minCost[start] = 0;
    
    while(!q.empty()){
        u = q.top().second;
        q.pop();
        for (int i=0; i<node[u].size(); i++) {
            if(minCost[u] + node[u][i].second < minCost[ node[u][i].first ]){
                minCost[ node[u][i].first ] = minCost[u] + node[u][i].second;
                q.push(make_pair(minCost[ node[u][i].first ] , node[u][i].first) );
            }
        }
    }
    return minCost[arrive];
}
