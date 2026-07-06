#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
ll n;

void process() {
    cin >> n;   
    ll sum = n*(n+1)/2;
    if (sum % 2 != 0) {
        cout << "NO";
        return;
    }
    ll need = sum/2;
    vector<ll> v1,v2;
    ll s1 = 0, s2 = 0;
    for (ll i = n; i >= 1; i--){
        if (s1 + i <= need) {
            s1 += i;
            v1.push_back(i);
        }
        else{
            s2 += i;
            v2.push_back(i);
        }
    }
    cout << "YES" << "\n";
    cout << (int) v1.size() << "\n";
    for (ll &u : v1) cout << u << " ";
    cout << "\n";
    cout << (int) v2.size() << "\n";
    for (ll &u : v2) cout << u << " ";


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