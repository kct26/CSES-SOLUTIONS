#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 10;
vector<string> ans;
vector<char> v;
string s;
int n;
bool used[MAX];

void dfs(string &s){
    if ((int) s.size() == n) {
        ans.push_back(s);
        return;
    }
    for (int i = 0; i < n; i++){
        if (used[i]) continue;
        if (i > 0 && v[i-1] == v[i] && !used[i-1]) continue;
        s += v[i];
        used[i] = true;
        dfs(s);
        used[i] = false;
        s.pop_back();
    }

}

void process() {
    cin >> s;
    n = (int) s.size();
    sort(s.begin(), s.end());
    v.assign(s.begin(), s.end());
    string s = "";
    dfs(s);
    cout << (int) ans.size() << "\n";
    for (string &s : ans) cout << s << "\n";

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