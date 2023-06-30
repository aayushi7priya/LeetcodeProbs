class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int n = nums.size();
        //XOR of even 1's = 0 & XOR of odd 1's = 1
        // Simplifying nums[i] AND (nums[i] XOR x) means
       // we can convert any 1 bit  to 0
       // we cannot convert any 0 bit to 1
        //so if we do xor of all numbers and all of it is zero- it will be 0 only
        //but if there occurs any 1, it will contribute in final answer as 1
        int ans= nums[0];
        for(int i =1;i<n;i++)
        {
            ans = ans|nums[i];
        }
        return ans;
    }
};