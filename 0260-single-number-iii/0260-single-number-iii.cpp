class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor1 = nums[0];
        for(int i =1;i<nums.size();i++)
        {
            xor1 = xor1^nums[i];
        }
        
        //now i want to find any set bit..let it be first
        int set_bit = 1;
        for(int i =0;i<32;i++)
        {
            if((xor1& set_bit)!=0)
                break;
            else set_bit = set_bit<<1;
        }
        int firstans= xor1,y;
        
        for(int i =0;i<nums.size();i++)
        {
            if((nums[i]&set_bit)!=0)
            {
               firstans= firstans^nums[i];
            }
        }
        
        return {firstans, firstans^xor1};
    }
};