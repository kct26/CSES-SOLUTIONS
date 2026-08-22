#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;

struct Interval{
    int start, end, id;
};

int n;
Interval a[MAX];
bool q1[MAX], q2[MAX];

void process() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i].start >> a[i].end;
        a[i].id = i;
    }
    sort(a, a + n, [](const Interval a, const Interval b){
        return a.start < b.start || (a.start == b.start && a.end > b.end);
    });
    int min_y = a[n-1].end;
    for (int i = n - 2; i >= 0; i--){
        if (a[i].end >= min_y) q1[a[i].id] = 1;
        min_y = min(min_y, a[i].end);
    }
    int max_y = a[0].end;
    for (int i = 1; i < n; i++){
        if (a[i].end <= max_y) q2[a[i].id] = 1;
        max_y = max(max_y, a[i].end);
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