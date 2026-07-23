#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n;
ll target, cur, cnt;
ll a[MAX];
unordered_set<ll> seen;

void process() {
    cin >> n >> target;
    for (int i = 0; i < n; i++) cin >> a[i];
    seen.insert(0);
    for (int i = 0; i < n; i++){
        cur += a[i];
        ll need = cur - target;
        if (seen.find(need) != seen.end()) cnt++;
        seen.insert(cur);
    }
    cout << cnt;
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