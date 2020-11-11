#include <iostream>
#include <string>
#define MAX_INF   987654321
using namespace std;

string A, B;

int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  int cnt = 0, ret = MAX_INF;
  cin >> A >> B;

  int sz = B.size() - A.size();
  // i == 0 일 때, A 뒤에 문자 붙힘.
  // i == 1 일 때, A 앞에 문자 붙힘. --> B가 한 칸씩 밀리므로.
  for (int i = 0; i <= sz; i++) {
    cnt = 0;
    for (int j = 0; j < A.size(); j++) {
      if (A[j] != B[j+i]) {
        cnt++;
      }
    }
    ret = min(ret, cnt);
  }
  cout << ret << "\n";
  return 0;
}
