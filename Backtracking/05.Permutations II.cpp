// Approach 1: Using Set
class Solution {
public:
    void findPermutations(int index, vector<int>& nums, set<vector<int>> &res){
        if(index==nums.size()-1){
            res.insert(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            findPermutations(index+1,nums,res);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        findPermutations(0,nums,res);
        vector<vector<int>> finalResult;
        for(vector<int> i:res) finalResult.push_back(i);
        return finalResult;
    }
};

// Approach 2: Using Map
class Solution {
public:
    void findPermutations(int index, vector<int>& nums, vector<int> currentPermutation,
                          vector<vector<int>> &result,unordered_map<int,int> &mp){
        if(index==nums.size()){
            result.push_back(currentPermutation);
            return;
        }
        for(auto i:mp){
            if(i.second<=0) continue;
            mp[i.first]--;
            currentPermutation.push_back(i.first);
            findPermutations(index+1,nums,currentPermutation,result,mp);
            currentPermutation.pop_back();
            mp[i.first]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        vector<vector<int>> result;
        vector<int> currentPermutation;
        findPermutations(0,nums,currentPermutation,result,mp);
        return result;
    }
};

// Approach 3:
class Solution {
public:
    bool canPermute(int index,int curr,vector<int> &nums){
        for(int i=index;i<curr;i++){
            if(nums[i]==nums[curr])
                return false;
        }
        return true;
    }
    void findPermutations(int index, vector<int>& nums, vector<int> currentPermutation,
                          vector<vector<int>> &result){
        if(index==nums.size()-1){
            result.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(i!=index && !canPermute(index,i,nums)) continue; 
            swap(nums[i],nums[index]);
            findPermutations(index+1,nums,currentPermutation,result);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentPermutation;
        findPermutations(0,nums,currentPermutation,result);
        return result;
    }
};