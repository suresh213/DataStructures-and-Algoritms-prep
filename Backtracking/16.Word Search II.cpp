// TLE

class Solution
{
public:
    int dirX[4] = {-1, 1, 0, 0};
    int dirY[4] = {0, 0, -1, 1};

    bool findWord(vector<vector<char>> &board, string word, int index,
                  int i, int j, int m, int n)
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
                board[i][j] = x;
                return true;
            }
        }
        board[i][j] = x;

        return false;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int m = board.size();
        int n = board[0].size();
        vector<string> result;

        for (int k = 0; k < words.size(); k++)
        {
            int found = 0;
            string word = words[k];
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] == word[0] && findWord(board, word, 0, i, j, m, n))
                    {
                        result.push_back(word);
                        found = 1;
                        break;
                    }
                }
                if (found)
                    break;
            }
        }
        return result;
    }
};

// TLE
// Better Approach using map

class Solution
{
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    bool find(vector<vector<char>> &board, int i, int j, int index, string word, int m, int n)
    {
        if (index == word.length())
        {
            return true;
        }

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index])
        {
            return false;
        }

        char x = board[i][j];
        board[i][j] = '#';
        for (int k = 0; k < 4; k++)
        {
            if (find(board, i + row[k], j + col[k], index + 1, word, m, n))
            {
                board[i][j] = x;
                return true;
            }
        }
        board[i][j] = x;

        return false;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int n = board[0].size();
        int m = board.size();

        vector<string> result;
        map<char, vector<pair<int, int>>> letters;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                letters[board[i][j]].push_back({i, j});
            }
        }

        for (int k = 0; k < words.size(); k++)
        {
            char x = words[k][0];
            if (letters.find(x) != letters.end())
            {
                for (pair<int, int> i : letters[x])
                {
                    if (find(board, i.first, i.second, 0, words[k], m, n))
                    {
                        result.push_back(words[k]);
                        break;
                    }
                }
            }
        }
        return result;
    }
};

// Best approach - Trie