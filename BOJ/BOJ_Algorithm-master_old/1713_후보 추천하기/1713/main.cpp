//
//  main.cpp
//  1713
//
//  Created by JEONGMIN on 2017. 9. 25..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//
//
//  main.cpp
//  1713
//
//  Created by JEONGMIN on 2017. 9. 25..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct info {
    int value;
    int total;
    int req;
};

int n, totV, can;
int size = 0;
int ret = -1;
int arr[1001] = {0,};
int final[21] = {0,};

bool compare(int &a, int &b)
{
    return a > b;
}

int sol() {
    int flag = 0;
    info student[21];
    memset(student, -1, sizeof(student));
    info temp;
    for (int i=0; i<totV; i++) {
        flag = 0;
        temp.value = arr[i];
        temp.total = 1;
        temp.req = i;
        
        // student 배열에 값이 들어있으면 추천 수 늘림.
        for (int j=0; j<n; j++) {
            if (temp.value == student[j].value) {
                student[j].total++;
                flag = 1;
                break;
            }
        }
        
        if (flag == 1) {
            continue;
        }
        
        // 사이즈가 n이 안되면 액자가 비어있으므로 걍 넣음
        if (size < n) {
            student[size++] = temp;
        }
        
        // 사이즈가 n 넘어가면, 액자 바꿔치기할 것
        else {
            int minCnt = 11111;
            int minIdx = -1;
            int req = 11111;
            
            for (int k=0; k<n; k++) {
                if (student[k].total < minCnt || (student[k].total == minCnt && student[k].req < req)) {
                    minIdx = k;
                    minCnt = student[k].total;
                    req = student[k].req;
                }
            }
            student[minIdx] = temp;
        }
    }
    
    for (int i=0; i<n; i++) {
        final[i] = student[i].value;
    }
    sort(final, final+n, compare);
    
    for (int i=n-1; i>=0; i--) {
        cout << final[i] <<" ";
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    cin >> n >> totV;
    for (int i=0; i<totV; i++) {
        scanf("%d", &can);
        arr[i] = can;
        //        cout << arr[i] <<"" ;
    }
    //    cout <<endl;
    sol();
    //    cout << "\n";
    
    return 0;
}
