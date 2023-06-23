class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size()) return false;
        //basically count of character should be same in both
        int a[26], b[26];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        
        for(int i =0;i<s.size();i++)
        {
            a[int(s[i])-97]++;
            b[int(t[i])-97]++;
        }
        
        for(int i =0;i<26;i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        
        return true;
    }
};