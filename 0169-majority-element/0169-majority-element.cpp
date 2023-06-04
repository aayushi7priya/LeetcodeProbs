class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m = nums.size()/2;
        map<int, int>mp;
        for(int i = 0; i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto i: mp)
        {
            if(i.second>m)
                return i.first;
        }
        
        return 0;
    }
};