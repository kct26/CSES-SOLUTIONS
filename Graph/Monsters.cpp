#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lb long double
#define mod 1000000007

const int INF = (int) 1e9;
const int MAX = 1005;
char a[MAX][MAX], direction[MAX][MAX];
int t[MAX][MAX];
int n,m,step;
vector<pair<int,int>> monster;
bool visited[MAX][MAX];
pair<int,int> startPos,endPos;
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};
const char dir[] = {'L', 'R', 'U', 'D'};

bool valid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void bfs_monster(){
    queue<pair<int,int>> q;
    for (auto &p : monster){
        q.push(p);
    }
    while (!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++){
            int new_x = x + dx[k];
            int new_y = y + dy[k];
            if (valid(new_x,new_y) && a[new_x][new_y] != '#' && t[new_x][new_y] >= INF){
                t[new_x][new_y] = t[x][y] + 1;
                q.push({new_x,new_y});
            }
        }
    }
}

bool bfs_source(pair<int,int> &p){
    queue<pair<int,int>> q;
    q.push(p);
    visited[p.first][p.second] = true;
    step = 0;
    while (!q.empty()){
        int sz = (int)q.size();
        for (int s = 0; s < sz; s++){
            auto [x,y] = q.front();
            q.pop();
            if (x == 0 || x == n-1 || y == 0 || y == m-1) {
                endPos = {x,y};
                return true;
            }
            for (int k = 0; k < 4; k++){
                int new_x = x + dx[k];
                int new_y = y + dy[k];
                if (valid(new_x,new_y) && !visited[new_x][new_y] && a[new_x][new_y] == '.' && step+1 < t[new_x][new_y]){
                    direction[new_x][new_y] = dir[k];
                    visited[new_x][new_y] = true;
                    q.push({new_x,new_y});
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
            t[i][j] = INF;
            if (a[i][j] == 'M') {
                monster.push_back({i,j});
                t[i][j] = 0;
            }
            else if (a[i][j] == 'A') startPos = {i,j};
        }
    }
    bfs_monster();
    bool canEscape = bfs_source(startPos);
    if (!canEscape) cout << "NO";
    else{
        cout << "YES" << "\n" << step << "\n";
        string ans = "";
        for (int i = 0; i < step; i++){
            char cur = direction[endPos.first][endPos.second];
            ans += cur;
            if (cur == 'R') endPos.second--;
            else if (cur == 'L') endPos.second++;
            else if (cur == 'U') endPos.first++;
            else endPos.first--;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
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