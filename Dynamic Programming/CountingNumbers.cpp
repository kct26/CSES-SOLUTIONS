#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
ll a,b, cache[19][10][2][2];

ll dfs(int idx, int last_digit, bool is_tight, bool leading_zeroes, const string &exceed){
    if (idx == (int) exceed.size()) return 1ll;

    if (cache[idx][last_digit][is_tight][leading_zeroes] != -1) return cache[idx][last_digit][is_tight][leading_zeroes];

    int left = 0;
    int right = (is_tight ? exceed[idx] - '0' : 9);
    
    ll res = 0;

    for (int i = left; i <= right; i++){
        if (i == last_digit && !leading_zeroes) continue;
        res += dfs(idx + 1, i, is_tight && i == right, leading_zeroes && i == 0, exceed);
    }

    cache[idx][last_digit][is_tight][leading_zeroes] = res;

    return cache[idx][last_digit][is_tight][leading_zeroes];
}

ll count(ll a, ll b){
    a--;
    memset(cache, -1, sizeof cache);
    ll left = dfs(0, 0, true, true, to_string(a));
    memset(cache, -1, sizeof cache);
    ll right = dfs(0, 0, true, true, to_string(b));
    return right - left;
}

void process() {
    cin >> a >> b;
    ll ans = count(a, b);
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