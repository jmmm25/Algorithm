#include <iostream>

using namespace std;

int n;
int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  cin >> n;
  int cnt = 0;
  n += 1;
  while (n--) {
    for (size_t i = n; i > 0; i/=10) {
      int temp = i % 10;
      // cout << temp << " ";
      if (temp >= 0) {
        cnt++;
      }
    }
    // cout << endl;
  }

  cout << cnt << "\n";
  return 0;
}
