#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MAX = 200005;
const int MOD = 1000000007;
const int LOG = 31;
int n,q,up[MAX][LOG];


void process() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> up[i][0];
    }

    // preprocessing (N log K)

    for (int i = 1; i < LOG; i++){
        for (int j = 1; j <= n; j++){
            up[j][i] = up[up[j][i-1]][i-1]; 
        }
    }

    //process queries (Q log K)

    while (q--){
        int x,k;
        cin >> x >> k;
        for (int i = 0; i < LOG; i++){
            if (k & (1 << i)) x = up[x][i];
        }
        cout << x << "\n";
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