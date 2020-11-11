#include<iostream>
#include<string>

using namespace std;

char first_Num[2];
int temp_Num = 0;
char next_Num[2];
int cnt = 0 ;

int main(int argc, char const *argv[]) {
  int init_Num = 0;
  int a=0, b=0, temp=0, flag = 1;
  cin >> init_Num;

  if (!init_Num) {
    cout << "input is NULL" << endl;
  }

  while(1) {

    if(flag == 0)
      break;

    first_Num = itoa(init_Num);

    if (strlen(first_Num) == 2) {
      a = first_Num[0];
      b = first_Num[1];
      temp = a+b;

      next_Num[1] = atoi(temp);
      next_Num[0] = first_Num[1];
      flag = atoi(next_Num);
      cnt++;

    }
  }
  return 0;
}
