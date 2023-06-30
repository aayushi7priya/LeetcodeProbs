class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n =arr.size();
        int ans =0;
        for(int i =0;i<n;i++)
        {
            int num = arr[i];
            for(int j = i+1; j<n;j++)
            {
                num = num^arr[j];
                if(num==0)
                    ans+=(j-i);
            }
            
        }
        return ans;
    }
};