class Solution {
public:
    int n;
    void rec(int i, vector<char>& s)
    {
        if(2*i<=n-1)
        {
            swap(s[i], s[n-1-i]);
            rec(i+1, s);
        }
        else return;
        
    }
    
    void reverseString(vector<char>& s) {
        n = s.size();
        rec(0, s);
    }
};