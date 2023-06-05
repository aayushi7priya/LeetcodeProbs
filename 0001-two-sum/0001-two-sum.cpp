class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>mp; //to store indices
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.count(target - nums[i]) > 0 && mp[target-nums[i]]!=i) {
                return { mp[target-nums[i]], i };
            }
            else continue;
        }
        return{};
    }
};