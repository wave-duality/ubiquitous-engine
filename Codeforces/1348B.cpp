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
    int a[n];
    vector<int> b;
    int diff = 0;
    //different amount of integers so far
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (count(b.begin(), b.end(), a[i]) == 0) {
            diff++;
            b.push_back(a[i]);
        }
    }
    if (diff > k) {
        cout << "-1" << "\n";
    } else {
        //just take the distinct elements of a and repeat them n times
        //add filler to the end first to make it k
        cout << k*n << "\n";
        while (b.size() != k) {
            b.push_back(1);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.size(); j++) {
                cout << b.at(j) << " ";
            }
        }
    }
    //can we make the array beautiful?
    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}