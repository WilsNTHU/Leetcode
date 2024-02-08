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
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        while(root){
            if(abs(root->val - target) < abs(ans - target)) 
                ans = root->val;
            if(abs(root->val - target) == abs(ans - target)) 
                ans = (root->val < ans) ? root->val : ans;
            
            if(target < root->val) root = root->left;
            else if(target > root->val) root = root->right;
            else break;
        }
        
        return ans;
    }
};