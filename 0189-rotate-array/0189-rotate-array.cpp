class Solution {
public:
    
    // don't use this code to understand logic
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rotated(n);
        
        for (int i = 0; i < n; i++) {
            rotated[(i + k) % n] = nums[i];
        }
        
        nums = rotated;
    }
};
