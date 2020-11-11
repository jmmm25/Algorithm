//
//  main.cpp
//  2331_반복수열
//
//  Created by JEONGMIN on 2018. 1. 19..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, P;
bool isCheck[236197];
vector<int> v;

int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    int cnt = 0;
    cin >> N >> P;
    v.push_back(N);
    while (!isCheck[N]) {
        int ret = 0;
        isCheck[N] = true;
        for (int i=N; i>0; i/=10) {
            ret += pow(i % 10, P);
        }
        v.push_back(ret);
        N = ret;
    }
    
    for (int i=0; i<v.size(); i++) {
        if (v.at(i) == N) {
            break;
        }
//        cout << v.at(i) << " ";
        cnt++;
    }
    
    cout << cnt << "\n";
    return 0;
}
