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
    //diamtere of binary tree - for each node max (height of left subtree + height of right subtree)
    int maxi =0;
    
    int findHeight(TreeNode* node)
    {
        if(node == NULL) return 0;
        return 1 + max(findHeight(node -> left), findHeight(node -> right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lh = findHeight(root -> left);
        int rh = findHeight(root -> right);
        
        maxi = max(maxi, lh + rh);
        diameterOfBinaryTree(root -> left);
        diameterOfBinaryTree(root -> right);
        
        return maxi;
    }
};