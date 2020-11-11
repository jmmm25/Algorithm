#include <iostream>
#define ll      long long
using namespace std;

ll int N, B, C;
ll int A[1000001];

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cin >> B >> C;
    ll int total = 0;

    for (int i=0; i<N; i++) {
        ll int master_p = 0, vice_p = 0;
        ll int people = A[i];
        master_p++;
        people -= B;
        if (people < 0) {
            total += master_p;
            continue;
        }
        else {
            if (people % C != 0) {
                vice_p = (people / C) + 1;
            }
            else if (people % C == 0) {
                vice_p = people / C;
            }
        }
        total += (master_p + vice_p);

        // cout << "mas , vice : " << master_p << "," << vice_p << endl;
    }

    cout << total << endl;
    return 0;
}
