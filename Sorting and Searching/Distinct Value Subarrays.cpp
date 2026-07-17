#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n;
int a[MAX];
set<int> window;
ll cnt;

// count the number of subarray ending at right
// [1,2,1,3]
// 1 : 1
// 2 : 2
// 1:  2
// 3 : 3

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll left = 0;
    ll right = 0;
    while (right < n){
        while (window.find(a[right]) != window.end()){
            window.erase(a[left]);
            left++;
        }
        cnt += right - left + 1;
        window.insert(a[right]);
        right++;
    }
    cout << cnt << "\n";
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