class Solution
{
public:
    void generateSubsets(int index, vector<int> &nums, vector<int> &currentSubset,
                         vector<vector<int>> &result)
    {
        if (index <= nums.size())
        {
            result.push_back(currentSubset);
        }
        for (int i = index; i < nums.size(); i++)
        {
            currentSubset.push_back(nums[i]);
            generateSubsets(i + 1, nums, currentSubset, result);
            currentSubset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> currentSubset;
        generateSubsets(0, nums, currentSubset, result);
        return result;
    }
};