#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    int N; cin >> N;
    int pass[N+1][N+1]; //keep track of the cows that pass through a particular point
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pass[i][j] = 1;
        }
    }
    //can just do it row by row
    char dir[N][N]; //directions of the signs
    int vats[2][N]; //vat values, first the ones on the right (top to bottom) then the ones on the bottom (left to right)
    for (int i = 0; i < N; i++) {
        //first N rows
        string directions = "";
        cin >> directions;
        for (int j = 0; j < directions.length(); j++) {
            dir[i][j] = directions.at(j);
        }
        cin >> vats[0][i];
    }
    for (int i = 0; i < N; i++) {
        cin >> vats[1][i];
        //last row
    }
    //initialize pass[][]
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            if (j > 0 || k > 0) {
                if (k > 0) {
                    pass[j][k] += pass[j][k-1] * (dir[j][k-1] == 'R');
                } 
                if (j > 0) {
                    pass[j][k] += pass[j-1][k] * (dir[j-1][k] == 'D');
                }
            }
        }
    }
    ll cost = 0;
    //current cost, let's initialize it 
    for (int i = 0; i < N; i++) {
        int mult;
        if (dir[i][N-1] == 'R') {
            mult = 1;
        } else {
            mult = 0;
        }
        cost += vats[0][i] * (pass[i][N-1] * mult);
    }
    for (int j = 0; j < N; j++) {
        int mult;
        if (dir[N-1][j] == 'D') {
            mult = 1;
        } else {
            mult = 0;
        }
        cost += vats[1][j] * (pass[N-1][j] * mult);
    }
    cout << cost << "\n"; //initial answer before queries
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a; int b; cin >> a >> b; //coordinates of flipped sign
        int x = a-1;
        int y = b-1;
        int change = pass[x][y];
        //subtract from everything it used to go to
        while (x < N && y < N) {
            if (dir[x][y] == 'R') {
                y++;
            } else {
                x++;
            }
            pass[x][y] -= change;
        }
        x = a-1;
        y = b-1;
        //change sign
        if (dir[x][y] == 'R') {
            dir[x][y] = 'D';
        } else {
            dir[x][y] = 'R';
        }

        
        //subtract from everything it used to go to
        while (x < N && y < N) {
            if (dir[x][y] == 'R') {
                y++;
            } else {
                x++;
            }
            pass[x][y] += change;
        }
       

        ll cost = 0;
        //current cost, let's initialize it 
        for (int i = 0; i < N; i++) {
            int mult;
            if (dir[i][N-1] == 'R') {
                mult = 1;
            } else {
                mult = 0;
            }
            cost += vats[0][i] * (pass[i][N-1] * mult);
        }
        for (int j = 0; j < N; j++) {
            int mult;
            if (dir[N-1][j] == 'D') {
                mult = 1;
            } else {
                mult = 0;
            }
            cost += vats[1][j] * (pass[N-1][j] * mult);
        }
        cout << cost << "\n"; //initial answer before queries
    }
    
}