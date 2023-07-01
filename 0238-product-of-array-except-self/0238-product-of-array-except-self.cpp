class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1,cnt=0;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                product*=nums[i];
            }
            else if(nums[i]==0)
            {
                cnt++;
            }
        }
        
        vector<int>ans(nums.size());
        if(cnt==0)
        {
            for(int i =0;i<nums.size();i++)
            {
                ans[i]= product/nums[i];
            }
        }
        else if(cnt==1)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]!=0)
                {
                    ans[i]=0;
                }
                else ans[i] = product;
            }
        }
        else 
        {
            for(int i =0;i<nums.size();i++)
                ans[i] = 0;
        }
        return ans;
    }
};