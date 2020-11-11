//
//  main.cpp
//  2503_숫자야구
//
//  Created by JEONGMIN on 2018. 1. 5..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#define MAXIMUM_NUMBER 987
using namespace std;

bool isCheck[1001];

bool sol(int inputNumber, int jNumber, int strikeCnt, int ballCnt) {
    int iNum1, iNum2, iNum3;
    int jNum1, jNum2, jNum3;
    int str = 0, ball = 0;
    iNum1 = inputNumber/100;
    iNum2 = (inputNumber % 100) / 10;
    iNum3 = (inputNumber % 100) % 10;
    
//    cout << endl <<"strike , ball = " << strikeCnt << " " << ballCnt << endl;
//    cout << "input : " << inputNumber;
//    cout << " 의 각 자리의 수 : 백 십 일 : " << iNum1 << " " << iNum2 << " " << iNum3 << endl;

    jNum1 = jNumber/100;
    jNum2 = (jNumber % 100) / 10;
    jNum3 = (jNumber % 100) % 10;
    
//    cout << "jNumber : " << jNumber;
//    cout << " 의 각 자리의 수 : 백 십 일 : " << jNum1 << " " << jNum2 << " " << jNum3 << endl;
    
    if (jNum1 == 0 || jNum2 == 0 || jNum3 == 0|| jNum1 == jNum2 || jNum2 == jNum3 || jNum1 == jNum3) {
        return false;
    }
    
    if (iNum1 == jNum1) str++;
    if (iNum2 == jNum2) str++;
    if (iNum3 == jNum3) str++;
    if (iNum1 == jNum2 || iNum1 == jNum3) ball++;
    if (iNum2 == jNum1 || iNum2 == jNum3) ball++;
    if (iNum3 == jNum1 || iNum3 == jNum2) ball++;
    
//    cout << "결과 값 : " << str << " " << ball << endl;
    if (strikeCnt == str && ballCnt == ball) {
        return true;
    }
    
    return false;
}


int main(int argc, const char * argv[]) {
    int n, input, str, ball;
    int ret = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> input >> str >> ball;
        for (int j=123; j<= MAXIMUM_NUMBER; j++) {
            if (isCheck[j] == false) {
                isCheck[j] = !sol(input, j, str, ball);
//                cout << "isCheck : " << isCheck[j] << endl;
            }
        }
    }
    
    for (int i=123; i<= MAXIMUM_NUMBER; i++) {
        if (isCheck[i] == false) {
//            cout << i << endl;
            ret++;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
