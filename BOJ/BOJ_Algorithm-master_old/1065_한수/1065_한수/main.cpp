//
//  main.cpp
//  1065_한수
//
//  Created by JEONGMIN on 2018. 1. 25..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int n, cnt;
int number[3];

int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    cin >> n;
//    cout << "n : " << n << endl;
    cnt = 0;
    for (int i=1; i<1000; i++) {
        // exit condition.
        if (i > n) {
            break;
        }
        // 100 이하의 모든 수는 한수로 인정이 된다.
        if (i < 100) {
            cnt++;
//            cout << "i : " << i << "     cnt : "<< cnt <<endl;
        }
        // 100이상은 등차 수열을 확인
        else {
            int pos = 2;
            for (int j=i; j>0; j/=10) {
                number[pos] = j % 10;
                pos--;
            }
            if ((number[0] <= number[1] && number[1] <= number[2] ) || (number[0] >= number[1] && number[1] >= number[2])) {
                if (abs(number[2] - number[1]) == abs(number[1] - number[0])) {
                    cnt++;
                }
            }
//            cout << "number : "<<number[0] << " " << number[1] << " " << number[2] << " cnt : " << cnt <<endl;
            memset(number, 0, sizeof(number));

        }
    }
    
    cout << cnt << "\n";
    
    return 0;
}
