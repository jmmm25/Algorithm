//
//  main.cpp
//  1753
//
//  Created by JEONGMIN on 2017. 1. 24..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#define INF 100000

using namespace std;
priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > myQ;
vector< pair<int,int> > node[20001];

int dijkstra(int start);
int n,e,start,u,v,w;


int main(){
    cin >> n >> e;
    cin >> start;
    
    for (int i=1; i<=e; i++) {
        cin >> u >> v >> w;
        node[u].push_back(make_pair(v, w));
    }
    
    dijkstra(start);
    
    return 0;
}

int dijkstra(int start){
    int length[20001];
    for (int i=1; i<= n; i++) {
        if(i != start)
            length[i] = INF;
        else
            myQ.push(make_pair(length[i],i));
    }
    length[start] = 0;
    
    while(!myQ.empty()){
        u = myQ.top().second;
        myQ.pop();
        for (int j=0; j<node[u].size(); j++) {
            if(length[u] + node[u][j].second < length[ node[u][j].first ]){
                length[ node[u][j].first ] = length[u] + node[u][j].second;
                myQ.push(make_pair(length[node[u][j].first], node[u][j].first));
            }
        }
    }
    
    for (int i=1; i<=n; i++) {
        if(length[i] != INF)
            cout << length[i] << "\n";
        else
            cout << "INF" << "\n";
    }

    return 0;
}
