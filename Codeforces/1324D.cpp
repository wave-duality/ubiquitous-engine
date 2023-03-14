#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
#define ll long long
 
using namespace std;



int main() {
    ll n; cin >> n; //topics   
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

    ll res = 0;

    ll num_pos = std::count_if(diff.begin(), diff.end(), [&](int v){return v > 0;});
    ll num_zeros = std::count(diff.begin(), diff.end(), 0);
    res += num_pos*(num_pos-1)/2;
    res += num_pos*num_zeros;

    int l = 0, r = n-1;
    while (l <= r && diff[l] < 0) {  // till left is no longer negative
        while (l < r && diff[r] > 0 && diff[l]+diff[r] > 0) {
            --r;
        }
        res += n-r-1;

        ++l;
    }
    std::cout << res << std::endl;
}