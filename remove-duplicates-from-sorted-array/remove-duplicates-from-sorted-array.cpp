class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        map<int, int>mp;
        for(int i =0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        nums.clear();
        for(auto i: mp)
        {
            nums.push_back(i.first);
        }
        return mp.size();
        
    }
};