#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const int MAX = 1005;
int n,m;
char a[MAX][MAX];
bool visited[MAX][MAX];
int dc[4] = {0,1,-1,0};
int dr[4] = {1,0,0,-1};

void bfs(int i, int j){
    deque<pair<int,int>> dq;
    dq.push_back({i,j});
    visited[i][j] = true;
    while (!dq.empty()){
        auto [r,c] = dq.front();
        dq.pop_front();
        for (int i = 0; i < 4; i++){
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && 
            !visited[new_r][new_c] && a[new_r][new_c] == '.'){
                visited[new_r][new_c] = true;
                dq.push_back({new_r,new_c});
            } 
        }
    }
}

void process() {
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] == '.' && !visited[i][j]){
                cnt++;
                bfs(i,j);
            }
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