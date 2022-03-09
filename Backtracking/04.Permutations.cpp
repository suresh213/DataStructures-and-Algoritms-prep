class Solution
{
public:
    void findPermutations(int index, vector<int> &nums, vector<vector<int>> &result)
    {
        if (index == nums.size() - 1)
        {
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            findPermutations(index + 1, nums, result);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        findPermutations(0, nums, result);
        return result;
    }
};