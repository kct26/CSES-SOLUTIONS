#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;

struct Project{
    int start, end;
    ll reward;
};

int n;
Project a[MAX];
ll dp[MAX];

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].start >> a[i].end >> a[i].reward;
    sort(a, a + n, [](const Project &x, const Project &y){
        return x.end < y.end;
    });
    for (int i = 1; i <= n; i++){
        int cur_start = a[i-1].start;
        int ans = 0;
        int left = 0;
        int right = i - 1;
        while (left <= right){
            int mid = (left + right) >> 1;
            Project tmp = a[mid];
            if (tmp.end < cur_start){
                ans = mid + 1;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        dp[i] = max(dp[ans] + a[i-1].reward, dp[i-1]);
    }
    cout << dp[n];

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