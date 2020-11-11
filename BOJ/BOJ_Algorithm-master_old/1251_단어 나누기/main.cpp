#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string str, a_text, b_text, c_text;
vector<string> v;

void sol() {
    string tempA, tempB, tempC, ret_text;
    for (int i = a_text.size() - 1; i >= 0; i--) {
        tempA += a_text[i];
    }
    for (int i = b_text.size() - 1; i >= 0; i--) {
        tempB += b_text[i];
    }
    for (int i = c_text.size() - 1; i >= 0; i--) {
        tempC += c_text[i];
    }
    ret_text = tempA + tempB + tempC;
    // cout << "sol : " << ret_text << endl;
    v.push_back(ret_text);
}

int main(int argc, char const *argv[]) {
    // freopen("input.txt", "r", stdin);
    cin >> str;
    int sz = str.size();
    if (sz >= 3 && sz <= 50) {
        for (int i = 0; i < sz - 2; i++) {
            a_text += str[i];
            for (int j = i+1; j < sz - 1; j++) {
                b_text += str[j];
                for (int k = j+1; k < sz; k++) {
                    c_text += str[k];
                }
                // cout << a_text << " ," << b_text << ", " << c_text << endl;
                sol();
                c_text = "";
            }
            b_text = "";
        }
        a_text = "";
        sort(v.begin(), v.end());
        cout << v.at(0) << "\n";
    }

    return 0;
}
