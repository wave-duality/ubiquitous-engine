#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
#define ll long long
 
using namespace std;



int main() {
    int m, s; cin >> m >> s;
    //m is the length, s is the sum of digits
    if (s == 0) {
        if (m == 1) {
            cout << 0 << " " << 0 << "\n";
        } else {
        cout << -1 << " " << -1 << "\n";
        }
    } else if (s > 9*m) {
        cout << -1 << " " << -1 << "\n";
    } else {
        //smallest, put 9s starting from the back
        vector<int> small;
        vector<int> large;
        int left = s;
        while (small.size() < m-1) {
            small.push_back(min(9, left-1));
            left -= min(9, left-1);
        }
        small.push_back(left);
        left = s;
        while (large.size() < m) {
            large.push_back(min(9, left));
            left -= min(9, left);
        }
        for (int j = small.size()-1; j >= 0; j--) {
            cout << small.at(j);
        } 
        cout << " ";
        for (int k = 0; k < large.size(); k++) {
            cout << large.at(k);
        } cout << "\n";
    }
}   
