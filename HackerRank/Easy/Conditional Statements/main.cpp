#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    string arr[11] = {"\0",  "one",   "two",   "three", "four", "five",
                      "six", "seven", "eight", "nine",  "ten"};
    int a;
    cin >> a;

    if (a < 10) {
        cout << arr[a] << "\n";
    } else {
        cout << "Greater than 9"
             << "\n";
    }

    return 0;
}