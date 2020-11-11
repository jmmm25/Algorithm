//
//  main.cpp
//  11047_동전0
//
//  Created by JEONGMIN on 2018. 1. 11..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>

using namespace std;

int N, K, price[11];

int sol() {
    int ret = 0;
    int quotient = 0;
    int remain_price = K;
    
    for (int i=N-1; i>=0; i--) {
        if (remain_price / price[i] > 0) {
            quotient = remain_price / price[i];
            remain_price %= price[i];
            ret += quotient;
//            cout << price[i] << " : " << quotient << "개" << "\n";
        }
        
        if (remain_price == 0) {
            break;
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    int ret = 0;
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        cin >> price[i];
    }
    
    ret = sol();
    cout << ret << "\n";
    
    return 0;
}
