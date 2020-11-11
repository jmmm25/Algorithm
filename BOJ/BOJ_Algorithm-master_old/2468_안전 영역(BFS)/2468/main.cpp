
#include <iostream>
#define MAX_SIZE    102
using namespace std;

int map[MAX_SIZE][MAX_SIZE] = {0,};
int isVisited[MAX_SIZE][MAX_SIZE] = {0,};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N = 0, h=0;

void dfs(int si, int fj, int k, int cnt) {
    isVisited[si][fj] = 1;
    for (int i=0; i<4; i++) {
        int ni = si + dx[i];
        int nj = fj + dy[i];
        if (ni < 0 || nj < 0 || ni >= N || nj >= N) {
            continue;
        }
        else {
            if (map[ni][nj] > k && !isVisited[ni][nj]) {
                dfs(ni, nj, k, cnt);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> N;
    int res = 0;
    for (int r=0; r<N; r++) {
        for (int c=0; c<N; c++) {
            scanf("%d",&h);
            map[r][c] = h;
        }
    }

    for (int k=0; k<101; k++) {
        int cnt = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                isVisited[i][j] = 0;
            }
        }
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (map[i][j] > k && !isVisited[i][j]) {
                    cnt++;
                    dfs(i,j,k,cnt);
                }
            }
        }
//        cout << cnt << endl;
        res = max(res, cnt);
        if (cnt == 0) {
            break;
        }
    }
    cout << res << "\n";
    
    return 0;
}
