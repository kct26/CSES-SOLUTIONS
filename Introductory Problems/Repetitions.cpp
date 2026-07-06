#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1000000007;
string s;

void solve() {
    cin >> s;
    int ans = 1;
    int left = 0;
    for (int i = 1; i < (int) s.size(); i++){
        if (s[i] == s[i-1] && (s[i] == 'A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'X')){
            ans = max(ans, i - left + 1);
        }
        else left = i;
    }    
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}