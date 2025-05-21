#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Step 1: Enqueue all initially rotten oranges
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    ++fresh;
                }
            }
        }

        // Step 2: Start BFS from all rotten oranges
        int minutes = 0;
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!q.empty() && fresh > 0) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front(); q.pop();
                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;
                    // If in bounds and it's a fresh orange
                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        --fresh;
                        q.push({nx, ny});
                    }
                }
            }
            ++minutes;
        }

        return (fresh == 0) ? minutes : -1;
    }
};
