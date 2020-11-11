#include <iostream>
#include <vector>
#define ll   long long
using namespace std;

int n, m, test;
int cnt = 0;
ll cache[40][40];

ll sol(int f, int h){
	ll &ret = cache[f][h];
	if (f == 0 && h == 0) {
        return 1;
	}
	if (ret != 0) return ret;
	if (f != 0) ret += sol(f - 1, h + 1);
	if (h != 0) ret += sol(f, h - 1);
	return ret;
}

int main(int argc, char const *argv[]) {
	// freopen("input.txt", "r", stdin);
	int n;
	while (cin >> n){
		if (n == 0) break;
		else
			cout << sol(n, 0) << endl;
	}
}

// int N, W, H;
// long long int cnt;
// int flag[6];
//
// void dfs(int W, int H, int depth) {
//     if (depth == 2*N) {
//         cnt++;
//         // for (size_t i = 0; i < 6; i++) {
//         //     if (flag[i] == 1) {
//         //         cout << "1" << " ";
//         //     }
//         //     else
//         //         cout << "0" << " ";
//         // }
//         // cout << endl;
//
//         return;
//     }
//
//     if (W > 0) {
//         // cout << "W" << " ";
//         // flag[depth] = 1;
//         // cout << "W : " << W << ", " << "H : " << H << " depth  :" << depth << endl;
//         dfs(W-1, H+1, depth+1);
//         // flag[depth] = 0;
//     }
//
//     if (H > 0) {
//         // cout << "H" << " ";
//         // flag[depth] = 0;
//         // cout << "W : " << W << ", " << "H : " << H << " depth  :" << depth << endl;
//         dfs(W, H-1, depth+1);
//         // flag[depth] = 1;
//     }
//
//
// }
// int main(int argc, char const *argv[]) {
//     // freopen("input.txt", "r", stdin);
//     while (true) {
//         cin >> N;
//         if (!N) break;
//         W = N;
//         // cout << W << ", " << H << endl;
//         // cout << "1" << " ";
//         // flag[0] = true;
//         dfs(N-1, H+1, 1);
//         cout << cnt << endl;
//     }
//
//     return 0;
// }
