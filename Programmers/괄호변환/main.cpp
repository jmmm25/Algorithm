#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// 앞뒤 문자열 제거 및 문자열 반대 방향으로 변경
string convert(string s) {
    string answer = "";
    for (int i = 0; i < s.length(); i++) {
        if (i == 0 || i == s.length() - 1) {
            continue;
        }
        if (s[i] == '(') {
            answer += ")";
        } else {
            answer += "(";
        }
    }
    return answer;
}

// u, v 만들 때 자를 index return
int findIndex(string s) {
    int left = 0, right = 0;
    int idx = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            idx = i;
            break;
        }
    }
    return idx + 1;
}
// 올바른 문자열 체크
bool checkNormalString(string& p) {
    stack<char> s;
    for (int i = 0; i < p.length(); i++) {
        if (s.empty()) {
            s.push(p[i]);
            continue;
        }
        if (p[i] == s.top()) {
            s.push(p[i]);
        } else {
            if (s.top() == '(' && p[i] == ')') {
                s.pop();
            } else {
                s.push(p[i]);
            }
        }
    }
    bool result = false;
    if (s.empty()) {
        result = true;
    } else {
        result = false;
    }

    while (!s.empty()) {
        s.pop();
    }
    return result;
}

string sol(string u, string v) {
    // cout << "u: " << u << endl;
    // cout << "v: " << v << endl;
    bool normal = checkNormalString(u);
    int idx = 0;
    string answer = "";
    if (normal) {
        if (v.length() == 0) {
            return u;
        } else {
            idx = findIndex(v);
            answer = u + sol(v.substr(0, idx), v.substr(idx));
        }
    } else {
        string ans = "";
        if (v.length() == 0) {
        } else {
            idx = findIndex(v);
            ans = sol(v.substr(0, idx), v.substr(idx));
            // cout << "v: empty,   " << ans << endl;
        }

        string ret = ans = "(" + ans + ")" + convert(u);
        return ret;
    }
    return answer;
}

string solution(string p) {
    string answer = "";
    if (p.length() == 0) {
        return p;
    }
    bool normal = checkNormalString(p);
    if (normal) {
        answer = p;
    } else {
        int idx = findIndex(p);
        answer = sol(p.substr(0, idx), p.substr(idx));
    }

    return answer;
}

int main(int argc, char const* argv[]) {
    string p = "(()())()";
    // string p = "()))((()";
    // string p = ")(";
    cout << solution(p) << endl;

    return 0;
}
