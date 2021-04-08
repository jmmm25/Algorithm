#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int max_val = -100000;
    for (int i = 0; i <= (arr.size() / 2); i++) {
        for (int j = 0; j <= (arr[i].size() / 2); j++) {
            int ans = 0;
            for (int x = i; x <= i + 2; x++) {
                for (int y = j; y <= j + 2; y++) {
                    if (x == i + 1 && y == j) {
                        continue;
                    }
                    if (x == i + 1 && y == j + 2) {
                        continue;
                    }
                    ans += arr[x][y];
                }
            }
            max_val = max(ans, max_val);
        }
    }
    return max_val;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
