#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 26;
int a[MAX];
string s;

void process() {
    cin >> s;
    for (char &ch : s) a[ch - 'A']++;
    int n = (int) s.size();
    int odd = 0, even = 0;
    for (int i = 0; i < 26; i++){
        if (a[i] == 0) continue;
        if (a[i] % 2 == 0) even++;
        else odd++;
    }
    if (n % 2 == 0 && odd > 0){
        cout << "NO SOLUTION";
        return;
    }
    else if (n % 2 == 1 && odd != 1) {
        cout << "NO SOLUTION";
        return;
    }
    vector<char> ans(n);
    int left = 0;
    int right = n - 1;
    for (int i = 0; i < 26; i++){
        if (a[i] % 2 != 0) {
            ans[n/2] = i + 'A';
            a[i]--;
        }
        while (a[i] > 0){
            ans[left] = i + 'A';
            ans[right] = i + 'A';
            a[i] -= 2;
            left++;
            right--;
        }
    }
    for (char &ch : ans) cout << ch;
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