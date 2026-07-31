#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n;
int a[MAX];

int LIS(){
    vector<int> v;
    for (int i = 0; i < n; i++){
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        if (it == v.end()) v.push_back(a[i]);
        else *it = a[i];
    }
    return (int) v.size();

}

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = LIS();
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