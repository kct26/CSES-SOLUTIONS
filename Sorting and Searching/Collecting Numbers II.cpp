#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
const int INF = INT_MAX;
int n,q;
int pos[MAX], arr[MAX];

void process() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr[i] = tmp;
        pos[tmp] = i;
    }
    int cnt = 1;
    for (int i = 2; i <= n; i++){
        if (pos[i] < pos[i-1]) {
            cnt++;
        }
    }
    while (q--){
        int a,b; cin >> a >> b;
        int x = arr[a-1];
        int y = arr[b-1];
        set<pair<int,int>> check;
        if (x - 1 > 0) check.insert({x - 1, x});
        if (x + 1 <= n) check.insert({x, x + 1});
        if (y - 1 > 0) check.insert({y - 1, y});
        if (y + 1 <= n) check.insert({y, y + 1});
        for (pair<int,int> p : check){
            if (pos[p.second] < pos[p.first]) cnt--;
        }
        swap(arr[a-1], arr[b-1]);
        swap(pos[x], pos[y]);
        for (pair<int,int> p : check){
            if (pos[p.second] < pos[p.first]) cnt++;
        }
        cout << cnt << '\n';
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