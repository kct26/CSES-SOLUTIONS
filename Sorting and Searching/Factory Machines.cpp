#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n;
ll t, a[MAX];

bool valid(ll given_time){
    ll produce = 0;
    for (int i = 0; i < n; i++){
        produce += given_time / a[i];
        if (produce >= t) return true;
    }
    return false;
}

void process() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll left = 0;
    ll right = 3e18;
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