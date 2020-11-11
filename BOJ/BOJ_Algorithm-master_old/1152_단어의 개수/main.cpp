#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {
	int num = 0, buf = 1000001;
    char str[1000001];
    cin.getline(str, buf);

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ')
			num++;
	}

	if (str[0] == ' ') {
		num = num - 1;
	}

	if (str[strlen(str) - 1] == ' ') {
		num = num - 1;
	}

	cout << num + 1 << endl;
}


// #include <iostream>
// #include <cstring>
//
// using namespace std;
//
// int main(int argc, char const *argv[]) {
//     // freopen("input.txt", "r", stdin);
//     int buf = 1000001;
//     char str[buf];
//     int cnt = 0, start = 0;
//     cin.getline(str, buf);
//     // cout << strlen(str) << endl;
//     int i = 0;
//     if (str[0] == ' ') {
//         while (str[i] == ' ') {
//             start++;
//             i++;
//         }
//     }
//     else {
//         start = 0;
//     }
//
//     for (int i = start; i <= strlen(str); i++) {
//         if (str[i] == ' ') {
//             // cout << "_";
//             cnt++;
//         }
//         else if (str[i] == '\000') {
//             cout << str[i];
//             // cout << "EOF";
//             cnt++;
//             break;
//         }
//     }
//     // cout << endl;
//     cout << cnt << "\n";
//     return 0;
// }
