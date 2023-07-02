class Solution {
public:
    
    int gcd(int a, int b)
    {
        if(a!=b)
        {
            if(a>b) return gcd(a-b, b);
            else return gcd(a,b-a); 
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int a = nums[0], b = nums[n-1];
        
        return gcd(a,b);
    }
};