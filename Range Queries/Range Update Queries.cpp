#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;

ll a[MAX], bit[MAX];
int n, q;

void update(int i, ll x){
    for (; i <= n; i += i & -i) bit[i] += x;
}

ll get(int i){
    ll res = 0;
    for (; i >= 1; i -= i & -i) res += bit[i];
    return res;
}

void process() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);
        update(i + 1, - a[i]);
    }    
    while (q--){
        int type; cin >> type;
        if (type == 1){
            int l, r, u;
            cin >> l >> r >> u;
            update(l, u);
            update(r + 1, -u);
        }
        else{
            int idx; cin >> idx;
            cout << get(idx) << "\n";
        }
    }
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