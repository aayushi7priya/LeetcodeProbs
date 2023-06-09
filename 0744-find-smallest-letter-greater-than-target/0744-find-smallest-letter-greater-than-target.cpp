class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = target;
        int minm = 1e9;
        for ( auto i: letters)
        {
            if(i-ans>0)
            minm = min(minm, (i-ans));
        }
        
        if(minm == 1e9)
            return letters[0];
        else
        return (ans + minm);
    }
};