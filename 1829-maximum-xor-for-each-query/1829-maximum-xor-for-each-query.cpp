class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int>ans;
        int mask = (1<<maximumBit)-1;   //isse kam hona chahiye
        for(int i =0;i<n;i++)
        {
            ans.push_back(mask^nums[i]);   //x^nums[i]=11111
            mask = mask^nums[i];           //x = 1111^nums[i]
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};