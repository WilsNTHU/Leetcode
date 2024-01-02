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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* ptr = root;
        while(ptr || !s.empty()){
            while(ptr){
                s.push(ptr);
                ptr = ptr->left;
            }
            ptr = s.top();
            s.pop();
            result.push_back(ptr->val);
            ptr = ptr->right;
        }
        
        return result;
    }
};