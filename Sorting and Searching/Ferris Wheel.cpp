#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int numChild,limit,cnt;
int weights[MAX];

void process() {
    cin >> numChild >> limit;
    for (int i = 0; i < numChild; i++) cin >> weights[i];
    sort(weights, weights + numChild);
    int left = 0;
    int right = numChild - 1;
    while (left <= right){
        if (right == left){
            cnt++;
            left++;
        }
        else if (weights[left] + weights[right] <= limit){
            left++;
            right--;
            cnt++;
        }
        else{
            right--;
            cnt++;
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