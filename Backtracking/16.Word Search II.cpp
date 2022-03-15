// TLE

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