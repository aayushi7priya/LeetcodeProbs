/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* target1;
    TreeNode* ans;
    void inorder(TreeNode* rootO, TreeNode* rootC )
    {
        //left root right
        if(rootO!= NULL)
        {
            inorder(rootO->left, rootC -> left );
            if(rootO == target1) ans = rootC;
            inorder(rootO -> right, rootC -> right);
        }
        
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        target1 = target;
        inorder(original, cloned);
        return ans;
    }
};