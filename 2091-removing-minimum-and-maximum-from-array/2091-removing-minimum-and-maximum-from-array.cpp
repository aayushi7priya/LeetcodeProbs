class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_index;
        int mini = 1e9;
        int max_index;
        int maxi = -1e9;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]<mini)
            {
                mini = nums[i];
                min_index = i;
            }
            if(nums[i]>maxi)
            {
                maxi = nums[i];
                max_index = i;
            }
        }
        //ya to front aur end se, ya to end se ya to front se
        int front_min = min_index + 1;
        int end_min = n - min_index;
        int front_max = max_index + 1;
        int end_max = n - max_index;
        //cout<<front_min<<" This is front_min";
        //cout<<end_min<<"This is end min"<<endl;
        //cout<<front_max<<"this is front_max"<<endl;
        //cout<<end_max<<"ths is end_max"<<endl;
        int ans = n;
        if(front_min > front_max) 
        {
            ans = min(ans, front_min);
            ans = min(ans, end_max);
        }
        else if ( front_max > front_min)
        {
            ans = min(ans, front_max);
            ans = min(ans, end_min);
        }
        ans = min({ans, front_min + end_max, front_max + end_min});
        return ans;
        
        
    }
};