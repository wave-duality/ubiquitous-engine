#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
#define ll long long
 
using namespace std;

int main() {
    int n; cin >> n;
    int res = 0;
    //0 = forced rest, 1 = only contest, 2 = only gym, 3 = either
    //3 at the end = just add one
    int days[100];
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }
    int dp[101][3];
    for (int i = 0; i < 101; i++) {
        //initialize
        dp[i][0] = 1e9;
        dp[i][1] = 1e9;
        dp[i][2] = 1e9;
    }
    dp[0][0] = 1;
    if (days[0] == 1 || days[0] == 3) {
        dp[0][1] = 0;
    }
    if (days[0] == 2 || days[0] == 3) {
        dp[0][2] = 0;
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = 1+min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
        //resting is always allowed

        //can we do a contest?
        if (days[i] == 1 || days[i] == 3) {
            //gym or rest previously
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        }

        if (days[i] == 2 || days[i] == 3) {
            //contest or rest previously
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        }
    }
    cout << min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << "\n";
    

   
}