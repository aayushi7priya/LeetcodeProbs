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
    int maxi = -1e9;
    
    int maxSum(TreeNode* node)
    {
        if(node == NULL) return 0;
        int leftsum = max(0,maxSum(node -> left)); //doing max so that it doesn't include negative path 
        int rightsum = max(0,maxSum(node -> right)); //e.g. 2, -1
        
        maxi = max(maxi, node->val + leftsum + rightsum);
        
        return node-> val + max(leftsum, rightsum);
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        
         maxSum(root);
        return maxi;
        
    }
};