#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
const int INF = 200005;

int n;

struct Interval{
    int start, end, id;
};

Interval a[MAX];
priority_queue<int, vector<int>, greater<int>> available;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> used;
int ans[MAX];

void process() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].start >> a[i].end;
        a[i].id = i;
        available.push(i);
    }
    sort(a + 1, a + n + 1, [](const Interval a, const Interval b){
        return a.start < b.start || (a.start == b.start && a.end < b.end);
    });
    int min_rooms = 0;
    for (int i = 1; i <= n; i++){
        while (!used.empty() && used.top().first < a[i].start){
            pair<int,int> tmp = used.top();
            used.pop();
            available.push(tmp.second);
        }
        int assign_room = available.top();
        available.pop();
        ans[a[i].id] = assign_room;
        used.push({a[i].end,assign_room});
        min_rooms = max(min_rooms, (int) used.size());
    }
    cout << min_rooms << "\n";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    
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