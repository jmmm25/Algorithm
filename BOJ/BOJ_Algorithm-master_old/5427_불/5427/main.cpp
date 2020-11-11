//
//  main.cpp
//  5427
//
//  Created by JEONGMIN on 2017. 9. 20..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>

#define MAX_SIZE 1001
using namespace std;

queue<pair<int, int> > que;
queue<pair<int, int> > fireque;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char map[MAX_SIZE][MAX_SIZE] = {0,};
int visit[MAX_SIZE][MAX_SIZE] = {0,};
int testNum = 0, w = 0, h = 0;

int bfs();

int main(int argc, const char * argv[]) {
    cin >> testNum;
    int N = 0;

    while (N < testNum) {
        cin >> h >> w;
        for (int i=0; i<w; i++) {
            for (int j=0; j<h; j++) {
                char str;
                cin >> str;
                map[i][j] = str;
            }
        }
        // 불의 위치와, 상근이 위치 파악
        for (int i=0; i<w; i++) {
            for (int j=0; j<h; j++) {
                if (map[i][j] == '@') {
                    que.push(make_pair(i,j));
                    visit[i][j] = 1;
                }
                else if (map[i][j] == '*') {
                    fireque.push(make_pair(i,j));
                }
                else {
                    continue;
                }
            }
        }

        bfs();

        for (int i=0; i<MAX_SIZE; i++) {
            for (int j=0; j<MAX_SIZE; j++) {
                visit[i][j] = 0;
                map[i][j] = NULL;
            }
        }

        while( !que.empty() ) que.pop();
        while( !fireque.empty() ) fireque.pop();

        N++;
    }

    return 0;
}


int bfs() {
    int result = 0;
    int escape = 0;

    while (!que.empty()) {
        result++;
        int size = (int)que.size();
        for (int q=0; q<size; q++) {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();
            if (map[row][col] == '*') {
                continue;
            }
            for (int i=0 ; i<4; i++) {
                int next_row = row + dx[i];
                int next_col = col + dy[i];

                if (next_row >= w || next_row < 0 || next_col >= h || next_col < 0) {
                    escape = 1;
                    break;
                }

                if ((map[next_row][next_col] == '.' && visit[next_row][next_col] != 1)) {
                    visit[next_row][next_col] = 1;
                    que.push(make_pair(next_row, next_col));
                }

            }
        }

        if (escape) {
            break;
        }

        size =fireque.size();
        for (int q=0; q<size; q++) {
            int row = fireque.front().first;
            int col = fireque.front().second;
            fireque.pop();
            for (int k=0; k<4; k++) {
                int next_row = row + dx[k];
                int next_col = col + dy[k];
                if (next_row >= w || next_row < 0 || next_col >= h || next_col < 0) {
                    continue;
                }
                if (map[next_row][next_col] == '.') {
                    map[next_row][next_col] = '*';
                    fireque.push(make_pair(next_row, next_col));
                }
            }
        }
    }

    if(escape)
        cout << result << "\n";
    else
        cout <<"IMPOSSIBLE\n";

    return 0;
}
