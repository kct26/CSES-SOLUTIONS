#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
ll x,y;


void process() {
    cin >> x >> y;
    if (x > y){
        if (x % 2 == 0) cout << x*x - (y-1) << "\n";
        else cout << x*x - (x-1) - (x - y) << "\n";
    }
    else{
        if (y % 2 == 0) cout << y*y - (y-1) - (y - x) << "\n";
        else cout << y*y - (x-1) << "\n";
    }

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