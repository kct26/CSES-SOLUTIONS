#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 105;
bool row[MAX][2*MAX], col[MAX][2*MAX];
int a[MAX][MAX];
int n;

void process() {
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int mex = 0;
            while (row[i][mex] || col[j][mex]) mex++;
            a[i][j] = mex;
            row[i][mex] = true;
            col[j][mex] = true;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
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