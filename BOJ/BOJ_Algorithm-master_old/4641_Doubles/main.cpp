#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[20];

int binary_search(int find_val, int n) {
    int l = 0, r = 0, mid = 0;
    l = 0;
    r = n;
    // cout << "find : " << find_val << endl;
    // cout << l  << " ," << r << ", " << mid << endl;
    while (l <= r) {
        mid = (l+r)/2;
        // cout << "mid : " << mid << endl;
        if (arr[mid] == find_val) {
            // cout << "find  idx : ";
            return 1;
        }
        else if (find_val < arr[mid]) {
            r = mid - 1;
        }
        else if (find_val > arr[mid]) {
            l = mid + 1;
        }
    }
    return 0;
}

int linear_search(int x, int n) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            ret++;
            // cout << arr[i] <<" find : " << ret << endl;
        }
    }

    return ret;
}


int sol(int n) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        // cout << arr[i] << ":: " << arr[i] * 2 << endl;
        ret += linear_search(arr[i]*2 , n);
        // cout << arr[i] << " ";
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    int n, i=0;
    while (true) {
        int ret = 0;
        cin >> n;
        // cout << n << " ";
        if (n == -1) {
            break;
        }
        else if (n != 0 && n != -1) {
            arr[i++] = n;
        }
        else if (n == 0) {
            // cout << " n = 0" << endl;
            // cout << i << endl;
            // for (int j = 0; j < i; j++) {
            //     cout << arr[j] << " ";
            // }
            // cout << endl;
            ret = sol(i);
            // cout << ret << endl;
            memset(arr, 0, sizeof(arr));
            i = 0;
            cout << ret << "\n";
        }
    }
    return 0;
}
