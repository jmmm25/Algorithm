//
//  main.cpp
//  1966_프린터 큐
//
//  Created by JEONGMIN on 2018. 1. 28..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <queue>

#define TRY_NUMBER      2

using namespace std;

int n, m, order;

int main(int argc, const char * argv[]) {
    int tc = 0;
    freopen("input.txt", "r", stdin);
    cin >> tc;
    while (tc > 0) {
        int ret = 0;
        queue<pair<int, int> > q;
        priority_queue<int> pq;
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            cin >> order;
            pq.push(order);
            q.push(make_pair(i, order));
        }
        
        while (!q.empty()) {
            int first = q.front().first;
            int second = q.front().second;
            q.pop();
//            cout << "first , second : " << first << ", " << second << endl;
            if (second == pq.top()) {
//                cout << "pq top 같음 :  "<< pq.top() << endl;
                pq.pop();
                ret++;
                if (first == m) {
                    break;
                }
            }
            else {
                q.push(make_pair(first, second));
            }
        }
        tc--;
        cout << ret << "\n";
    }
    return 0;
}
