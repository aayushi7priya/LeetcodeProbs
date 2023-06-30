class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4) return 0;
        sort(nums.begin(), nums.end());
        // 0 3 6 9 9 11 13
        
        int pos1 = nums[n-4] - nums[0]; //you change last 3
        int pos2 = nums[n-1] - nums[3]; //you change first 3
        int pos3 = nums[n-3] - nums[1]; //you change first 1 and last 2
        int pos4 = nums[n-2] - nums[2]; //you change first 2 and last 1
        
        return min({pos1,pos2,pos3,pos4});
    }
};

