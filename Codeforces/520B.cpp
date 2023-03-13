#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
#define ll long long
 
using namespace std;



int main() {
    //get from n to m with x2 and -1
    int n, m; cin >> n >> m;
    int res = 0;
    while (m > n) {
        if (m%2 == 1) {
            m++;
            res++;
        } else {
            m = m/2;
            res++;
        }
    }
    cout << res + (n-m) << "\n";
}