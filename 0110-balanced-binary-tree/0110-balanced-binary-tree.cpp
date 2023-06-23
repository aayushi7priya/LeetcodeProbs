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
    //naive solution
    //time complexity - O(N*N)
    //just going and checking each and every node's subtree height 
    int findHeight(TreeNode* node)
    {
        if(node == NULL) return 0;
        
        return 1 + max(findHeight(node->left), findHeight(node->right));
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL) return true;
        
        int lh = findHeight(root -> left);
        int rh = findHeight(root -> right);
        
        if(abs(lh-rh)>1) return false;
        
        else{
            if(isBalanced(root->left)==false || isBalanced(root->right)==false) return false;
        }
        return true;
    }
};