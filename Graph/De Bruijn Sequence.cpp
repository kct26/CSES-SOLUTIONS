#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 32768 + 5;
int n, mask;
vector<int> ans;
bool visited[MAX];

void dfs(int cur){
    for (int bit = 0; bit <= 1; bit++){
        int EdgeId = (cur << 1) | bit;
        if (visited[EdgeId]) continue;
        visited[EdgeId] = true;
        int nextBit = (EdgeId) & mask;
        dfs(nextBit);
        ans.push_back(bit);
    }
}

void process() {
    cin >> n;
    mask = (1 << (n - 1)) - 1;     
    dfs(0);
    for (int i = 0; i < n - 1; i++){
        cout << 0;
    }
    reverse(ans.begin(), ans.end());
    for (int& v : ans) cout << v;

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