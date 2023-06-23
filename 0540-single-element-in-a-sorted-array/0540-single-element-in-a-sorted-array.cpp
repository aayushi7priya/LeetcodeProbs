class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i =1;i<n-1;i++)
        {
            if(nums[i]==nums[i-1] || nums[i]==nums[i+1])
                continue;
            else return nums[i];
        }
        //if nothing has returned yet, means it's either first or last
        if(nums[0]!=nums[1]) return nums[0];
        else if(nums[n-1]!=nums[n-2]) return nums[n-1];
        else return -1;
    } 
};