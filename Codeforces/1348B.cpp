#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <array>
 
#define ll long long
 
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    
    int num;
    vector<int> b;
    //different amount of integers so far
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (count(b.begin(), b.end(), num) == 0) {
            b.push_back(num);
        }
    }
    if (b.size() > k) {
        cout << "-1" << "\n";
    } else {
        //just take the distinct elements of a and repeat them n times
        //add filler to the end first to make it k
        cout << k*n << "\n";
        while (b.size() != k) {
            b.push_back(1);
        }
        for (int i = 0; i < n; i++) {
            for (const auto x : b) {
                cout << x << " ";
            }
        }
        cout << endl;
    }
    //can we make the array beautiful?
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}