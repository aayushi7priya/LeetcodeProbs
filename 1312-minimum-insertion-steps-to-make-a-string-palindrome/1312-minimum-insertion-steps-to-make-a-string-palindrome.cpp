class Solution {
public:
    string s;
    int dp[502][502];
    int rec(int i, int j)
    {
        int n = s.size();
        if(i>=j || i>=n || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = 0;
        if(s[i] == s[j])
            ans = rec(i+1, j-1);
        else
        ans = 1 + min(rec(i+1,j), rec(i,j-1));
            
        return dp[i][j] = ans;
    }
    int minInsertions(string st) {
        s = st;
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        return rec(0, n-1);
    }
};