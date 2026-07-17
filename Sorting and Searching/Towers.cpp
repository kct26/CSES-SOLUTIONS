#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n;
int a[MAX];

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    multiset<int> towers;
    for (int i = 0; i < n; i++){
        auto it = towers.upper_bound(a[i]);
        if (it != towers.end()) towers.erase(it);
        towers.insert(a[i]);
    }
    cout << towers.size() << "\n";
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