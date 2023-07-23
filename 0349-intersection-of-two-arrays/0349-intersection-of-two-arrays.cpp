class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        set<int>ans;
        vector<int>ans1;
        if(n<m)
        {
            for(int i =0;i<n;i++)
            {
                auto it = find(nums2.begin(), nums2.end(), nums1[i] );
                if(it!=nums2.end())
                {
                    ans.insert(nums1[i]);
                }
                else continue;
            }
        }
        else {
            for(int i =0;i<m;i++)
            {
                auto it = find(nums1.begin(), nums1.end(), nums2[i] );
                if(it!=nums1.end())
                {
                    ans.insert(nums2[i]);
                }
                else continue;
            }
        }
        for(auto i: ans)
        {
            ans1.push_back(i);
        }
        
        return ans1;
    }
};