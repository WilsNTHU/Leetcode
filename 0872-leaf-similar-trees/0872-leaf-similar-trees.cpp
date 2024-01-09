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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr_1, arr_2;
        helper(arr_1, root1);
        helper(arr_2, root2);
        return (arr_1 == arr_2);
    }
    
    void helper(vector<int> &arr, TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right){
            arr.push_back(root->val);
            return;
        } 
        helper(arr, root->left);
        helper(arr, root->right);
        return;
    }
};