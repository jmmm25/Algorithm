//
//  main.cpp
//  2602
//
//  Created by JEONGMIN on 2017. 9. 18..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//
#include <iostream>
#include <cstring>

using namespace std;

int cache[101][21][2], slen, alen;
string str, a[2];

int sol(int scur, int acur, int locs) {
    if (acur == slen-1) {
        return 1;
    }
    
    int &ret = cache[scur][acur][locs];
    if (ret != -1) {
        return ret;
    }
    ret = 0;

    for (int i=scur+1; i<alen; i++) {
        if (str[acur+1] == a[1-locs][i]) {
            ret += sol(i, acur+1, 1-locs);
        }
    }
    
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin >> str ;
    cin >> a[0] >> a[1];
//    cout << str << a[0] << a[1];
    slen = (int)str.size();
    alen = (int)a[0].size();
    
    memset(cache, -1, sizeof(cache));
    int ret = 0;
    for (int i=0; i<alen; i++) {
        if (str[0] == a[0][i]) {
            ret += sol(i, 0, 0);
        }
        if (str[0] == a[1][i]) {
            ret += sol(i, 0, 1);
        }
    }
    
    cout << ret <<"\n";
    
    return 0;
}
