#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;

void process() {
    int n,a,b;
    cin >> n >> a >> b;
    if (a + b > n || (a > 0 && b == 0) || (b > 0 && a == 0)) {
        cout << "NO" << "\n";
        return;
    }
    int draw = n - (a + b);
    vector<int> m1,m2;
    for (int i = 1; i <= draw; i++){
        m1.push_back(i);
        m2.push_back(i);
    }
    int start = draw + 1;
    int end = n;
    for (int i = start; i < start + b; i++) m1.push_back(i);
    for (int i = end - b + 1; i <= end; i++) m2.push_back(i);
    for (int i = start + b; i <= end; i++) m1.push_back(i);
    for (int i = start; i < start + a; i++) m2.push_back(i);
    cout << "YES" << "\n";
    for (int &u : m1) cout << u << " ";
    cout << "\n";
    for (int &u : m2) cout << u << " ";
    cout << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test = 1;
    cin >> test;
    while (test--) {
        process();
    }
    return 0;
}