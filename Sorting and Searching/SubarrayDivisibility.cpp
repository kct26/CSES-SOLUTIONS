#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n;
ll a[MAX], r[MAX], cur, cnt;

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    r[0] = 1;
    for (int i = 0; i < n; i++){
        cur = (cur + a[i] % n + n) % n;
        cnt += r[cur];
        r[cur]++;
    }
    cout << cnt;
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