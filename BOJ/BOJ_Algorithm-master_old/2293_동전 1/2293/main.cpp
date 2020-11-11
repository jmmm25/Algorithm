//
//  main.cpp
//  2293
//
//  Created by JEONGMIN on 2017. 1. 24..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//
#include <iostream>
using namespace std;
int d[100001];
int a[101];
int main() {
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    d[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= k; j++) {
            d[j] += d[j - a[i]];
        }
    }
    cout << d[k] << "\n";
    return 0;
}


