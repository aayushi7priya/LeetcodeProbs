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

//doubts
//----pehla ki map mai ye kaise store krte usme bhot dikkat aa rhi smhne mai
//---and last final ans mai store karne ke liye ye map ko access kaise ho rha
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode* , pair<int,int>>>q;  //node, vertical,level
        map<int, map<int, multiset<int>>> mp;     //vertical, level, nodes
        //mp[vertical] -> mp[level] = nodes
        q.push({root, {0, 0}});
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int y = p.second.first;
            int x = p.second.second;
            
            mp[x][y].insert(node -> val);
            if(node -> left != NULL) q.push({node -> left,{y+1, x-1}});
            if(node -> right != NULL) q.push({node -> right,{y+1, x+1}});
        }
        
         vector<vector<int>> ans;
         for(auto it:mp)
         {
            vector<int> col;
            for(auto t:it.second)
            {
                for(auto x:t.second)
                {
                    col.push_back(x);
                }
            }
            ans.push_back(col);
        }
        return ans;
    
    }
};