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
    int ans;
    void levelorder(TreeNode* root)
    {
       // vector<vector<int>>ans;
        if(root == NULL) return ;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            ans = 0;
            int size = q.size();
           // vector<int>level;
            for(int i =0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                 ans+=node->val;
                if(node -> left != NULL) q.push(node->left);
                if(node -> right != NULL) q.push(node -> right);
                //level.push_back(node -> val);
               
            }
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        levelorder(root);
        return ans;
    }
};