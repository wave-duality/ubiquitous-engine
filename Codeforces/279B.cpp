#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
#define ll long long
 
using namespace std;



int main() {
    int n, t; cin >> n >> t;
    vector<int> times;
    //see how far 0 can go with prefix/suffix
    int l = 0;
    int r = -1;
    //see largest l given current r;
    vector<int> prefix;
    int curr = 0;
    prefix.push_back(curr);
    for (int i = 0; i < n; i++) {
        int k; cin >> k; times.push_back(k);
        curr += k;
        prefix.push_back(curr);
        if (prefix.at(i+1) <= t) {
            r = i;
        }
    }
    curr = prefix.at(r+1); 
    //l and r are now initialized
    int res = r-l+1;
    while (r < n-1) {
        int extra = times.at(l);
        l++;
        //how much can we increase r, now that l is gone?
        curr -= extra;
        while (r < n-1 && curr+times.at(r+1) <= t) {
            r++;
            curr += times.at(r);
        }
        res = max(res, r-l+1);
    }
    cout << res << "\n";
}