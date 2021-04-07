#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    string a, b;
    cin >> a >> b;
    cout << a.length() << " " << b.length() << "\n";
    cout << a + b << "\n";
    
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;

    cout << a << " " << b << "\n";

    return 0;
}