#include <iostream>
#include <vector>
using namespace std;

int N, M, sx, sy, K;
int map[21][21];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

// 0 : up, 1 : bottom, 2 : front, 3 : rear, 4 : left, 5 : right
vector<pair<int, int> > dice;

void roll_east(int nx, int ny) {
    vector<pair<int, int> > temp;
    for (int i = 0; i < dice.size(); i++) {
        temp.push_back(make_pair(dice[i].first, dice[i].second));
        // cout <<"push : " <<  temp[i].first << ", " << temp[i].second << endl;
    }
    dice[0] = temp[4];
    dice[1] = temp[5];
    dice[4] = temp[1];
    dice[5] = temp[0];
    if (map[nx][ny] == 0) {
        map[nx][ny] = dice[1].second;
    }
    else {
        dice[1].second = map[nx][ny];
        map[nx][ny] = 0;
    }
}

void roll_west(int nx, int ny) {
    vector<pair<int, int> > temp;
    for (int i = 0; i < dice.size(); i++) {
        temp.push_back(make_pair(dice[i].first, dice[i].second));
        // cout <<"push : " <<  temp[i].first << ", " << temp[i].second << endl;
    }
    dice[0] = temp[5];
    dice[1] = temp[4];
    dice[4] = temp[0];
    dice[5] = temp[1];
    if (map[nx][ny] == 0) {
        map[nx][ny] = dice[1].second;
    }
    else {
        dice[1].second = map[nx][ny];
        map[nx][ny] = 0;
    }
}

void roll_north(int nx, int ny) {
    vector<pair<int, int> > temp;
    for (int i = 0; i < dice.size(); i++) {
        temp.push_back(make_pair(dice[i].first, dice[i].second));
        // cout <<"push : " <<  temp[i].first << ", " << temp[i].second << endl;
    }
    dice[0] = temp[2];
    dice[1] = temp[3];
    dice[2] = temp[1];
    dice[3] = temp[0];
    if (map[nx][ny] == 0) {
        map[nx][ny] = dice[1].second;
    }
    else {
        dice[1].second = map[nx][ny];
        map[nx][ny] = 0;
    }

}

void roll_south(int nx, int ny) {
    vector<pair<int, int> > temp;
    for (int i = 0; i < dice.size(); i++) {
        temp.push_back(make_pair(dice[i].first, dice[i].second));
        // cout <<"push : " <<  temp[i].first << ", " << temp[i].second << endl;
    }
    dice[0] = temp[3];
    dice[1] = temp[2];
    dice[2] = temp[0];
    dice[3] = temp[1];
    if (map[nx][ny] == 0) {
        map[nx][ny] = dice[1].second;
    }
    else {
        dice[1].second = map[nx][ny];
        map[nx][ny] = 0;
    }
}

void sol(int order, int x, int y) {
    int nx = x + dx[order];
    int ny = y + dy[order];
    if (nx < 0 || ny < 0 || nx >= N || ny >= M) return;
    // cout << "nx, ny go  : " << nx << ", " << ny << endl;
    switch (order) {
        case 1:
            roll_east(nx, ny);
            break;
        case 2:
            roll_west(nx, ny);
            break;
        case 3:
            roll_north(nx, ny);
            break;
        case 4:
            roll_south(nx, ny);
    }
    sx = nx;
    sy = ny;
    // cout << "result : " << dice[0].second << endl;
    cout << dice[0].second << endl;
}

void set_dice_init() {
    dice.push_back(make_pair(1, 0));
    dice.push_back(make_pair(6, map[sx][sy]));
    dice.push_back(make_pair(5, 0));
    dice.push_back(make_pair(2, 0));
    dice.push_back(make_pair(4, 0));
    dice.push_back(make_pair(3, 0));
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> N >> M >> sx >> sy >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    set_dice_init();

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "=========original =============" << endl;
    // for (int i = 0; i < dice.size(); i++) {
    //     cout << dice[i].first << " , " << dice[i].second <<  endl;
    // }
    // cout << "============change +==============" << endl;
    for (int i = 0; i < K; i++) {
        int order;
        cin >> order;
        sol(order, sx, sy);
        // for (int j = 0; j < 6; j++) {
        //     cout << dice[j].first << ", " << dice[j].second << endl;
        // }
        // cout << "map ::::::" << endl;
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }



    return 0;
}
