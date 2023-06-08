class Solution {
public:
    int dp[2502][2502];
     int n;
    vector<int>num;
    int rec(int i, int j){
        if(i==n) return 0;
        
        if(dp[i][j+1]!=-1) return dp[i][j+1];
        
        int ans = 0;
        
        ans+=rec(i+1,j);
        if(j==-1 || num[j]<num[i]){
            ans =max(ans, 1+ rec(i+1,i));
        }
        return dp[i][j+1]=ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        num = nums;
        memset(dp, -1, sizeof(dp));
        n=nums.size();
        return rec(0,-1);
    }
};