#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
int ans[8][8];
int r,c,step;
bool visited[8][8];

bool valid(int x, int y){
    if (0 <= x && x < 8 && 0 <= y && y < 8 && !visited[x][y]) return true;
    return false;
}

int dx[] = {-1,-2,-2,-1,1,2,2,1};
int dy[] = {-2,-1,1,2,2,1,-1,-2}; 

int degree(int x, int y){
    int degree = 0;
    for (int i = 0; i < 8; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (valid(new_x,new_y)) degree++;
    }
    return degree;
}

bool dfs(int x, int y){
    if (step == 64) return true;
    vector<pair<int, pair<int,int>>> moves;
    for (int i = 0; i < 8; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (valid(new_x, new_y)){
            int cnt = degree(new_x,new_y);
            moves.push_back({cnt, {new_x,new_y}});
        }
    }
    step++;
    sort(moves.begin(), moves.end());
    for (auto &p : moves){
        int new_x = p.second.first;
        int new_y = p.second.second;
        visited[new_x][new_y] = true;
        ans[new_x][new_y] = step;
        if (dfs(new_x,new_y)) return true;
        visited[new_x][new_y] = false;
        ans[new_x][new_y] = 0;
    }
    step--;
    return false;
}

void process() {
    cin >> c >> r;
    step++;
    visited[r-1][c-1] = true;
    ans[r-1][c-1] = step;
    dfs(r-1,c-1);
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cout << ans[i][j] << " ";
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