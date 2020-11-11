#include <iostream>
using namespace std;

int number[10];
bool isChecked[10];

void dfs(int num, int pos, int n) {
  number[pos] = num;

  if (pos == n) {
    for (int i = 1; i <= n; i++) {
      cout << number[i] << " ";
    }
    cout << "\n";
  }

  for (int i = 1; i <= n; i++) {
    if (isChecked[i]) continue;
    isChecked[i] = true;
    dfs(i, pos+1, n);
    isChecked[i] = false;
  }
}

int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    isChecked[i] = true;
    dfs(i, 1, n);
    isChecked[i] = false;
  }
  return 0;
}
