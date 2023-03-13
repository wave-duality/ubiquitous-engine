#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
#define ll long long
 
using namespace std;



int main() {
    ll n; cin >> n; //topics
    ll res = 0;
    vector<int> teacher;
    vector<int> student;
    for (ll i = 0; i < n; i++) {
        int k; cin >> k;
        teacher.push_back(k);
    }
    for (ll j = 0; j < n; j++) {
        int k; cin >> k;
        student.push_back(k);
    }
    vector<int> diff;
    for (ll p = 0; p < n; p++) {
        diff.push_back(teacher.at(p) - student.at(p));
    }
    sort(diff.begin(), diff.end());
    int l = 0;
    int r = n-1;
    ll a = 1e9;
    ll b = 1e9;
    //a is the smallest index such that diff[>=a] >= 0
    //b is the smallest index such that diff[>=b] >= 1
    for (ll i = 0; i < n; i++) {
        if (diff.at(i) >= 0) {
            a = min(a, i);
        } 
        if (diff.at(i) >= 1) {
            b = min(b, i);
        }
    }

    //separate out the negative terms to prevent l and r crossing
    if (b == 1e9) {
        cout << 0 << "\n";
    } else {
        ll k = (n-b)*(n-b-1)/2;
        ll m = (b-a)*(n-b);
        res += k; //pairs within all-positive
        res += m; //pairs of (0, positive)
        while (l < a) {
            while (r >= 1 && diff.at(l) + diff.at(r) >= 1) {
                r--;
            }
            res += (n-r-1);
            if (diff.at(l) + diff.at(r) >= 1) {
                res++;
            }
            l++;
        }
        cout << res << "\n";
    }
}