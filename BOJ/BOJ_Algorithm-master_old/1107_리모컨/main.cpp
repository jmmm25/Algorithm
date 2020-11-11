#include <iostream>
#include <cstring>
#define MAX_INF     987654321
#define MAX_RANGE   1000000
using namespace std;

int n, k;
int isChecked[13];

int btn_cnt_chk (int num) {
  int cnt = 0;
  if (num == 0) {
    // 고장났다면 true 이므로 -1 return.
    if (isChecked[num]) {
      return -1;
    }
    // 동작한다면 false 이므로 1 return.
    else
      return 1;
  }

  // num > 0
  else {
    cnt = 0;
    for (int i = num; i > 0; i/=10) {
      int rest = i % 10;
      if (!isChecked[rest]) {
        cnt++;
      }
      else
        return -1;
    }
    // cout << "num , cnt " << num << ", " << cnt << endl;
  }
  return cnt;
}

int sol() {
  int cnt = 0, ret = MAX_INF;
  for (int i = 0; i < MAX_RANGE; i++) {
    cnt = btn_cnt_chk(i);
    // cout << i << " >> " << "cnt : " << cnt << "    ";
    if (cnt > 0) {
      int len = abs(n - i);
      // cout << i << " 일 때 , +,- 한 숫자는 " << len << "  거기에 + cnt  " << cnt << endl;
      ret = min(ret, len + cnt);
    }
  }

  return ret;
}


int main(int argc, char const *argv[]) {
  // freopen("input3.txt", "r", stdin);
  cin >> n >> k;
  int chk, ret = -1, sol_cnt = 0;

  // isChecked[chk] == true 일 경우 고장난 버튼.
  for (int i = 0; i < k; i++) {
    cin >> chk;
    isChecked[chk] = 1;
  }

  // +, - 버튼으로 채널을 이동할 때.
  ret = abs(100 - n);;
  sol_cnt = sol();
  ret = min(ret, sol_cnt);
  cout << ret << "\n";

  return 0;
}


// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <cmath>
// #define START_NUMBER    100
// #define MAX_INF   987654321
// using namespace std;
//
// int n, k;
// bool key[13];
// int number[7];
// vector<int> approx_val;
//
// void find_approx_value (int j) {
//
//   // 각 해당하는 값의 자리에 최적 값을 찾음.
//   for (int l = j-1; l >= 0; l--) {
//     int val = MAX_INF, sub_val = 0, save_pos = -1;
//     // cout << number[l] << endl;
//     for (int i = 0; i < 10; i++) {
//       if (key[i] == true) {
//         continue;
//       }
//       else {
//         sub_val= abs(number[l] - i);
//         // cout << "number[l] - "<< i << " :  " << sub_val << endl;
//         if (val > sub_val) {
//           val = sub_val;
//           save_pos = i;
//         }
//       }
//     }
//     // cout << val << " , " << save_pos << endl;
//     approx_val.push_back(save_pos);
//   }
//
// }
//
// int sol() {
//   int j=0;
//   for (int i = n; i > 0; i/=10) {
//     number[j] = i % 10;
//     j++;
//   }
//
//   find_approx_value(j);
//
//   // vector에 저장된 값을 integer 형으로
//   int num = 0;
//   int sz = approx_val.size();
//   // cout << "size : " << sz << endl;
//   for (size_t i = 0; i < approx_val.size(); i++) {
//     // cout << approx_val[i] << " ";
//     num += (approx_val[i] * pow(10, (sz-1)));
//     sz--;
//   }
//   // cout << num;
//
//   sz = approx_val.size();
//   cout << "num : " << num << endl;
//   while (true) {
//     if (num == n) {
//       break;
//     }
//
//     // + button
//     if (num > n) {
//       num--;
//       sz++;
//     }
//     // - button
//     else if (num < n){
//       num++;
//       sz++;
//     }
//   }
//   // cout << sz << "\n";
//   return sz;
// }
//
// int main(int argc, char const *argv[]) {
//   // freopen("input3.txt", "r", stdin);
//   cin >> n >> k;
//   int x, plma_ret = 0, approx_ret = 0;
//   // key[x]가 true 일 경우 고장난 버튼.
//   for (int i = 0; i < k; i++) {
//     cin >> x;
//     key[x] = true;
//   }
//
//   // 처음 시작 채널은 100 이므로, 버튼 조작 X
//   if (n == START_NUMBER) {
//     cout << "0" << "\n";
//     return 0;
//   }
//
//   plma_ret = abs(100 - n);
//   approx_ret = sol();
//
//   cout << approx_ret << "\n";
//   return 0;
// }
