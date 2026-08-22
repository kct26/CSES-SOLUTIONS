#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n, k;
ll a[MAX];

bool valid(ll check){
    int cur_k = 1;
    ll cur_sum = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > check) return false;
        if (cur_sum + a[i] > check){
            cur_sum = 0;
            cur_k++;
        }
        cur_sum += a[i];
    }
    return cur_k <= k;
}

void process() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll left = 1;
    ll right = 2e14;
    ll ans = right;
    while (left <= right){
        ll mid = (left + right) >> 1;
        if (valid(mid)){
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
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