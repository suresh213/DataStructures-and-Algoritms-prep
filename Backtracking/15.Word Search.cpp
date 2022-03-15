class Solution
{
public:
    int dirX[4] = {-1, 1, 0, 0};
    int dirY[4] = {0, 0, -1, 1};

    bool findWord(vector<vector<char>> &board, string word, int index, int i, int j, int m, int n)
    {
        if (index == word.length())
            return true;
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index])
            return false;

        char x = board[i][j];
        board[i][j] = '#';
        for (int k = 0; k < 4; k++)
        {
            if (findWord(board, word, index + 1, i + dirX[k], j + dirY[k], m, n))
            {
                return true;
            }
        }
        board[i][j] = x;

        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (findWord(board, word, 0, i, j, m, n))
                        return true;
                }
            }
        }
        return false;
    }
};