#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;

int bit[MAX];
int n,k;

void update(int idx, int val){
    for (; idx <= n; idx += idx & -idx){
        bit[idx] += val;
    }
}

int get(int idx){
    int res = 0;
    for(; idx >= 1; idx -= idx & -idx){
        res += bit[idx];
    }
    return res;
}

int find_kth(int k){
    int left = 1;
    int right = n;
    while (left <= right){
        int mid = (left + right) >> 1;
        int check = get(mid);
        if (check >= k) right = mid - 1;
        else if (check < k) left = mid + 1;
    }
    return left;
}

void process() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) update(i, 1);
    int current_sum = 0;
    for (int active = n; active > 0; active--){
        current_sum = (current_sum + k) % active;
        int current_child = find_kth(current_sum + 1);
        cout << current_child << " ";
        update(current_child, -1);
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