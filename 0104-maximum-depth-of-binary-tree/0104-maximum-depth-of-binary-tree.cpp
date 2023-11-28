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
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        map<TreeNode *, bool> visited;
        DFS(visited, root, max_depth, 0);
        
        return max_depth;
    }
    
    void DFS(map<TreeNode *, bool> visited, TreeNode* root, int &max_depth, int depth){
        if(!root){
            max_depth = (depth > max_depth) ? depth : max_depth;
            return;
        }
        
        visited[root] = true;
        if(!visited[root->left]) DFS(visited, root->left, max_depth, depth +1);
        if(!visited[root->right]) DFS(visited, root->right, max_depth, depth +1);
        
    }
};