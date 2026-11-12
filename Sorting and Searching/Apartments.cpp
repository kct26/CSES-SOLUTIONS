#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n,m,k,cnt;
int applicants[MAX], apartments[MAX];

void process() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> applicants[i];
    for (int i = 0; i < m; i++) cin >> apartments[i];
    int cur = 0;
    sort(applicants, applicants + n);
    sort(apartments, apartments + m);
    for (int i = 0; i < n; i++){
        while (cur < m && apartments[cur] < applicants[i] - k) cur++;
        if (apartments[cur] >= applicants[i] - k && apartments[cur] <= applicants[i] + k){
            cnt++;
            cur++;
        }
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