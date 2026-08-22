#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;

char a[8][8];
bool posDiag[20], negDiag[20], row[8], col[8];
ll cnt;

ll dfs(ll r, ll c){
    if (row[r] || col[c] || posDiag[r+c] || negDiag[r-c+8] || a[r][c] == '*') return 0;
    if (r == 7) return 1;
    row[r] = true;
    col[c] = true;
    posDiag[r+c] = true;
    negDiag[r-c+8] = true;
    ll cnt = 0;
    for (int i = 0; i < 8; i++){
        cnt += dfs(r+1,i);
    }
    row[r] = false;
    col[c] = false;
    posDiag[r+c] = false;
    negDiag[r-c+8] = false;
    return cnt;
}

void process() {
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 8; i++){
        if (a[0][i] != '*') cnt += dfs(0, i);
    }
    cout << cnt;
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