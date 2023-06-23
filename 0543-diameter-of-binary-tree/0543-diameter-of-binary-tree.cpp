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
        int lh = findHeight(node -> left);
        int rh = findHeight(node -> right);
        maxi = max(maxi, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        findHeight(root); 
        return maxi;
    }
};