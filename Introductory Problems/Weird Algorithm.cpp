#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1000000007;

ll n;

void solve() {
    cin >> n;
    cout << n << " ";
    while (n != 1){
        if(n % 2 == 0) n /= 2;
        else n = n*3 + 1;
        cout << n << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}

