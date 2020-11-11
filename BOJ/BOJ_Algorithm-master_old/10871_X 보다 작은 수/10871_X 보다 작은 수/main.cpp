//
//  main.cpp
//  10871_X 보다 작은 수
//
//  Created by JEONGMIN on 2018. 1. 10..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
using namespace std;

int n, x;
int number[10001];

int main(int argc, const char * argv[]) {
    cin >> n >> x;
    for (int i=0; i<n; i++) {
        cin >> number[i];
    }
    
    for (int i=0; i<n; i++) {
        if (number[i] < x) {
            cout << number[i] << " ";
        }
    }
    
    cout << "\n";
    return 0;
}
