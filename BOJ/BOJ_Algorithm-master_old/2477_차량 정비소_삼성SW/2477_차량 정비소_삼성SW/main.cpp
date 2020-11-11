//
//  main.cpp
//  2477_차량 정비소_삼성SW
//
//  Created by JEONGMIN on 2017. 10. 21..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

struct Info {
    int id;
    int t;
    int repDeskIdx;
};

queue<Info> receptionQ;
queue<Info> repairQ;
int TC, N, M, K, A, B;
int ai[10], bi[10];
Info receptionDesk[10];
Info repairDesk[10];

int sol() {
    int ret = 0;
//    int time = 0;
    Info firstRec = receptionQ.front();
    int time = firstRec.t;
    int cnt = 0;
    
    while (cnt < K) {
//        cout << "time  : " << time << endl;
        for (int i=1; i<=N; i++) {
            if (receptionDesk[i].t > 0) {
                receptionDesk[i].t--;
//                cout << i << "데스크 타임 " <<receptionDesk[i].t << endl;
                if (receptionDesk[i].t == 0) {
                    receptionDesk[i].repDeskIdx = i;
                    Info repairCus = receptionDesk[i];
                    repairQ.push(repairCus);
//                    cout << "repairQ에 들어간 값" << receptionDesk[i].id << " " << time << " " <<receptionDesk[i].repDeskIdx << endl;
                }
            }
            
            if (receptionDesk[i].t == 0) {
                Info customer = receptionQ.front();
                
                if (!receptionQ.empty() && customer.t <= time) {
                    receptionQ.pop();
                    receptionDesk[i] = {customer.id, ai[i]};
//                    cout << "receptionDesk "<< i <<"에 " << customer.id << " " << ai[i] << " 들어감 "<< endl;
                }
            }
        }
        
        for (int i=1; i<=M; i++) {
            if (repairDesk[i].t > 0) {
                repairDesk[i].t--;
                
                if (repairDesk[i].t == 0) {
                    cnt++;
//                    cout << "cnt : " << cnt << endl;
                }
            }
            
            if (repairDesk[i].t == 0) {
                if (!repairQ.empty()) {
                    Info customer = repairQ.front();
                    repairQ.pop();
                    repairDesk[i] = {customer.id, bi[i], customer.repDeskIdx};
                    if (repairDesk[i].repDeskIdx == A && i == B) {
                        ret += repairDesk[i].id;
//                        cout << "ret : " <<  ret << endl;
                    }

//                    cout  << "초 일 때 repairDesk "<< i <<"에 " << customer.id << " " << bi[i] << " 들어감 "<< endl;;
                }
            }
        }
        time++;
    }
    
    if (ret == 0) {
        return -1;
    }
    else {
        return ret;
    }
}





int main(int argc, const char * argv[]) {
    cin >> TC;
    Info c;
    for (int t=1; t<=TC; t++) {
        cin >> N >> M >> K >> A >> B;
        
        for (int i=1; i<=N; i++) {
            scanf("%d", &ai[i]);
//            cout << ai[i] << endl;
        }
        
        for (int i=1; i<=M; i++) {
            scanf("%d", &bi[i]);
//            cout << bi[i] << endl;
        }
        
        for (int i=1; i<=K; i++) {
            c.id = i;
            scanf("%d", &c.t);
            receptionQ.push(c);
//            cout << c.id << " " << c.t << endl;
        }
        
        int ret = sol();
        printf("#%d %d\n", t, ret);
        while (!receptionQ.empty()) {
            receptionQ.pop();
        }
        while (!repairQ.empty()) {
            repairQ.pop();
        }
        memset(ai, 0, sizeof(ai));
        memset(bi, 0, sizeof(bi));
        
    }
    
    
    
    return 0;
}
