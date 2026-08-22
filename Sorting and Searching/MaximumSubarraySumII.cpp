#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
const ll INF = 4e18;

ll arr[MAX], pref[MAX], ans;
int n,a,b;

void process() {
    cin >> n >> a >> b;
    ans = -INF;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + arr[i-1];
    deque<ll> dq;
    for (int i = a; i <= n; i++){
        while (!dq.empty() && pref[dq.back()] >= pref[i - a]){
            dq.pop_back();
        }
        dq.push_back(i - a);
        while (!dq.empty() && dq.front() < i - b) dq.pop_front();
        if (!dq.empty()) ans = max(ans, pref[i] - pref[dq.front()]);
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