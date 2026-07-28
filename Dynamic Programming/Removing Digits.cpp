#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 1000005;
int n, step;

void process() {
    cin >> n;
    while (n > 0){
        int max_digit = 0;
        int x = n;
        while (x > 0){
            max_digit = max(max_digit, x % 10);
            x /= 10;
        }
        n -= max_digit;
        step++;
    }
    cout << step;
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