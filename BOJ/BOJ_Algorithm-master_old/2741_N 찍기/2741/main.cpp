//
//  main.cpp
//  2741
//
//  Created by JEONGMIN on 2017. 9. 10..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int number;
    cin >> number;
    
    if (number<=0) {
        cout << "not a natural number\n";
    }
    else {
        for (int i=1; i<=number; i++) {
            cout << i;
            cout <<"\n";
        }
    }
    
    return 0;
}
