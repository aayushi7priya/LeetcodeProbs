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

    void rec(TreeNode* root,int targetSum,int &currsum, vector<vector<int>> &ans,vector<int>&temp)
    {
      if(root==NULL)
          return ;
      
      if(root->left==NULL && root->right==NULL)
      {
          temp.push_back(root->val);
          currsum+=root->val;
          if(currsum==targetSum)
              ans.push_back(temp);
          //clear temp for storing any other possible path
          temp.pop_back();
          currsum-=root->val;
          return;
      }

    temp.push_back(root->val);
    currsum+=root->val; 
     
     rec(root->left,targetSum,currsum,ans,temp);
     rec(root->right,targetSum,currsum,ans,temp);

     temp.pop_back();
     currsum-=root->val;
    }



    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        int currsum=0;
        vector<int>temp;
        rec(root,targetSum,currsum,ans,temp);
        return ans;
    }
};