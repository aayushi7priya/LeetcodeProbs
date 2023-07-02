class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0)return false;
        
        //if n&(n-1) is zero it's power of 2
        //another check to ensure that it is power of 4
        
        return (n>0 && ((n&(n-1))==0) && (n%3==1));
    }
};