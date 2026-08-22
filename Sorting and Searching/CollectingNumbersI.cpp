#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
const int INF = INT_MAX;
int n;
int a[MAX];

void process() {
    cin >> n;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        a[tmp] = i;
    }
    int cnt = 1;
    for (int i = 2; i <= n; i++){
        if (a[i] < a[i-1]) cnt++;
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