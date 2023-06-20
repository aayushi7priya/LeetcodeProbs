class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        long long sum[n];
        sum[0] = nums[0];
        for(int i =1;i<n;i++)
        {
            sum[i]= sum[i-1] + nums[i];
        }
        for(int i =0;i<n;i++)
        {
            if(i<k) ans.push_back(-1);
            
            else if(i>=k && i+k<n){
                if(i-k == 0)
                {
                    ans.push_back(sum[i+k]/(2*k + 1));
                }
                else ans.push_back((sum[i+k]-sum[i-k-1])/(2*k + 1) );
                
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
        
    }
};