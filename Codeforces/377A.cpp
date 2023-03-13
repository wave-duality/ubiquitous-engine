#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <utility>
#include <queue>
#include <string>
 
#define ll long long
 
using namespace std;

bool check(int n, int m, pair<int, int> a) {
    if (a.first >= 0 && a.first < n && a.second >= 0 && a.second < m) {
        return true;
    } 
    return false;
}

int main() {
    int n, m, k; cin >> n >> m >> k;
    int s = 0;
    //dfs from a free cell until we cover s-k free cells, remaining k can be walled up
    char grid[n][m];
    pair<int, int> start;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            cin >> grid[a][b];
            if (grid[a][b] == '.') {
                start.first = a;
                start.second = b;
                s++;
            }
        }
    }
    //now we've initialized 
    map<pair<int, int>, bool> visited;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            pair<int, int> t;
            t.first = a;
            t.second = b;
            visited[t] = false;
        }
    }

    queue<pair<int, int> > q;
    q.push(start);
    int curr = 0;
    while (curr != s-k) {
        pair<int, int> t = q.front();
        while (visited[t]) {
            q.pop();
            t = q.front();
        }
        visited[t] = true;
        curr++;
        pair<int, int> a, b, c, d;
        a.first = t.first+1; a.second = t.second;
        b.first = t.first-1; b.second = t.second;
        c.first = t.first; c.second = t.second+1;
        d.first = t.first; d.second = t.second-1;
        if (check(n,m,a) && !visited[a] && grid[a.first][a.second] == '.') {
            q.push(a);
        }
        if (check(n,m,b) && !visited[b] && grid[b.first][b.second] == '.') {
            q.push(b);
        }
        if (check(n,m,c) && !visited[c] && grid[c.first][c.second] == '.') {
            q.push(c);
        }
        if (check(n,m,d) && !visited[d] && grid[d.first][d.second] == '.') {
            q.push(d);
        }
    }

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            pair<int, int> t;
            t.first = a;
            t.second = b;
            if (!visited[t] && grid[t.first][t.second] == '.') {
                grid[t.first][t.second] = 'X';
            }
            cout << grid[a][b];
        }
        cout << "\n";
    }

    


}