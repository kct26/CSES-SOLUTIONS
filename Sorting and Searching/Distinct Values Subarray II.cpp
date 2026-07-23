#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
ll n, k, cur, cnt;
ll a[MAX];
map<ll, ll> seen;

void process() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll left = 0;
    for (ll right = 0; right < n; right++){
        seen[a[right]]++;
        if (seen[a[right]] == 1) cur++;
        while (cur > k){
            seen[a[left]]--;
            if (seen[a[left]] == 0) cur--;
            left++;
        }
        cnt += right - left + 1;
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