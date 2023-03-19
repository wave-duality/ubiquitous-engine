#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
#define ll long long
 
using namespace std;



int main() {
    string recipe; cin >> recipe;
    ll p = 0; ll q = 0; ll r = 0;
    ll a, b, c; cin >> a >> b >> c; //curr stock
    ll x, y, z; cin >> x >> y >> z; //prices
    ll money; cin >> money;
    for (const auto t : recipe) {
        if (t == 'B') {
            p++;
        } else if (t == 'S') {
            q++;
        } else {
            r++;
        }
    }

    ll lo = 0;
    ll hi = 1e13;
    while (lo < hi) {
        ll mid = (lo+hi+1)/2; 
        ll zero = 0;
        if (max((mid*p-a)*x, zero) + max((mid*q-b)*y, zero) + max((mid*r-c)*z, zero) <= money) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    cout << lo << "\n";
}