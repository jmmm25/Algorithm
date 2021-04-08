#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long ans = 0;
    if (s.length() == 1) {
        if (s[0] == 'a') {
            return ans + n;
        } else {
            return ans;
        }
    }
    for (auto i : s) {
        if (i == 'a') ans++;
    }
    ans = ans * (n / s.length());
    for (long i = 0; i < n % s.length(); i++) {
        if (s[i] == 'a') ans++;
    }
    return ans;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
