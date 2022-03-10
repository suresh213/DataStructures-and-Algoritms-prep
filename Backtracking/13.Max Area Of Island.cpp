class Solution
{
public:
    int dirX[4] = {-1, 1, 0, 0};
    int dirY[4] = {0, 0, -1, 1};

    void getNumberOfIslands(vector<vector<int>> &grid, int i,
                            int j, int m, int n, int &area, int &maxArea)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return;

        grid[i][j] = 0;
        ++area;
        for (int k = 0; k < 4; k++)
        {
            getNumberOfIslands(grid, i + dirX[k], j + dirY[k], m, n, area, maxArea);
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int area = 0;
                    getNumberOfIslands(grid, i, j, m, n, area, maxArea);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};