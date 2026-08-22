#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n;
pair<int,int> a[MAX];

void process() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        cin >> a[i].second;
    }
    sort(a, a + n,[](const pair<int,int> a, const pair<int,int> b){
        return a.second < b.second;
    });
    int ans = 1;
    int cur_start = a[0].first, cur_end = a[0].second;
    for (int i = 1; i < n; i++){
        if (cur_end <= a[i].first){
            ans++;
            cur_start = a[i].first;
            cur_end = a[i].second;
        }
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