//
//  main.cpp
//  algospot_소풍(PICNIC)
//
//  Created by JEONGMIN on 2018. 1. 2..
//  Copyright © 2018년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
bool isSelected[11];
int areFriends[11][11];

int countPairings(bool isSelected[11]) {
    int firstFre = -1;
    for (int i=0; i<n; i++) {
        if (!isSelected[i]) {
            firstFre = i;
            break;
        }
    }
//    cout << "firstFre value : " << firstFre << endl;
    
    if (firstFre == -1) {
//        cout << "return 완료 " << endl;
        return 1;
    }
    
    int ret = 0;
    for (int pairWith = firstFre + 1; pairWith < n; pairWith++) {
        if (!isSelected[pairWith] && areFriends[firstFre][pairWith]) {
            isSelected[firstFre] = isSelected[pairWith] = true;
//            cout << "firstFre, pairWith = " << firstFre << ", " << pairWith << endl;
//            cout << "isSelected True" << endl << "재귀 시작" << endl;
            ret += countPairings(isSelected);
            isSelected[firstFre] = isSelected[pairWith] = false;
//            cout << "isSelected false" << endl;
        }
    }
    
    
    
    return ret;
}

int main(int argc, const char * argv[]) {
//    freopen("input.txt", "r", stdin);
    int tc = 0, ret = -1;
    scanf("%d", &tc);
//    cout << tc << endl;
    for (int i=0; i<tc; i++) {
//        cout << "Test Case : " << i << endl;
        cin >> n >> m;
//        cout << n << " " << m << endl;
        for (int j=0; j<m; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
//            cout << x << " " << y << endl;
            areFriends[x][y] = areFriends[y][x] = 1;
//            cout << "friends : " << x << " " << y << " :  " << areFriends[x][y] << ",  " << y << " " << x  << " : " << areFriends[y][x] << endl;
        }
        
        ret = countPairings(isSelected);
//        cout << "result value = " << ret << endl;
        cout << ret << "\n";
        memset( areFriends, 0, sizeof(areFriends) );
        memset( isSelected, 0, sizeof(isSelected) );
    }
    
    
    return 0;
}
