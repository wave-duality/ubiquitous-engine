#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
#define ll long long
 
using namespace std;


ll mod = 1e9 + 7;

int main() {
    int n, k, d; cin >> n >> k >> d;
    ll dp[n+1][2];
    //so we can index from 1
    //second element = 0 --> no >= d yet, = 1 --> yes >= d yet 
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        dp[i][1] = 0;
        for (int j = i-1; j >= max(0, i-d+1); j--) {
            dp[i][0] += dp[j][0];
            dp[i][0] = dp[i][0] % mod;
        }
        for (int j = i-1; j >= max(0, i-k); j--) {
            dp[i][1] += dp[j][1];
            dp[i][1] = dp[i][1] % mod;
        }
        for (int j = i-d; j >= max(0, i-k); j--) {
            dp[i][1] += dp[j][0];
            dp[i][1] = dp[i][1] % mod;
        }
    }
    cout << dp[n][1] % mod << "\n";
    
}