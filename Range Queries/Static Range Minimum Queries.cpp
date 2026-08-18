#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
const int LG = 17;

int lg2[MAX], a[MAX], st[LG + 1][MAX];
int n, q;

void buildLog2(){
    lg2[1] = 0;
    for (int i = 2; i < MAX; i++) lg2[i] = lg2[i/2] + 1;
}

void preprocess(){
    for (int i = 1; i <= n; i++) st[0][i] = a[i];
    for (int i = 1; i <= LG; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n ; j++){
            st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i - 1))]);
        }
    }
}

void process() {
    int a, b;
    cin >> a >> b;
    int len = b - a + 1;
    if (len == 1) {
        cout << st[0][a] << "\n";
        return;
    }
    int log = lg2[len];
    int ans = min(st[log][a], st[log][b - (1 << log) + 1]);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test = 1;
    cin >> n >> test;
    for (int i = 1; i <= n; i++) cin >> a[i];
    buildLog2();
    preprocess();
    while (test--) {
        process();
    }
    return 0;
}