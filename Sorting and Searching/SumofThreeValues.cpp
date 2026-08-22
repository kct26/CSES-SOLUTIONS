#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 5005;
int n;
pair<ll, int> a[MAX];
ll target;

void process() {
    cin >> n >> target;
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++){
        ll complement = target - a[i].first;
        int left = i + 1;
        int right = n - 1;
        while (left < right){
            if (a[left].first + a[right].first < complement) left++;
            else if (a[left].first + a[right].first > complement) right--;
            else{
                cout << a[left].second + 1 << " " << a[i].second + 1 << " " << a[right].second + 1 << "\n";
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
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