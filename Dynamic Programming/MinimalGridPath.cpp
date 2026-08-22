#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 3005;

int n;
bool seen[MAX][MAX];
char a[MAX][MAX];

bool valid (int r, int c){
    return (r >= 0 && r < n && c >= 0 && c < n);
}

void bfs (int x, int y){
    string ans = "";
    ans += a[x][y];
    deque<pair<int,int>> dq;
    dq.push_back({x,y});
    seen[x][y] = true;
    char min_char;
    while (!dq.empty()){
        int s = (int) dq.size();
        min_char = 'Z' + 1;
        vector<pair<int,int>> next_layer;
        for (int i = 0; i < s; i++){
            pair<int,int> p = dq.front();
            dq.pop_front();
            int r = p.first, c = p.second;
            if (valid(r + 1, c) && !seen[r+1][c]){
                seen[r+1][c] = true;
                next_layer.push_back({r + 1, c});
                min_char = min(min_char, a[r+1][c]);
            }
            if (valid(r, c + 1) && !seen[r][c+1]){
                seen[r][c+1] = true;
                next_layer.push_back({r, c + 1});
                min_char = min(min_char, a[r][c+1]);
            }
        }
        if (next_layer.empty()) break;
        ans += min_char;
        for (pair<int,int> p: next_layer){
            int r = p.first, c = p.second;
            if (a[r][c] == min_char){
                dq.push_back(p);
            }
        }
    }
    cout << ans;
}

void process() {
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            char tmp; cin >> tmp;
            a[i][j] = tmp;
        }
    }
    bfs(0,0);
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