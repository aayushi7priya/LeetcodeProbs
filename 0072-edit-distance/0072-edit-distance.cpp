class Solution {
public:
 int dp[505][505];
 string t1,t2;
int rec(int i,int j)
{
    int ans =1e9;
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    //reached end of t1 meaning we need to delete rest from t2
    if(i==t1.length())
        return t2.length()-j; 
    
    //reached end of t2 meaning we need to delete rest from t1
    if(j==t2.length())
        return t1.length()-i; 
    
    if(t1[i] == t2[j])
        ans = rec(i+1,j+1);
    else
    {
        //rec(i+1,j) - delete the current character in t1 and move to the next position 
        //rec(i,j+1) -  insert the current character of t2 at the current position in t1 and move to the next position
        //rec(i+1,j+1) -  replace the current character in t1 with the current character in t2 and move to the next position
        ans = 1+min({rec(i+1,j), rec(i,j+1), rec(i+1, j+1)});
    }
    
    return dp[i][j]=ans;
}
    
    int minDistance(string word1, string word2) {
        t1 = word1, t2 = word2;
        memset(dp, -1, sizeof(dp));
        return(rec(0,0));
        
    }
};