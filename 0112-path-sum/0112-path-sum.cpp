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
    
    bool rec(TreeNode* node, int sum)
    {
        if (node == NULL)
            return false;
        
        if (node->left == nullptr && node->right == nullptr && sum == node->val) //it has reached leaf node
            return true;
        
        int x = node -> val;
        bool left = rec(node->left, sum - node->val);
        bool right = rec(node->right, sum - node->val);
        
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return(rec(root, targetSum)==1);
    }
};