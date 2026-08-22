#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 105;
int a[MAX], dp[100005], n;

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 100000; j >= 1; j--) {
            if (j - a[i] >= 0 && dp[j-a[i]] == 1) dp[j] = 1;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= 100000; i++) if (dp[i]) ans.push_back(i);
    cout << (int) ans.size() << "\n";
    for (int &u : ans) cout << u << " ";
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