/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
      void rec(TreeNode* root, vector<vector<int>> &ans,vector<int>&temp)
    {
      if(root==NULL) return ;
      
      if(root->left==NULL && root->right==NULL)
      {
          temp.push_back(root->val);
          ans.push_back(temp);
          temp.pop_back();
          return;
      }

     temp.push_back(root->val);
     rec(root->left,ans,temp);
     rec(root->right,ans,temp);
     temp.pop_back();
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>temp;
        rec(root,ans,temp);
        vector<string>ans1;
        for(int i =0;i<ans.size();i++)
        {
            string s= "";
            for(int j =0;j<ans[i].size();j++)
            {
                if(j!= ans[i].size()-1)
                {
                    s+=to_string(ans[i][j]);
                    s+="->";
                }
                else s+=to_string(ans[i][j]);
            }
            ans1.push_back(s);
        }
        return ans1;
    }
};