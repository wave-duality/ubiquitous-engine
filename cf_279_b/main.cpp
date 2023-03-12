// Problem: https://codeforces.com/contest/279/problem/B

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> books(n);
    for (int i = 0; i < n; ++i) cin >> books[i];

    int result = 0;
    int left = 0, right = 0;
    long long s = 0;
 
    while (right < n) {
        // move right till total is less than t
        while (right < n && s+books[right] <= t) {
            s += books[right];
            ++right;
        }

        result = std::max(result, right-left);

        s -= books[left];
        ++left;
    }
    cout << result << endl;

    return 0;
}