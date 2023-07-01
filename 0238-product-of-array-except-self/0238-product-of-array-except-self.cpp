class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //imp: don't use division
        int n = nums.size();
        vector<int>pref(n,1);
        vector<int>suff(n,1);
        pref[0] = nums[0];
        suff[n-1] = nums[n-1];
        for(int i =1;i<nums.size();i++)
        {
            pref[i] = pref[i-1]*nums[i];  
        }
        for(int i =n-2;i>=0;i--)
        {
            suff[i] = suff[i+1]*nums[i];
        }
        
        vector<int>ans(n);
        ans[0] = suff[1];
        ans[n-1] = pref[n-2];
        for(int i =1;i<n-1;i++)
        {
            ans[i] = suff[i+1]*pref[i-1];
        }
        return ans;
    }
};