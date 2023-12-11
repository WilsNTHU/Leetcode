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
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int start, int end){
        if(start > end) return {NULL};
        if(start == end){
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        
        
        
        vector<TreeNode*> result;
        for(int i=start; i<=end; i++){
            vector<TreeNode*> left_tree = helper(start, i-1);
            vector<TreeNode*> right_tree = helper(i+1, end);
            
            for(TreeNode *left: left_tree){
                for(TreeNode *right: right_tree){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
    
};