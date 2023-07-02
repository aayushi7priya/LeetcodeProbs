class Solution {
public:
    //reverse string karne ke liye function chahiye
    
    string reverseStr(string s, int k) { 
        int n = s.size();
        int i =0;
        int j = min(k, n);
        
        while(i<j)
        {
            reverse(s.begin()+i, s.begin()+j);
            i+=2*k;
            j = min(i+k, n);
        }
        return s;
    }
};

