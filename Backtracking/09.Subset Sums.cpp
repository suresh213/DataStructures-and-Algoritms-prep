class Solution
{
public:
    void generateSubsets(int index, vector<int> &nums, vector<int> &result, int sum)
    {
        if (index <= nums.size())
        {
            result.push_back(sum);
        }
        for (int i = index; i < nums.size(); i++)
        {
            generateSubsets(i + 1, nums, result, sum + nums[i]);
        }
    }
    vector<int> subsetSums(vector<int> nums, int N)
    {
        vector<int> result;
        generateSubsets(0, nums, result, 0);
        return result;
    }
};