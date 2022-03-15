class Solution
{
public:
    int dirX[4] = {-1, 1, 0, 0};
    int dirY[4] = {0, 0, -1, 1};

    void dfs(vector<vector<char>> &board, int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
            return;

        board[i][j] = '#';
        for (int k = 0; k < 4; k++)
        {
            dfs(board, i + dirX[k], j + dirY[k], m, n);
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
            {
                dfs(board, 0, i, m, n);
            }
            if (board[m - 1][i] == 'O')
            {
                dfs(board, m - 1, i, m, n);
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, i, 0, m, n);
            }
            if (board[i][n - 1] == 'O')
            {
                dfs(board, i, n - 1, m, n);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};