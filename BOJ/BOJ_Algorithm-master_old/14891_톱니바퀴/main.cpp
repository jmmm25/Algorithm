#include <iostream>
#include <cstring>
#include <vector>

#define DEBUG           0
using namespace std;

char wheel[5][8];
bool isChanged[5];
int move_dir[5];
int K;

void move(int n, int v) {
    int temp_wheel[8] = {0,};

    // left move
    if (v == -1) {
        int temp = wheel[n][0];
        for (int i = 7; i > 0; i--) {
            temp_wheel[i-1] = wheel[n][i];
        }

        temp_wheel[7] = temp;

        for (int i = 0; i < 8; i++) {
            wheel[n][i] = temp_wheel[i];
        }
        return;
    }

    // right move
    if (v == 1) {
        int temp = wheel[n][7];
        for (int i = 0; i < 7; i++) {
            temp_wheel[i+1] = wheel[n][i];
        }
        temp_wheel[0] = temp;

        for (int i = 0; i < 8; i++) {
            wheel[n][i] = temp_wheel[i];
        }
    }

}

void move_wheel(int u, int v) {
    isChanged[u] = true;
    move_dir[u] = v;
    // cout << "move wheel " << u << " before changed " << endl;
    // for (int j = 0; j < 8; j++) {
    //     cout << wheel[u][j] << " ";
    // }
    // cout << endl;
    // if (v == 1) {
    //     move_right(u);
    // }
    // else if (v == -1) {
    //     move_left(u);
    // }
    // for (int j = 0; j < 8; j++) {
    //     cout << wheel[u][j] << " ";
    // }
    // cout << endl;
    //
    // cout << "move wheel " << u << "after changed " << endl;

    // left process
    for (int i = u-1; i > 0; i--) {
        // right move
        if (move_dir[i+1] == 1 && isChanged[i+1]) {
            if (wheel[i+1][6] != wheel[i][2]) {
                // cout << i+1 << " ------ " << i << " different, go left" << endl;
                // move_left(i);
                move_dir[i] = -1;
                isChanged[i] = true;
            }
            else {
                continue;
            }
        }
        // left move
        else if (move_dir[i+1] == -1 && isChanged[i+1]) {
            if (wheel[i+1][6] != wheel[i][2]) {
                // cout << i+1 << " ------ " << i << " different, go right" << endl;
                // move_right(i);
                move_dir[i] = 1;
                isChanged[i] = true;
            }
            else {
                continue;
            }
        }
    }

    // right process
    for (int i = u+1; i < 5; i++) {
        if (move_dir[i-1] == 1 && isChanged[i-1]) {
            if (wheel[i-1][2] != wheel[i][6]) {
                // move_left(i);
                move_dir[i] = -1;
                isChanged[i] = true;
            }
            else {
                continue;
            }

        }

        else if (move_dir[i-1] == -1 && isChanged[i-1]) {
            if (wheel[i-1][2] != wheel[i][6]) {
                // move_right(i);
                move_dir[i] = 1;
                isChanged[i] = true;
            }
            else {
                continue;
            }
        }
    }
    if (DEBUG) {
        for (size_t i = 1; i < 5; i++) {
            cout << "dir : " << move_dir[i] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i < 5; i++) {
        if (move_dir[i]) {
            if(DEBUG) {
                cout << i << " wheel move " << move_dir[i] << "direction" << endl;
            }
            move(i, move_dir[i]);
        }
    }


    if (DEBUG) {
        for (int i = 1; i < 5; i++) {
            for (int j = 0; j < 8; j++) {
                cout << wheel[i][j] << " ";
            }
            cout << endl;
        }
    }
}



int main(int argc, char const *argv[]) {
    if (DEBUG) {
        freopen("input.txt", "r", stdin);
    }

    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> wheel[i][j];
        }
    }

    if (DEBUG) {
        for (int i = 1; i < 5; i++) {
            for (int j = 0; j < 8; j++) {
                cout << wheel[i][j] << " ";
            }
            cout << endl;
        }
    }

    cin >> K;
    // u is wheel number, v is dir (-1 : <- , 1 : ->)
    for (int i = 0; i < K; i++) {
        int u, v;
        cin >> u >> v;
        // cout << u << ", " << v << endl;
        memset(isChanged, false, sizeof(isChanged));
        memset(move_dir, 0, sizeof(move_dir));
        move_wheel(u, v);
    }

    int N = 0, ret = 0;
    for (int i = 1; i < 5; i++) {
        // cout << "i : " << i << endl;
        if (wheel[i][0] == '1') {
            ret += (1 << N);
            // cout << ret << endl;
        }
        N++;
    }
    cout << ret << "\n";

    if(DEBUG) {
        cout << "=================== DEBUG START =================" << endl;
        cout << "change " << endl;
        // move_left(3);
        for (int i = 1; i < 5; i++) {
            for (int j = 0; j < 8; j++) {
                cout << wheel[i][j] << " ";
            }
            cout << endl;
        }
        cout << "=================== DEBUG FINISH =================" << endl;
    }
    return 0;
}
