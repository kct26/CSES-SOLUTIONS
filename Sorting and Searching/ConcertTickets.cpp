#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;

const int MOD = 1000000007;
const int MAX = 200005;
int numTickets, numCustomers;
int prices[MAX], canBuy[MAX];
multiset<int> available;

void process() {
    cin >> numTickets >> numCustomers;
    for (int i = 0; i < numTickets; i++) cin >> prices[i];
    for (int i = 0; i < numCustomers; i++) cin >> canBuy[i];
    available.insert(prices, prices + numTickets);
    for (int i = 0; i < numCustomers; i++){
        auto it = available.upper_bound(canBuy[i]);
        if (it == available.begin()) cout << -1 << "\n";
        else{
            it--;
            if (*it <= canBuy[i]){
                cout << *it << "\n";
                available.erase(it);
            }
            else cout << -1 << "\n";
        }
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