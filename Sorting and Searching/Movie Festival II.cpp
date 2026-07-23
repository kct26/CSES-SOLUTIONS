#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n,k,cnt;
pair<int,int> a[MAX];
multiset<int> available;

void process() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a, a + n, [](const pair<int,int> x, const pair<int,int> y){
        return x.second < y.second;
    });
    for (int i = 0; i < k; i++) available.insert(0);
    for (int i = 0; i < n; i++){
        auto it = available.upper_bound(a[i].first);
        if (it == available.begin()) continue;
        else{
            it--;
            available.erase(it);
            available.insert(a[i].second);
            cnt++;
        }
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