#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int mod = 1000000007;
int n;
 
void solve() {
    cin >> n;
    if (n == 1){
        cout << 1;
        return;
    }
    if (n < 4){
        cout << "NO SOLUTION";
        return;
    }
    for (int i = 2; i <= n; i+=2){
        cout << i << " ";
    }
    for (int i = 1; i <= n; i+=2){
        cout << i << " ";
    }
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
