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
    int findHeight(TreeNode* node, bool& isBalanced)
    {
        if(node == NULL) return 0;
        
        int leftH = findHeight(node -> left, isBalanced);
        int rightH = findHeight(node -> right, isBalanced);
        
        if(abs(leftH- rightH)>1) isBalanced = false;
        
        //return 1 + max(findHeight(node->left, isBalanced), findHeight(node->right, isBalanced));
        return 1 + max(leftH, rightH);
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        findHeight(root, ans);
        
        return ans;
    }
};