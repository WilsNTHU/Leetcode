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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if(!root) return result;
        q.push(root);
        while(!q.empty()){
            vector<int> temp; 
            for(int i=q.size(); i>0; i--){
                TreeNode* node = q.front(); q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                temp.push_back(node->val);
            }
            result.push_back(temp);
        }
        
        return result;
    }
};