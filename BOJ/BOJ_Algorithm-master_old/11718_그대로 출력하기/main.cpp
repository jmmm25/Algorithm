#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    char str;
    while (true) {
        str = getchar();
        if (str == EOF) {
            break;
        }
        putchar(str);
    }
    return 0;
}
