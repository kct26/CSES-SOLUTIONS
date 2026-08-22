#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n,x;
int a[MAX];
map<int,int> seen;

void process() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++){
        int need = x - a[i];
        if (seen.find(need) != seen.end()){
            cout << seen[need] + 1 << " " << i + 1;
            return;
        }
        seen[a[i]] = i;
    }
    cout << "IMPOSSIBLE";
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