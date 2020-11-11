//
//  main.cpp
//  4796_캠핑
//
//  Created by JEONGMIN on 2018. 1. 11..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
using namespace std;

int l, p, v;

int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    int i = 1;
    while (true) {
        int ret = 0;
        cin >> l >> p >> v;
        int mok = 0;
        
        if (l == 0 && p == 0 && v == 0) {
            break;
        }
        
        if (l > 1 && p > l && v > p) {
            mok = v / p;
            v = v % p;
            
            if (v > l) {
                ret = (mok * l) + l;
            }
            else
                ret = (mok * l) + v;
            
            cout << "Case " << i << ": " << ret << "\n";
            i++;
        }
    }

    return 0;
}
