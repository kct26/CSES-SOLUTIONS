#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int a[MAX];
int n;
set<int> window;

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    int left = 0;
    for (int right = 0; right < n; right++){
        if (window.find(a[right]) == window.end()){
            ans = max(ans, right - left + 1);
        }
        else{
            while (window.find(a[right]) != window.end()){
                window.erase(a[left]);
                left++;
            }
        }
        window.insert(a[right]);
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