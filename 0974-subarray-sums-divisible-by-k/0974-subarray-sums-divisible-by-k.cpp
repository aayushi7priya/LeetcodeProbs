class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum[n+1];
        sum[0] = 0;
        for(int i =1;i<=n;i++)
        {
            sum[i] = sum[i-1] + nums[i-1];
        }
        //can't iterate in pairs - will take O(n2) time
        //think of another approach
        //(prefix[j]-prefix[i])%k == 0
        //prefix[i]%k ==  pefix[j]%k
        
        vector<int> mod(k);
        for(int i =0;i<=n;i++)
        {
            mod[(sum[i]%k+k)%k]++;
        }
        //basically add 
        int result = 0;
        for(int i=0;i<k;i++)
        {
            result += (mod[i] * (mod[i] - 1)) / 2;
        }
        
        return result;
    }
};