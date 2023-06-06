class Solution {
public:
    int a;
    vector<int> arr;
    vector<int> dp;
    
    bool canJump(vector<int>& nums) {
        arr = nums;
        a = nums.size();
        dp.resize(a, -1);
        return rec(0);
    }
    
    bool rec(int level) {
        if (level >= a)
            return false;
        if (level >= a - 1)
            return true;
        if (dp[level] != -1)
            return dp[level];
        
        int n = arr[level];
        bool ans = false;
        for (int i = 1; i <= n; i++) {
            ans = ans || rec(level + i);
        }
        dp[level] = ans;
        return ans;
    }
};
