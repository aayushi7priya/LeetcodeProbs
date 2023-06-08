class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        for(auto v:nums)
        {
            if(temp.empty()||temp.back()<v)
            {
                temp.push_back(v);
            }
            else
            {
                auto it = lower_bound(temp.begin(), temp.end(), v);
                *it = v;
            }
        }
        return temp.size();
    }
};