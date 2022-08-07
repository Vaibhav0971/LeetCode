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
    pair<int, bool> solve(TreeNode* &root){
        if(root == NULL) {
            return make_pair(0, true);
        }
        
        pair<int, bool> left = solve(root -> left);
        pair<int, bool> right = solve(root -> right);
        
        bool diff = abs(left.first - right.first) <= 1;        
        
        if(left.second && right.second && diff){
            return make_pair(max(left.first, right.first) + 1, true);
        }
        else{
            return make_pair(max(left.first, right.first) + 1, false);          
        }
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return solve(root).second;
    }
};