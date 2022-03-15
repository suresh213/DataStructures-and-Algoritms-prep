class Solution
{
public:
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (board[i][col] == 'Q')
                return false;
            if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q')
                return false;
            if (row - i >= 0 && col + i < n && board[row - i][col + i] == 'Q')
                return false;
        }
        return true;
    }

    void getPositions(vector<string> &board, int i,
                      int n, int queens, vector<vector<string>> &result)
    {
        if (queens == n)
        {
            result.push_back(board);
            return;
        }
        for (int k = 0; k < n; k++)
        {
            if (isSafe(board, i, k, n))
            {
                queens++;
                board[i][k] = 'Q';
                getPositions(board, i + 1, n, queens, result);
                board[i][k] = '.';
                queens--;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board;
        string row = "";
        for (int i = 0; i < n; i++)
        {
            row += '.';
        }
        for (int i = 0; i < n; i++)
        {
            board.push_back(row);
        }
        vector<vector<string>> result;
        getPositions(board, 0, n, 0, result);
        return result;
    }
};