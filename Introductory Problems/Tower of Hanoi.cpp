#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;

int n;

void dfs(int cur, int from, int to){
    if (cur == 0) return;
    dfs(cur - 1, from, 6 - to - from);
    cout << from << " " << to << "\n";
    dfs(cur - 1, 6 - to - from, to);
}

void process() {
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    dfs(n, 1, 3);
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