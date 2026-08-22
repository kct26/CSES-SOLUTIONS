#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int dr[] = {1,0,-1,0};
const int dc[] = {0,1,0,-1};
const char direction[] = {'D','R','U','L'};
bool visited[8][8], inside[8][8];
string s;
ll paths;

bool isValid(int r, int c){
    return (inside[r][c] && !visited[r][c]);
}

void dfs(int idx, int r, int c){
    visited[r][c] = true;
    if (r == 7 && c == 1){
        if (idx == 48) paths++;
        return;
    }
    if (idx == 48) return;
    bool valid[4];
    for (int i = 0; i < 4; i++){
        valid[i] = isValid(r + dr[i], c + dc[i]);
    }
    bool down = valid[0];
    bool right = valid[1];
    bool up = valid[2];
    bool left = valid[3];
    if (right && left && !up && !down) return;
    if (up && down && !right && !left) return;
    if (s[idx] != '?'){
        for (int i = 0; i < 4; i++){
            if (s[idx] == direction[i] && valid[i]){
                dfs(idx + 1, r + dr[i], c + dc[i]);
                visited[r + dr[i]][c + dc[i]] = false;
                return;
            }
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (valid[i]){
            dfs(idx + 1, r + dr[i], c + dc[i]);
            visited[r + dr[i]][c + dc[i]] = false;
        }
    } 
    return;
}

void process() {
    cin >> s;
    memset(inside, true, sizeof inside);
    for (int i = 0; i <= 7; i++) {
        inside[0][i] = false;
        inside[i][0] = false;
    }
    dfs(0, 1, 1);
    cout << paths;

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