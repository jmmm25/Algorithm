//
//  main.cpp
//  1182_부분집합의 합
//
//  Created by JEONGMIN on 2018. 1. 10..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>

using namespace std;

int N, S, ret, abs_s;
int number[21];
int flag[21];

void powerset(int n, int depth) {
    if (n == depth) {
        int sum = 0;
//        cout << " 부분집합 : ";
        for (int i=0; i<n; i++) {
            if (flag[i] == 1) {
//                cout << number[i] << " ";
                sum += number[i];
            }
        }
//        cout << " --> 합계 : " <<  sum << endl;
        if (sum == S) {
            ret++;
        }
        return;
    }
    flag[depth] = 1;
    powerset(n, depth+1);
    flag[depth] = 0;
    powerset(n, depth+1);
}


int main(int argc, const char * argv[]) {
    cin >> N >> S;
    for (int i=0; i<N; i++) {
        cin >> number[i];
    }
    powerset(N, 0);
    
    // 만약 S가 0이라면, 공집합일 경우도 포함이 되므로 -1을 해주어야 한다.
    if (S == 0) {
        ret -= 1;
    }
    cout << ret << "\n";
    
    
    return 0;
}
