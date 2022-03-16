int dirX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dirY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafe(vector<vector<int>> &board, int i, int j, int n, int m)
{
    return (i >= 0 && j >= 0 && i < n && j < m && board[i][j] == 0);
}

bool helper(vector<vector<int>> &board, int i, int j, int n, int m, int move)
{
    if (move == m * n)
        return true;

    for (int k = 0; k < 8; k++)
    {
        int x = i + dirX[k];
        int y = j + dirY[k];
        if (isSafe(board, x, y, n, m))
        {
            board[x][y] = move;
            if (helper(board, x, y, m, n, move + 1))
            {
                return true;
            }
            board[x][y] = 0;
        }
    }
    return false;
}

void knightTour(int n, int m)
{
    vector<vector<int>> board(n, vector<int>(m, 0));
    helper(board, 0, 0, n, m, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    knightTour(8, 8);
    return 0;
}