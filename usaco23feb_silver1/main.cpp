#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

static bool valid(ll eq[][3], int k, int N, int a, int b) {
    //given some equations (int form X(B) + Y(k) less than or equal to Z) with proposed value of k, check if there is a compatible B-solution (1 to k-1)
    vector<ll> up;
    //keeps track in the form b <= a
    vector<ll> down;
    //down keeps track of b >= a
    for (int i = 0; i < N; i++) {
        int var = 0;
        ll a, b, c;
        a = eq[i][0];
        b = eq[i][1];
        c = eq[i][2];
        if (a == 0) {
            if (c-b*k < 0) {
                return false;
            } 
        } else if (a > 0) {
            if (c-b*k >= a) {
                ll thing = (c-b*k)/a;
                up.push_back(thing);
            } else {
                return false;
            }
        } else {
            //a < 0
            if (c-b*k < a) {
                ll thing;
                if ((b*k-c) % (-1*a) == 0) {
                    thing = (b*k-c)/(-1*a);
                } else {
                    thing = (b*k-c)/(-1*a)+1;
                }
                down.push_back(thing);
            }
        }
    }

    //can't increase b
    up.push_back(b);
    down.push_back(k-a);
    if (up.size() == 0 && down.size() == 0) {
        return true;
    }
    ll upbig = 9e18;
    ll downbig = -9e18;
    if (up.size() > 0) {
        upbig = up.at(0);
        for (int i = 0; i < up.size(); i++) {
            if (up.at(i) < upbig) {
                upbig = up.at(i);
            }
            //cout << "up " << up.at(i) << "\n";
        }
    }
    if (down.size() > 0) {
        downbig = down.at(0);
        for (int j = 0; j < down.size(); j++) {
            if (down.at(j) > downbig) {
                downbig = down.at(j);
            }
            //cout << "down " << down.at(j) << "\n";
        }
    }
    if (upbig < downbig) {
        return false;
    }
    if (downbig >= k) {
        return false;
    }
    if (upbig <= 0) {
        return false;
    }
    //now actually solve for a, we need to ensure a and b don't end up increasing
    
    //if b <= 3, b <= 5, then b <= 3 is enough
    return true;
}

int main() {
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        //each test case
        int N; ll c; ll m; cin >> N >> c >> m;
        ll eq[N][3];
        for (int j = 0; j < N; j++) {
            ll d, e, f;
            cin >> d >> e >> f;
            eq[j][0] = e-d;
            eq[j][1] = d;
            eq[j][2] = f;
            //B, k, number
        }

        ll lo = 2;
        ll hi = c + m;


        //binary search the maximum possible value of k = a+b
        while (lo != hi) {
            ll mid;
            // if ((lo+hi) % 2 == 1) {
            //     mid = (lo+hi+1)/2;
            // } else {
            //     mid = (lo+hi)/2;
            // }
            mid = ceil((lo+hi)/2.0);
            //cout << lo << " " << mid << " " << hi << "\n";
            if (valid(eq, mid, N, c, m)) {
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        cout << (c + m - lo) << "\n";


    }
    //replace all equations with an A = k-b substitution


}
