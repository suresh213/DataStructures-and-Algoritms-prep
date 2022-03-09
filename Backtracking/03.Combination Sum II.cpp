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
                break;
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            combination.push_back(candidates[i]);
            findCombinations(i + 1, candidates, target - candidates[i], result, combination);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        findCombinations(0, candidates, target, result, combination);
        return result;
    }
};