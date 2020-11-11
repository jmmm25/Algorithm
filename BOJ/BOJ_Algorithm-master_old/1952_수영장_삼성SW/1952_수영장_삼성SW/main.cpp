//
//  main.cpp
//  1952_수영장_삼성SW
//
//  Created by JEONGMIN on 2017. 10. 16..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 9999999;

using namespace std;

int tc, price[4], month[13], cache[13];

int sol(int cur) {
    if (cur > 12) {
        return 0;
    }
    int &ret = cache[cur];
    if (ret != -1) {
        return ret;
    }
    ret = INF;
    
//    cout << "현재 ret : " << ret << endl;
    ret = min(ret, month[cur] * price[0] + sol(cur+1));
//    cout << cur <<" ~ 12월까지 총 1일권 계산 값 : " <<month[cur]*price[0]+sol(cur+1) << endl;
    ret = min(ret, price[1] + sol(cur+1));
//    cout << cur <<"월의 총 1달권 계산 값 : " <<price[1]+sol(cur+1) << endl;
    ret = min(ret, price[2] + sol(cur+3));
//    cout << cur <<"월의 총 3달권 계산 값 : " <<price[2]+sol(cur+1) << endl;
//    cout << "min ret 값:" << ret << endl;
    return ret;
    
}

int main(int argc, const char * argv[]) {
    scanf("%d", &tc);
    for (int i=0; i<tc; i++) {
        for (int i=0; i<4; i++) {
            scanf("%d", &price[i]);
//            cout << price[i] << endl;
        }
        for (int i=1; i<=12; i++) {
            scanf("%d", &month[i]);
//            cout << month[i] << " ";
        }
        memset(cache, -1, sizeof(cache));
        int ret = 0;
        
        ret = min(price[3] ,sol(1));
        cout << "#" << i+1 << " " << ret << "\n";
    }
    
    return 0;
}
