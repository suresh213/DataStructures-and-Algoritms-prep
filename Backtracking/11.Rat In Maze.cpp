class Solution
{
public:
    void getPaths(vector<vector<int>> &grid, int i, int j, int n,
                  string path, vector<string> &result)
    {
        if (i < 0 || j < 0 || i >= n || j >= n || !grid[i][j])
            return;
        if (i == n - 1 && j == n - 1)
        {
            result.push_back(path);
            return;
        }
        grid[i][j] = 0;
        getPaths(grid, i - 1, j, n, path + 'U', result);
        getPaths(grid, i, j + 1, n, path + 'R', result);
        getPaths(grid, i + 1, j, n, path + 'D', result);
        getPaths(grid, i, j - 1, n, path + 'L', result);
        grid[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &grid, int n)
    {
        if (!grid[0][0])
            return {};
        vector<string> result;
        getPaths(grid, 0, 0, n, "", result);
        return result;
    }
};