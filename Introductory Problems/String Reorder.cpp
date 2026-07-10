#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;

// 4 A -> A_A_A_A -> if max_freq*2 - 1 == n, max_freq char is forced 
// _A_A_A_A -> else any character is fine

string s,ans;
int freq[26], max_freq, len;
char cur;

char nextValid(){
    int cur_len = (int)ans.size();
    int n = len - cur_len;
    max_freq = 0;
    char earliest,max_cur;
    for (int i = 0; i < 26; i++){
        if (freq[i] != 0){
            if (i + 'A' == ans[cur_len - 1]) continue;
            earliest = i + 'A';
            break;
        }
    }
    for (int i = 0; i < 26; i++){
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            max_cur = i + 'A';
        }
    }
    if (max_freq*2 - 1 == n) {
        freq[max_cur - 'A']--;
        return max_cur;
    }
    else {
        freq[earliest - 'A']--;
        return earliest;
    }
}

void process() {
    cin >> s;
    for (char &ch : s) freq[ch - 'A']++;
    for (char &ch : s) {
        if (freq[ch - 'A'] > max_freq) {
            max_freq = freq[ch-'A'];
        }
    }
    len = (int) s.size();
    if (max_freq*2 - 1 > len){
        cout << -1;
        return;
    }
    ans = "";
    for (int i = 0; i < len; i++){
        char nextChar = nextValid();
        ans += nextChar;
    }
    cout << ans;
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