#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n, q;
set<int> lights;
multiset<int> lengths;

void process() {
    cin >> n >> q;
    lights.insert(0);
    lights.insert(n);
    lengths.insert(n);
    while (q--){
        int add; cin >> add;
        lights.insert(add);
        auto left = lights.find(add);
        auto right = lights.upper_bound(add);
        left--;
        int L = *left;
        int R = *right;
        lengths.erase(lengths.find(R - L));
        lengths.insert(add - L);
        lengths.insert(R - add); 
        cout << *lengths.rbegin() << " ";
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