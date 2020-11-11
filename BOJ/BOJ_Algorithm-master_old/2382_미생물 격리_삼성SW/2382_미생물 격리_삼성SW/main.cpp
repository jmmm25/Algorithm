//
//  main.cpp
//  2382_미생물 격리_삼성SW
//
//  Created by JEONGMIN on 2017. 10. 20..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int T, N, M, K;
int dx[5] = {0, -1, 1, 0, 0 };
int dy[5] = {0, 0, 0, -1, 1 };

struct P {
    int cnt;
    int dir;
    int isvisit;
};

vector<P> map[101][101];

void sol() {
    P info;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!map[i][j].empty() && !map[i][j].at(0).isvisit) {
                int dir = map[i][j].at(0).dir;
                int ni = i + dx[dir];
                int nj = j + dy[dir];
                
                if (ni < 0 || nj < 0 || ni >= N || nj >= N) {
                    continue;
                }
                info.cnt = map[i][j].at(0).cnt;
                //                    cout << "미생물 갯수 : " << info.cnt << endl;
                info.dir = map[i][j].at(0).dir;
                info.isvisit = map[i][j].at(0).isvisit + 1;
                map[ni][nj].push_back(info);
                //                    cout << i << "," << j << "이 " << ni << " " << nj <<" 로 이동 완료" << endl;
                //                    cout << "현재 위치인 " << ni <<"," << nj <<"의 미생물 군집 갯수 : " << map[ni][nj].size()<< endl;
                
                map[i][j].erase(map[i][j].begin());
            }
        }
    }
    
    //        cout << "===========================첫번째 for문 종료!!! 전원 이동 함" << endl;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!map[i][j].empty()){
                int maxVal = -1, maxK = -1, curCnt = 0;
                if (map[i][j].size() != 1) {
                    //                        cout << "현재 위치 " << i << "," << j << "의 미생물 군집 갯수: "<< map[i][j].size()<< endl;
                    for (int k=0; k<map[i][j].size(); k++) {
                        curCnt += map[i][j].at(k).cnt;
                        //                            cout << "미생물의 갯수 : " << curCnt << endl;
                        
                        if (maxVal < map[i][j].at(k).cnt) {
                            maxVal = map[i][j].at(k).cnt;
                            maxK = map[i][j].at(k).dir;
                            //                                cout << "가장 큰 max Dir :  " << maxK << endl;
                        }
                    }
                    
                    info.dir = maxK;    info.cnt = curCnt;  info.isvisit = 0;
                    map[i][j].clear();
                    map[i][j].push_back(info);
                    //                        cout << "현재 map" << i <<"," << j << "에 들어간 값 " << info.dir << " " <<
                    //                        info.cnt << " " << info.isvisit << endl;
                    curCnt = 0;
                }
                
                if (i == 0 || i == N-1 || j == 0 || j == N-1) {
                    //                    map[i][j].at(0).cnt /= 2;
                    int cnt = map[i][j].at(0).cnt;
                    cnt /= 2;
                    
                    if (cnt == 0) {
                        map[i][j].clear();
                        continue;
                    }
                    
                    int reDir = 0;
                    reDir = (map[i][j].at(0).dir < 3 ? 3 - map[i][j].at(0).dir : 7 - map[i][j].at(0).dir);
                    //                    cout << map[i][j].at(0).cnt << endl;
                    //                    cout << "redir   " << reDir << endl;
                    map[i][j].at(0).dir = reDir;
                    map[i][j].at(0).cnt = cnt;
                }
                map[i][j].at(0).isvisit = 0;
            }
        }
    }
    //        cout << "===========================두번째 for문 종료!!! " << endl;
    
}

int main(int argc, const char * argv[]) {
    cin >> T;
    P p;
    
    for (int test = 1; test <= T; test++) {
        int ret = 0;
        //        cout << "=========================test " << test << "===================="  << endl;
        cin >> N >> M >> K;
        int x=0, y=0, cnt=0 ,dir=0;
        for (int i=0; i<K; i++) {
            cin >> x >> y >> cnt >> dir;
            p.cnt = cnt;    p.dir = dir;    p.isvisit = 0;
            map[x][y].push_back(p);
            //            cout << map[x][y].at(0).cnt << " " << map[x][y].at(0).dir << endl;
        }
        
        for (int q=0; q<M; q++) {
            sol();
        }
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (!map[i][j].empty()) {
                    ret += map[i][j].at(0).cnt;
                    map[i][j].clear();
                }
            }
        }
        cout << "#" <<test<<" " << ret << "\n";
    }
    return 0;
}
