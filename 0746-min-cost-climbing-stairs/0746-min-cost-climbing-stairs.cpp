class Solution {
public:
    int dp[1002];
    
    Solution() {
        memset(dp, -1, sizeof(dp)); // Initialize dp array to -1
    }
    
    int rec(int i, vector<int>&cost)
    {
        int n = cost.size();
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        else 
            dp[i] = cost[i] + min(rec(i+1,cost), rec(i+2, cost));
        //ans = cost[i]+ min( rec(i+1, cost), rec(i+2, cost));
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        return min(rec(0, cost), rec(1,cost));
    }
};