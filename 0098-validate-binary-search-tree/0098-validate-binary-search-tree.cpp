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
    // iterative solution
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* prev = nullptr;
        if(!root) return true;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            
            root = s.top(), s.pop();
            
            if(prev && prev->val >= root->val) return false;
            prev = root;
            root = root->right;
        }
        
        return true;
    }

};