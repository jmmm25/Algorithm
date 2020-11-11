//
//  main.cpp
//  11651
//
//  Created by JEONGMIN on 2017. 1. 23..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,int> &u, const pair<int,int> &v){
    if(u.second < v.second)
        return true;
    else if(u.second == v.second)
        return u.first < v.first;
    else
        return false;
}

int main(void){
    int n;
    cin >> n;
    
    vector<pair<int,int>> vc(n);
    for (int i=0; i<n; i++) {
        cin >> vc[i].first >> vc[i].second;
    }
    
    sort(vc.begin(), vc.end(), cmp);
    
    for (int i=0; i<n; i++) {
        cout << vc[i].first << ' ' << vc[i].second;
        cout << "\n";
    }
    
    return 0;
}
