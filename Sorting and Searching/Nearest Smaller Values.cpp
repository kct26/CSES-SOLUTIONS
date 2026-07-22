#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n;
ll a[MAX];
stack<ll> st;

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        ans[i] = (st.empty() ? 0 : st.top() + 1);
        st.push(i);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
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