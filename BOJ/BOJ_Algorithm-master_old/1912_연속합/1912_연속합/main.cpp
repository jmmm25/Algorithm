//
//  main.cpp
//  1912_연속합
//
//  Created by JEONGMIN on 2018. 1. 10..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#define MIN_INF     (-1000)

using namespace std;

int n, number[100001];

int main(int argc, const char * argv[]) {
    int ret = MIN_INF;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> number[i];
    }
    
    cout << ret << "\n";
    
    return 0;
}
