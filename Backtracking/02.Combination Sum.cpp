class Solution
{
public:
    void findCombinations(int index, vector<int> &candidates, int target,
                          vector<vector<int>> &result, vector<int> combination)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            result.push_back(combination);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates[i] > target)
                continue;
            combination.push_back(candidates[i]);
            findCombinations(i, candidates, target - candidates[i], result, combination);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> combination;
        findCombinations(0, candidates, target, result, combination);
        return result;
    }
};