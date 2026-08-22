#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n;
ll a[MAX], ans;

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    ll maxE = *max_element(a, a + n);
    ans = max(ans, 2*maxE);
    cout << ans;
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