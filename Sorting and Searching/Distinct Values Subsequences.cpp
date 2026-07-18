#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
int n;
map<int, ll> freq;

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        freq[tmp]++;
    }
    ll ans = 1;
    for (pair<int,ll> p : freq){
        ans = ans * (p.second + 1); 
        ans %= MOD;
    }
    cout << ans - 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test = 1;
    // cin >> test;
    while (test--) {
        process();
    }
    return 0;
}