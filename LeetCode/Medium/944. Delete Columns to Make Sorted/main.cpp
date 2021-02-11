#include <iostream>
#include <vector>

using namespace std;

int minDeletionSize(vector<string> &A)
{
  int result = 0;
  for (int i = 0; i < A[0].size(); i++)
  {
    for (int j = 1; j < A.size(); j++)
    {
      if (A[j-1][i] > A[j][i])
      {
        result++;
        break;
      }
    }
  }
  return result;
}

int main(int argc, char const *argv[])
{
  vector<string> A;

  // Test Case 1
  // A.push_back("cba");
  // A.push_back("daf");
  // A.push_back("ghi");

  // Test Case 2
  // A.push_back("a");
  // A.push_back("b");

  // Test Case 3
  // A.push_back("zyx");
  // A.push_back("wvu");
  // A.push_back("tsr");

  int result = minDeletionSize(A); 
  return 0;
}
