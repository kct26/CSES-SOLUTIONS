#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
int n;
queue<int> q;

void process() {
    cin >> n;
    for (int i = 1; i <= n; i++) q.push(i);
    while (!q.empty()){
        int tmp = q.front();
        q.pop();
        q.push(tmp);
        cout << q.front() << " ";
        q.pop();
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