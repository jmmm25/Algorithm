#include <iostream>
using namespace std;

bool alpha[26];
string text;
int N, K;

void set_init() {
    char ch[6] = "antic";
    for (int i = 0; i < 5; i++) {
        cout << ch[i] << " ";
        alpha[ch[i] - 'a'] = true;
        cout << ch[i] - 'a' << endl;
    }

    for (int i = 0; i < 26; i++) {
        cout << alpha[i] << " ";
    }
}

int sol(string text) {
    int ret = 0;
    int cnt = K - 5;
    if (cnt > 0) {
        
    }
    else

    return ret;
}


int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    int ret = 0;
    cin >> N >> K;
    set_init();
    for (int i = 0; i < N; i++) {
        cin >> text;
        ret += sol(text);
    }
    return 0;
}
