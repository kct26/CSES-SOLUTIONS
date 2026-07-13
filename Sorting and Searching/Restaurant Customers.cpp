#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
map<int,int> timeline;
int n;

void process() {
    cin >> n;
    for (int i = 0; i < n; i++){
        int in,out;
        cin >> in >> out;
        timeline[in] = 1;
        timeline[out] = -1;
    }
    int ans = 1;
    int cur = 0;
    for (pair<int,int> p : timeline){
        cur += p.second;
        ans = max(ans, cur);
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