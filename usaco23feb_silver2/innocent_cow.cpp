#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

bool unreachable(ll a, ll b, ll t, const vector<ll>& g) {
    double dist = sqrt(pow(a - g[0], 2) + pow(b - g[1], 2));
    double time = abs(t - g[2]);
    return dist - time > std::numeric_limits<double>::epsilon();
}

static bool comp(const vector<ll>& vec1, const vector<ll>& vec2) {
    return vec1[2] < vec2[2];
}
int main() {
    ll res = 0;
    ll G, N;
    //only need to check the one before and after
    //just sort the grazing first
    //take into account case where the time is exact
    cin >> G >> N;
    vector<vector<ll> > graze;
    for (int i = 0; i < G; i++) {
        vector<ll> v;
        ll x; ll y; ll t; cin >> x >> y >> t;
        v.push_back(x);
        v.push_back(y);
        v.push_back(t);
        graze.push_back(v);
    }
    sort(graze.begin(), graze.end(), comp);


    //grazes are ordered now

    for (int j = 0; j < N; j++) {
        ll a; ll b; ll c; cin >> a >> b >> c;
        //binary search on where the cow would go
        ll lo = 0;
        ll hi = G-1;
        ll mid;
        while (lo != hi) {
            mid = (lo+hi)/2;
            if (c <= graze.at(mid).at(2)) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }

        if (c == graze.at(lo).at(2)) {
            if (a != graze.at(lo).at(0) || b != graze.at(lo).at(1)) {
                res++;
            }
        } else if (lo == 0) {
            if (unreachable(a, b, c, graze[lo])) ++res;
        } else if (lo == G-1 && c > graze.at(lo).at(2)) {
            if (unreachable(a, b, c, graze[lo])) ++res;
        } else {
            if (unreachable(a, b, c, graze[lo]) || unreachable(a, b, c, graze[lo-1])) ++res;
        }
        
    }
    cout << res << "\n";

/*
} else if (lo == G-1){
            if (dist(a, b, graze.at(lo).at(0), graze.at(lo).at(1)) > (c - graze.at(lo).at(2))) {
                res++;
            }
*/

}   