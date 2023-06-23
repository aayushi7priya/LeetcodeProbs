class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        map<char, int>mp;
        mp['('] = 1;
        mp['{'] = 2;
        mp['['] = 3;
        mp[')'] = 4;
        mp['}'] = 5;
        mp[']'] = 6;
        
        if(s.size()%2!=0) return false;
        for(int i =0;i< s.size();i++)
        {
            if(mp[s[i]]<=3)
                st.push(s[i]);
            else
            {
                if(!st.empty() && mp[st.top()] + 3 == mp[s[i]])
                    st.pop();
                else return false;
            }
        }
        
        if(st.empty()) return true;
        else return false;
        
    }
};