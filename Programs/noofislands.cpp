#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int islands(int grid[4][5],int i,int j) {
    if (i < 0 || j < 0 || i>3 || j>4 || grid[i][j]==0) {
        return 0;
    }
    grid[i][j] = 0;
    islands(grid, i + 1, j);
    islands(grid, i - 1, j);
    islands(grid, i, j + 1);
    islands(grid, i, j - 1);
    return 1;
}

int main() {

    int grid[4][5] = {1,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,1,1 };
    int total = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            total += islands(grid, i, j);

        }
    }

    cout << total << endl;

    return 0;
}
