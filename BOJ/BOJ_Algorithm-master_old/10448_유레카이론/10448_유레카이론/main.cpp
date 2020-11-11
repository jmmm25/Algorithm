//
//  main.cpp
//  10448_유레카이론
//
//  Created by JEONGMIN on 2018. 1. 5..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>

#define MAX_N 46
using namespace std;

int samgaksu[MAX_N];

int sol(int k) {
    for (int i=1; i<MAX_N; i++) {
        for (int j=1; j<MAX_N; j++) {
            for (int z=1; z<MAX_N; z++) {
                if ((samgaksu[i] + samgaksu[j] + samgaksu[z]) == k){
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    int tc = 0, k = 0;
    cin >> tc;
    
    for (int i=1; i<MAX_N; i++) {
        samgaksu[i] = (i*(i+1))/2;
    }

    for (int testCase = 0; testCase < tc; testCase++) {
        cin >> k;
        cout << sol(k) << "\n";
    }
    
    return 0;
}
