#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;

int bit[MAX];
int n, a[MAX], compressed[MAX], dp[MAX];

void update(int idx, int val){
    val %= MOD;
    for (; idx <= n; idx += idx & -idx) bit[idx] = (bit[idx] + val) % MOD;
}

int get(int idx){
    int res = 0;
    for (; idx > 0; idx -= idx & - idx) res = (res + bit[idx]) % MOD;
    return res % MOD;
}

void process() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        v[i] = a[i];
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());   
    for (int i = 0; i < n; i++){
        compressed[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }
    for (int i = 0; i < n; i++){
        int cur_find = compressed[i];
        int newSub = get(cur_find - 1);
        int val = (1 + newSub) % MOD;
        update(cur_find, val);
    }
    int ans = get(n);
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