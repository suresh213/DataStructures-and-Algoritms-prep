class Solution
{
public:
    void combinations(int start, int n, int k, vector<int> &currentCombination,
                      vector<vector<int>> &result)
    {
        if (k == 0)
        {
            result.push_back(currentCombination);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            currentCombination.push_back(i);
            combinations(i + 1, n, k - 1, currentCombination, result);
            currentCombination.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> currentCombination;
        combinations(1, n, k, currentCombination, result);
        return result;
    }
};