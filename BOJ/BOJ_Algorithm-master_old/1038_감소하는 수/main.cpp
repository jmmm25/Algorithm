#include <iostream>

#define MAX_INF     1000000
using namespace std;

int n;
int number[20];
int main(int argc, char const *argv[]) {
  cin >> n;
  long long num = 1;
  if (n == 0) {
    cout << "0" << "\n";
    return 0;
  }
  else if (n > 1022) {
    cout << "-1" << "\n";
    return 0;
  }

  while (true) {
    long long temp = num;
    long long temp2 = -1;
    int jump = 1;
    bool flag = true;
      while (temp) {
        if (temp % 10 <= temp2) {
          flag = false;
          break;
        }
        jump *= 10;
        temp2 = temp % 10;
        temp /= 10;
      }
      // flag가 true이면 n을 감소시킴. 0일 때 출력.
      if (flag) {
        n--;
      }

      else {
        num += jump;
        num = (num/jump) * jump;
        continue;
      }
      if (n == 0) {
        cout << num << "\n";
        break;
      }
      num++;
  }
  return 0;
}
