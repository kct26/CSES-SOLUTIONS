#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 1005;
int n;
ll target;
ll a[MAX];
unordered_map<ll, pair<int,int>> m;

void process() {
    cin >> n >> target;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            ll complement = target - a[i] - a[j];
            if (m.find(complement) != m.end()){
                cout << i + 1 << " " << j + 1 << " " << m[complement].first + 1 << " " << m[complement].second + 1;
                return;
            }
        }   
        for (int k = 0; k < i; k++) m[a[k] + a[i]] = {i,k}; // adding all pairs end before i
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