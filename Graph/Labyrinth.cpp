#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const int MAX = 1005;
int n,m,x_start,y_start,x_end,y_end;
char a[MAX][MAX];
char direction[MAX][MAX];
bool visited[MAX][MAX];
const int dr[4] = {0,0,-1,1};
const int dc[4] = {-1,1,0,0};
int step;

bool bfs(int i, int j){
    deque<pair<int,int>> dq;
    dq.push_back({i,j});
    visited[i][j] = true;
    step = 0;
    while (!dq.empty()){
        int sz = (int)dq.size();
        for (int _ = 0; _ < sz; _++){
            auto [r,c] = dq.front();
            if (r == x_end && c == y_end){
                return true;
            }
            dq.pop_front();
            for (int k = 0; k < 4; k++){
                int new_r = r + dr[k];
                int new_c = c + dc[k];
                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && !visited[new_r][new_c] && (a[new_r][new_c] == '.' || a[new_r][new_c] == 'B')){
                    visited[new_r][new_c] = true;
                    dq.push_back({new_r,new_c});
                    if (k == 0) direction[new_r][new_c] = 'L';
                    else if (k == 1) direction[new_r][new_c] = 'R';
                    else if (k == 2) direction[new_r][new_c] = 'U';
                    else direction[new_r][new_c] = 'D'; 
                } 
            }
        }
        step++;
    }
    return false;
}

void process() {
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                x_start = i;
                y_start = j;
            }
            else if (a[i][j] == 'B'){
                x_end = i;
                y_end = j;
            }
        }
    }
    bool valid = bfs(x_start,y_start);
    if (!valid) cout << "NO";
    else{
        cout << "YES" << "\n";
        cout << step << "\n";
        string ans = "";
        for (int i = 0; i < step; i++){
            char current = direction[x_end][y_end];
            ans += current;
            if (current == 'L') y_end++;
            else if (current == 'R') y_end--;
            else if (current == 'U') x_end++;
            else x_end--;
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
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