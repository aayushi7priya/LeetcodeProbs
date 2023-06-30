class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //my intuition behind solution is that if numbers are occuring 3 times then 
        //sum of all the ith bit should be either totally divisible by 3
        //or it will leave a remainder 1
        // if it leaves a remainder 1 - then in our answer that bit is 1
        //otherwise 0
        
        vector<int> sum(32); //to store sum of ith bit of every element in array
        for(int i =0;i<32;i++) sum[i] = 0;
        for(int i =0;i<nums.size();i++)
        {
            for(int j =0;j<=31;j++)
            {
                if((nums[i]&(1<<j))!=0)
                    sum[j]++;
            }
        }
        int num =0;
        for(int i =0;i<32;i++)
        {
            if(sum[i]%3==1)
            {
                num+= (1<<i);
            }
        }
        return num;
    }
};