//
//  main.cpp
//  2115_벌꿀채취_삼성SW
//
//  Created by JEONGMIN on 2017. 10. 17..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define MIN_INF (-999999)
using namespace std;

int tc, N, M, C, matrix[11][11], isVisited[11][11];
int data[11], flag[11];
int exceptX, exceptY;
vector< pair<int, int> > v;
int maxCost = MIN_INF;

int powerset(int n,int depth, int cost, int x, int y, int start)
{
    
    int sum = 0;
    if(n==depth){
        int i;
//        printf("{");
        for(i=0;i<n;i++){
            if(flag[i]==1) {
                if (data[i] == 0) {
                    break;
                }
//                printf("%d ",data[i]);
                sum += data[i];
            }
        }
        
//        printf("}\n");
//        cout << "sum: " << sum << endl;
        if (sum <= C) {
            for (int i=0; i<n; i++) {
                if (flag[i] ==1) {
                    if (data[i] == 0) {
                        break;
                    }
//                    cout << data[i] <<" ";
                    cost += (data[i] * data[i]);
                    
                }
            }
//            cout << cost << endl;
//            cout << "max 값 찾기 : " << maxCost << " " << cost << endl;
            maxCost = max(maxCost, cost);
            if (maxCost < cost) {
                maxCost = cost;
            }
            if (maxCost == cost) {
                v.clear();
                v.push_back(make_pair(x, y));
//                cout << "x, y 값 : " << v.at(0).first << " " << v.at(0).second << endl;
            }
//            cout << "max 값 : " << maxCost << endl;
        }

        return maxCost;
    }
    flag[depth]=1;
    powerset(n,depth+1, cost, x, y, start);
    flag[depth]=0;
    powerset(n,depth+1, cost, x, y, start);
    
    return maxCost;
    
}

int sol(int start) {
    int ret = 0;
    data[M] = {0};
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (start == 1) {
                if (v.size() == 1 && (exceptX == i || exceptY == j)) {
                    continue;
                }
            }
            
            // 표에서 m 갯수만큼 데이터를 연속적으로 뽑아서 subset 만들기.
            for (int k=0; k<M; k++) {
                if (j > (N-M)) {
                    continue;
                }
                data[k] = matrix[i][j+k];
                //data 잘 들어갔는지를 확인
//                cout << "k: " << k << "일 때 data"<<k <<" "<< data[k] << " " << endl;
            }
            
            ret = powerset(M, 0, 0, i,j, start);
//            cout << "ret : " << ret << endl;
        }
    }

    return ret;
}

int main(int argc, const char * argv[]) {
    cin >> tc;
    for (int t=1; t<=tc; t++) {
//        cout << "=================================test case :" << t <<endl;
        cin >> N >> M >> C;
        
        // constraint of input rule
        if ( (N<3 || N>10) || (M<1 || M>5) || (C<10 || C>30) ) {
            cout << "Input Error" << "\n";
            return 1;
        }
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        int ret = 0;
        
        ret += sol(0);
        exceptX = v.at(0).first;    exceptY = v.at(0).second;
        maxCost = MIN_INF;
//        cout << "===========================2번째 시작 " << endl;
        ret += sol(1);
        
        //    ret = sol();
        //    cout << ret << endl;
        //    ret = sol();
        cout <<"#"<< t << " " << ret << "\n";
        memset(matrix, 0, sizeof(matrix));
        maxCost = MIN_INF;
        
        
    }
    
    return 0;
}
