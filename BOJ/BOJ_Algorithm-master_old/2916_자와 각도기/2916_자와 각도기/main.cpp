//
//  main.cpp
//  2916_자와 각도기
//
//  Created by JEONGMIN on 2017. 10. 10..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int n,k;
int c[11], h[11];
bool result[361];

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%d", &c[i]);
//        cout << c[i];
        result[c[i]] = true;
    }
    
    for (int i=0; i<k; i++) {
        scanf("%d", &h[i]);
//        cout << h[i];
    }
    int val = 0;
    
    while (1) {
        int flag = 0;
        for (int i=0; i<360; i++) {
            for (int j=0; j<360; j++) {
//                cout << i <<" " << j << endl;
                if (result[i] && result[j]) {
                    val = abs(i - j);
                    if (!result[val]) {
                        result[val] = 1;
                        flag = 1;
//                        cout << "새로운 값" << i << "-" << j << "= " << val << endl;
//                        cout << "result["<< val <<"] = " << result[val] << endl;
                    }
                }
            }
        }
        
        for (int i=0; i<360; i++) {
            for (int j=0; j<360; j++) {
                if (result[i] && result[j]) {
                    val = (360 + i + j) % 360;
                    if (!result[val]) {
                        result[val] = 1;
                        flag = 1;
//                        cout << "새로운 값" << i << "+" << j << "= " << val << endl;
//                        cout << "result["<< val <<"] = " << result[val] << endl;
                    }
                }
            }
        }
//        cout << "debug" << endl;

        if (!flag) {
            break;
        }
    }
    
    for (int i=0; i<k; i++) {
        if (result[h[i]]) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
    
    
    return 0;
}
