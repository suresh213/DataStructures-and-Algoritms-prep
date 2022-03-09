// Approach 1: Using Set
class Solution
{
public:
    void generateSubsets(int index, vector<int> &nums, vector<int> &currentSubset,
                         set<vector<int>> &result)
    {
        if (index <= nums.size())
        {
            result.insert(currentSubset);
        }
        for (int i = index; i < nums.size(); i++)
        {
            currentSubset.push_back(nums[i]);
            generateSubsets(i + 1, nums, currentSubset, result);
            currentSubset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> result;
        vector<int> currentSubset;
        generateSubsets(0, nums, currentSubset, result);

        vector<vector<int>> finalResult;
        for (vector<int> i : result)
            finalResult.push_back(i);
        return finalResult;
    }
};

// APproach 2 : Using Sorting
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
            if (i > index && nums[i] == nums[i - 1])
                continue;
            currentSubset.push_back(nums[i]);
            generateSubsets(i + 1, nums, currentSubset, result);
            currentSubset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> currentSubset;
        generateSubsets(0, nums, currentSubset, result);
        return result;
    }
};