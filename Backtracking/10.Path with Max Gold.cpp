class Solution
{
public:
    int dirX[4] = {-1, 1, 0, 0};
    int dirY[4] = {0, 0, -1, 1};

    void getMaxGold(vector<vector<int>> &grid, int i, int j, int m, int n,
                    int gold, int &maxGold)
    {
        maxGold = max(gold, maxGold);
        if (i < 0 || j < 0 || i >= m || j >= n || !grid[i][j])
            return;

        int val = grid[i][j];
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++)
        {
            getMaxGold(grid, i + dirX[k], j + dirY[k], m, n, gold + val, maxGold);
        }
        grid[i][j] = val;
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int maxGold = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] > 0)
                {
                    getMaxGold(grid, i, j, m, n, 0, maxGold);
                }
            }
        }
        return maxGold;
    }
};