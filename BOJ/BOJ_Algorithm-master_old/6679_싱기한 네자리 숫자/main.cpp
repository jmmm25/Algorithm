#include <iostream>

#define MAXIMUM_INPUT     9999
#define MINIMUM_INPUT     1000
using namespace std;

int main(int argc, char const *argv[]) {
  int ret_ten, ret_twe, ret_hex;
  for (int i = MINIMUM_INPUT; i <= MAXIMUM_INPUT; i++) {
    ret_ten = 0, ret_twe = 0, ret_hex = 0;

    // 10진수 각 자리수의 합
    for (int n = i; n > 0; n/=10) {
      ret_ten += n % 10;
    }
    // cout << "ten : " << ret_ten << " ";

    // 12진수 각 자리수의 합
    for (int n = i; n > 0; n/=12) {
      ret_twe += n % 12;
    }
    // cout << "twe : " << ret_twe << " ";

    // 16진수 각 자리수의 합
    for (int n = i; n > 0; n/=16) {
      ret_hex += n % 16;
    }
    // cout << "hex : " << ret_hex << endl;

    if (ret_ten == ret_twe && ret_twe == ret_hex) {
      cout << i << "\n";
    }
  }

  return 0;
}
