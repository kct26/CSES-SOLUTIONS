#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 1005;
const int dr[] = {-2,-2,-1,+1,+2,+2,+1,-1};
const int dc[] = {-1,+1,+2,+2,+1,-1,-2,-2};
int n;
int dist[MAX][MAX];

bool isValid(int x, int y){
    if (x >= 0 && x < n && y >= 0 && y < n) return true;
    return false;
}

void bfs(int x, int y){
    memset(dist, -1, sizeof dist);
    queue<pair<int,int>> q;
    q.push({x,y});
    dist[x][y] = 0;
    while (!q.empty()){
        pair<int,int> p = q.front();
        int r = p.first, c = p.second;
        q.pop();
        for (int k = 0; k < 8; k++){
            int new_r = r + dr[k];
            int new_c = c + dc[k];
            if (isValid(new_r,new_c) && dist[new_r][new_c] == -1) {
                q.push({new_r,new_c});
                dist[new_r][new_c] = dist[r][c] + 1;
            }
        }
    }
}

void process() {
    cin >> n;
    bfs(0,0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << dist[i][j] << " ";
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