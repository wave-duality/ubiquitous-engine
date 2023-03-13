#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
#define ll long long
 
using namespace std;
void solve() {
    //111 mod 11 = 1
    //1111 mod 11 = 0
    //11111 mod 11 = 1, mod 111 = 
    //111111 mod 11 = 0
    int x; cin >> x;
    int a = x%11;
    int b = x-a*111;
    if (b >= 0 && b%11 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}