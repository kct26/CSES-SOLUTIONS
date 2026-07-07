#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;

ll a,b;

void process() {
    cin >> a >> b;
    // a - 2*x - y = 0
    // b - x - 2*y = 0
    // 2*x + y = a
    // 2*y + x = b
    // x = b - 2*y
    // 2 * (b - 2*y) + y = a
    // 2*b - 4*y + y - a = 0
    // 2*b - 3*y - a = 0
    // 2*b - a = 3*y
    // => 2*a - b = 3*x
    ll check1 = 2*b - a;
    ll check2 = 2*a - b;
    if (check1 >= 0 && check1 % 3 == 0 && check2 >= 0 && check2 % 3 == 0) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test = 1;
    cin >> test;
    while (test--) {
        process();
    }
    return 0;
}