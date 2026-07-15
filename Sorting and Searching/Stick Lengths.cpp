#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
ll a[MAX];
int n;

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll ans = 4e18;
    ll target = a[n/2];
    ll tmp = 0;
    for (int i = 0; i < n; i++){
        tmp += abs(a[i] - target);
    }
    ans = min(ans, tmp);    
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