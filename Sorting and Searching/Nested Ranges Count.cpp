#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int n;

struct Interval{
    int start, end, id;
};

vector<int> compression;
Interval a[MAX];
int bit[MAX], q1[MAX], q2[MAX];

void update(int idx, int val){
    for (; idx <= n; idx += idx & -idx) bit[idx] += val;
}

int get(int idx){
    int res = 0;
    for (int i = idx; i >= 1; i -= i & - i) res += bit[i];
    return res;
}

int get_fenwick_idx(int time){
    return lower_bound(compression.begin(), compression.end(), time) - compression.begin()+1; 
}

void process() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i].start >> a[i].end;
        a[i].id = i;
        compression.push_back(a[i].end);
    }
    sort(a, a + n, [](const Interval a, const Interval b){
        return a.start < b.start || (a.start == b.start && a.end > b.end);
    });
    sort(compression.begin(), compression.end());
    auto it = unique(compression.begin(), compression.end());
    compression.erase(it, compression.end());
    for (int i = 0; i < n; i++){
        int idx = get_fenwick_idx(a[i].end);
        q2[a[i].id] = i - (idx == 1 ? 0 : get(idx-1));  // in i intervals already check, num of end time >= current
        update(idx, 1);
    }
    memset(bit, 0, sizeof bit);
    for (int i = n - 1; i >= 0; i--){
        int idx = get_fenwick_idx(a[i].end);
        q1[a[i].id] = get(idx);
        update(idx, 1);
    }
    for (int i = 0; i < n; i++) cout << q1[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) cout << q2[i] << " ";
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