#include <cstdio>
#include <iostream>
using namespace std;
    
int main() {
    freopen("input.txt", "r", stdin);
    string arr[11] = {"\0",  "one",   "two",   "three", "four", "five",
                      "six", "seven", "eight", "nine",  "ten"};
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (i > 9) {
            if (i % 2 == 0) {
                cout << "even"
                     << "\n";
            } else {
                cout << "odd"
                     << "\n";
            }
        } else {
            cout << arr[i] << "\n";
        }
    }

    return 0;
}