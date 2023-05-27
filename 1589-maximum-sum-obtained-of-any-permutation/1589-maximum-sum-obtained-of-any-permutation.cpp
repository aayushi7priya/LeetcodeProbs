class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        
        int mod = 1e9+7;
        int n = nums.size();
        int q = requests.size();
        int query[n];
        memset(query, 0, sizeof(query));
        for(int i =0;i<q;i++)
        {
            query[requests[i][0]]++;
            if(requests[i][1]+1<n)query[requests[i][1]+1]--;
        }
        
        //prefix sum
        for(int i =1;i<n;i++)
        {
             query[i]+=query[i-1];
            
        }
        
        sort(query, query+n);
        sort(nums.begin(), nums.end());
        
        int ans=0;
        for(int i =0;i<n;i++)
        {
            ans= (ans + ((long long)(query[i]%mod)*(long long)(nums[i]%mod))%mod)%mod;
        }
        return ans;
    }
};
