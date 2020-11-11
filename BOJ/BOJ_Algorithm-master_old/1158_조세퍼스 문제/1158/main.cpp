//
//  main.cpp
//  1158
//
//  Created by JEONGMIN on 2017. 2. 13..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
queue<int> q1;
queue<int> q2;
queue<int> result;


int main(void){
    cin >> n >> m;
    
    for (int i=1; i<=n; i++) {
        q1.push(i);
    }
    
    int order = 1;
    while(!( q1.empty() && q2.empty() )){
        while(!q1.empty()){
            if(order != m){
                q2.push(q1.front());
                q1.pop();
                order++;
            }
            
            else{
                result.push(q1.front());
                q1.pop();
                order = 1;
            }
        }
        
        while(!q2.empty()){
            if(order!=m){
                q1.push(q2.front());
                q2.pop();
                order++;
            }
            
            else{
                result.push(q2.front());
                q2.pop();
                order = 1;
            }
        }
    }
    cout << "<";
    for (int i=0; i<n-1; i++) {
        cout << result.front() << ", ";
        result.pop();
    }
    cout << result.front() << ">";
    
    return 0;
}
