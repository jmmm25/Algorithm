//
//  main.cpp
//  2309_일곱난쟁이
//
//  Created by JEONGMIN on 2018. 1. 2..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define PEOPLE 9
#define FINDVALUE 100
using namespace std;

int weight[10];


int sumOfWeight() {
    int sum = 0;
    for (int i=0; i<PEOPLE; i++) {
        sum += weight[i];
    }
//    cout << sum << "    Sum value" << endl;
    return sum;
}

int sol() {
    int ret = 0;
    int sum = sumOfWeight();
//    cout << "Sum : " << sum << endl;
    for (int i=0; i<PEOPLE-1; i++) {
        for (int j=i+1; j<PEOPLE; j++) {
            if ( (sum - (weight[i] + weight[j])) == FINDVALUE) {
//                cout << "remove value" << weight[i] << "," << weight[j] << endl;
                weight[i] = weight[j] = 0;
                return ret;
            }
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    for (int i=0; i<PEOPLE; i++) {
        scanf("%d", &weight[i]);
//        cout << weight[i] << endl;
    }
    
    sol();

    sort(weight, weight+PEOPLE);
    
    for (int i=2; i<PEOPLE; i++) {
        cout << weight[i] << "\n";
    }
    
    return 0;
}
