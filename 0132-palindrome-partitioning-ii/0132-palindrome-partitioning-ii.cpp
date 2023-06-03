class Solution {
public:
    string s;
    vector<vector<string>> partitions;
    int dp[2002];
    
    bool isPalindrome(int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    
    int rec(int start) {
        if (start == s.length())
            return -1;           
        
        int minCuts = INT_MAX;
        
        if(dp[start]!=-1)
            return dp[start];
        
        // all possible partitions starting from 'start'
        for (int i = start; i < s.length(); i++) { //here i is end of that substring
            if (isPalindrome(start, i)) {
                int cuts = rec(i + 1);          
                minCuts = min(minCuts, cuts + 1); 
            }
        }
        return dp[start] = minCuts;
    }
    
    int minCut(string st) {
        memset(dp,-1,sizeof(dp));
        s = st;
        return rec(0);
    }
};
