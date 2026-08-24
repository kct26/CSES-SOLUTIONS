#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;

int bit[MAX], a[MAX];
int n;

void update(int idx, int val){
    for (; idx <= n; idx += idx & -idx) bit[idx] += val;
}

int get(int idx){
    int res = 0;
    for (; idx >= 1; idx -= idx & -idx) res += bit[idx];
    return res;
}

void process() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, 1);
    }
    for (int i = 0; i < n; i++) {
        int pos; cin >> pos;
        int left = 1; 
        int right = n;
        int ans = right;
        while (left <= right){
            int mid = (left + right) >> 1;
            int tmp = get(mid);
            if (pos < tmp) right = mid - 1;
            else if (pos > tmp) left = mid + 1;
            else {
                ans = mid;
                right = mid - 1;
            }

        }
        update(ans, -1);
        cout << a[ans] << " ";
    }
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