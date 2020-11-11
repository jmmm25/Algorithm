//
//  main.cpp
//  2589
//
//  Created by JEONGMIN on 2017. 9. 5..
//  Copyright © 2017년 JEONGMIN. All rights reserved.
//

#include <iostream>
#include <queue>


#define DEBUG   1
#define W   0
#define L   1
using namespace std;

int matrix[51][51] = {0,};

int BFS(int row, int col) {
    
    queue<pair<int, int> > que;
    int visit[51][51] = {0,};
    que.push(make_pair(row, col));
    int max = 0;
    int value = 0;
    visit[row][col] = 1;

    while (!que.empty()) {
        int row = que.front().first;
        int col = que.front().second;
        que.pop();
        
        if (max < visit[row][col]) {
            max = visit[row][col];
        }
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        
        int next_row = 0, next_col = 0;
        for (int i=0; i<4; i++) {
            next_row = row + dx[i];
            next_col = col + dy[i];
            if (next_row >= 0 && next_col >= 0) {
                if (matrix[next_row][next_col] == L && visit[next_row][next_col] == 0) {
                    que.push(make_pair(next_row, next_col));
                    visit[next_row][next_col] = visit[row][col] + 1;
                }
            }
        }
    }
    
    return max-1;
}

int main(int argc, const char * argv[]) {
    int row, col;
    cin >> row >> col;
    char landType;
    
    // input
    for (int i=0; i < row; i++) {
        for (int j=0; j<col; j++) {
            cin >> landType;
            if (landType == 'W') {
                matrix[i][j] = W;
            }
            else {
                matrix[i][j] = L;
            }
        }
    }
    

    
    // matrix confirm
//    if (DEBUG) {
//        printf("=====matrix confirm=====\n");
//        for (int i=0; i < row; i++) {
//            for (int j=0; j<col; j++) {
//                printf("%d ", matrix[i][j]);
//            }
//            printf("\n");
//        }
//    }
    
    
    int bfsValue = 0, max = -1;
    
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (matrix[i][j] == L) {
                bfsValue = BFS(i,j);
                
                if (max < bfsValue) {
                    max = bfsValue;
                }

            }
        }
    }
    
    cout << max;
    
    return 0;
}
