class Solution {
public:
    //[7,1,1,25]
    
    int dp[101];
    int rec(vector<int> &nums, int i)
    {
        int n = nums.size();
        if(i>=n) return 0;
        if(i==n-1) return nums[i];
        if(dp[i]!=-1) return dp[i];
        return dp[i] = nums[i] + max(rec(nums, i+2), rec(nums,i+3));
    }
    int rob(vector<int>& nums) {
        int ans=-1;
        memset(dp,-1,sizeof(dp));
        //we can't do max(rec(nums, 0), rec(nums,1),rec(nums,2)) because 
        //you don't know the length of nums
        //so better consider every index as starting point
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,rec(nums,i));
        }
        return ans;
    }
};