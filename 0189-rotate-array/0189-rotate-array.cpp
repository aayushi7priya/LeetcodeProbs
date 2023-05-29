class Solution {
public:
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (n <= 1 || k % n == 0) {
            return;  // No rotation needed
        }
        
        k = k % n; //if k is multiple we will get the same array. it's the remainder we need to 
        //be concerned if it's some edge case like array = [1,2] and k = 3
        
        reverse(nums.begin(), nums.end());
        
        reverse(nums.begin(), nums.begin()+k);
        
        reverse(nums.begin()+k, nums.end());
    
    }
};
