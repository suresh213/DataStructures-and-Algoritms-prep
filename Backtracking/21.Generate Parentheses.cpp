class Solution
{
public:
    void generate(int open, int close, int n, string curr, vector<string> &result)
    {
        if (open == n && close == n)
        {
            result.push_back(curr);
            return;
        }

        if (open < n)
        {
            generate(open + 1, close, n, curr + '(', result);
        }
        if (close < open)
        {
            generate(open, close + 1, n, curr + ')', result);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        generate(0, 0, n, "", result);
        return result;
    }
};