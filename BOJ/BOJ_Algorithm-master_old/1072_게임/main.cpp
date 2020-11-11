#include <iostream>
#include <cstdio>

#define MAX_INF     1000000000
using namespace std;

long long x, y, z;

int main(int argc, char const *argv[]) {
  long long l, r, mid;
  // freopen("input.txt", "r", stdin);
  while(cin >> x >> y) {
    long long temp_z = 0;
    z = 100 * y / x;
    // cout << z << endl;
    l = 0;
    r = MAX_INF;

    if (z >= 99) {
      cout << "-1" << "\n";
    }

    else {
      // 시간 초과를 해결하기 위해 이분 탐색.
      while (l <= r) {
        mid = (l + r) / 2;
        temp_z = 100 * (y+mid) / (x+mid);
        // cout << temp_z << endl;
        if (z < temp_z) {
          r = mid - 1;
        }
        else
          l = mid + 1;
      }
      cout << l << "\n";
    }
  }
  return 0;
}
