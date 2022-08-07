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
    int ans = 0;
    
    void solve(TreeNode* root, int target, long long int sum){
        if(root == NULL) return;
        
        if(sum == target) ans++;
        
        if(root -> left != NULL)
            solve(root -> left, target, sum + root -> left -> val);
        
        if(root -> right != NULL)
            solve(root -> right, target, sum + root -> right -> val);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        
        solve(root, targetSum, root -> val);
        
        pathSum(root -> left, targetSum);
        pathSum(root -> right, targetSum);
        
        return ans;       
    }
};