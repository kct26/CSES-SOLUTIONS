#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;

int n;

void process() {
    cin >> n;
    vector<string> v = {"0","1"};
    for (int i = 0; i < n - 1; i++){
        vector<string> tmp(v.begin(), v.end());
        reverse(tmp.begin(), tmp.end());
        vector<string> final;
        for (string &s : v){
            final.push_back(s + "0");
        }
        for (string &s : tmp){
            final.push_back(s + "1");
        }
        v = final;
    }
    for (string &s : v) cout << s << "\n";
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