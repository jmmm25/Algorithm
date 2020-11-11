//
//  main.cpp
//  2231_분해합
//
//  Created by JEONGMIN on 2018. 1. 3..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX_VALUE 1000000
#define TRY_NUMBER 198

using namespace std;

int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    int input = 0;
    // input 조건
    if (input <= 0 && input >= 1000001) {
        return -1;
    }
    scanf("%d", &input);
    
    for (int i = 1; i <= MAX_VALUE; i++) {
        int number = i;
        int creatorNumber = 0;
        creatorNumber += number;
        
        while (number != 0) {
            int rest = number % 10;
            creatorNumber += rest;
            number /= 10;
        }
        
        if (creatorNumber == input) {
            cout << i << "\n";
            break;
        }
        
        if (i+1 > MAX_VALUE) {
            cout << "0" << "\n";
        }
    }
    return 0;
}
