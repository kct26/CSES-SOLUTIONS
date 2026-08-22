#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
// 12345678910111213141516171819202122232425...
// 9 -> 2*90 -> 3*900 -> 4*9000 -> 5*90000
void process() {
    ll k;
    cin >> k;
    if (k <= 9){
        cout << k << "\n";
        return;
    }
    ll check = 0;
    ll mul9 = 9;
    ll length = 1;
    while (length < 20){ 
        check = length * mul9;
        if (k <= check) break;
        k -= check;
        mul9 *= 10;
        length++;
    }
    ll ith = (k + length - 1) / length;
    ll num = mul9/9 - 1 + ith;
    if (k % length == 0) {
        cout << num % 10 << "\n";
        return;
    }
    ll digit = length - k % length;
    while (digit){
        num /= 10;
        digit--;
    }
    cout << num % 10 << "\n";
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