#include<iostream>
#include<cstring>
#include<vector>
#define MAX_COUNT		6
using namespace std;
int k;
int number[50], flag[50];

void powerset(int n, int depth) {
	if (n == depth) {
		vector<int> save_number;
		for (size_t i = 0; i < n; i++) {
			if (flag[i] == 1) {
				// cout << number[i] << " ";
				save_number.push_back(number[i]);
			}
		}

		if (save_number.size() == MAX_COUNT) {
			for (size_t i = 0; i < save_number.size(); i++) {
				cout << save_number.at(i) << " ";
			}
			cout << "\n";
		}
		return;
	}
	
	flag[depth] = 1;
	powerset(n, depth+1);
	flag[depth] = 0;
	powerset(n, depth+1);
}



int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	while (true) {
		cin >> k;
		if (k == 0) {
			break;
		}
		memset(number, 0, sizeof(number));
		memset(flag, 0,	sizeof(flag));
		for (size_t i = 0; i < k; i++) {
			cin >> number[i];
		}
		// for (size_t i = 0; i < k; i++) {
		// 	cout << number[i] << " ";
		// }
		// cout << endl;
		powerset(k, 0);
		cout << "\n";
	}
	return 0;
}
