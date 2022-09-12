/*
 * @Author: yh
 * @Date: 2022-09-05 01:26:11
 * @LastEditTime: 2022-09-05 01:49:16
 * @Description:
 * @FilePath: \algorithm\practice\recurse\numberOfIslands.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    grid[i][j] = 0;
    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
        dfs(grid, i - 1, j);
    } else if (j - 1 >= 0 && grid[i][j - 1] == 1) {
        dfs(grid, i, j - 1);
    } else if (j + 1 < n && grid[i][j + 1] == 1) {
        dfs(grid, i, j + 1);
    } else if (i + 1 < m && grid[i + 1][j] == 1) {
        dfs(grid, i + 1, j);
    }
}
int main() {
    vector<vector<int>> grid{{1, 1, 0, 0, 0}, {0, 1, 0, 1, 1}, {0, 0, 0, 1, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 1, 1}};
    if (grid.empty()) {
        return 0;
    }

    int ret = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1) {
                ret++;
                dfs(grid, i, j);
            }
        }
    }
    cout << ret << endl;

    return 0;
}