class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
         int n = pref.size();
        vector<int>ans(n);
        ans[0] = pref[0];
       // ans[1] = pref[1]^ans[0];
       // ans[2] = pref[2]^ans[0]^ans[1];
      // ans[3] = pref[3]^ans[0]^ans[1]^ans[2]
       
        int temp = ans[0];
        
        for(int i =1;i<n;i++)
        {
           ans[i] = pref[i]^temp;
            temp = temp^ans[i];
        }
        
        return ans;
    }
};