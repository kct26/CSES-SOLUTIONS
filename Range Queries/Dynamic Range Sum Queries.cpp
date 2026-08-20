#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;

ll a[MAX], bit[MAX];
int n, q;

ll get(int i){
    ll res = 0;
    for (; i >= 1; i -= i & - i) res += bit[i];
    return res;  
}

void update(int i, ll x){
    for (; i <= n; i += i & -i) bit[i] += x;
}

ll getSumRange(int l, int r){
    return get(r) - get(l - 1);
}


void process() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);
    }
    while (q--){
        ll type, l, r, u, k;
        cin >> type;
        if (type == 1){
            cin >> k >> u;
            ll dif = u - a[k];
            update(k, dif);
            a[k] = u;
        }
        else{
            cin >> l >> r;
            cout << getSumRange(l, r) << "\n";
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