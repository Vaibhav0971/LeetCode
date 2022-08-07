
class Solution {
    
    int height(TreeNode* &root){
        if(root == NULL) return 0;
        
        return 1 + max(height(root -> left), height(root -> right));
    }
    
    int diameter(TreeNode* &root){
        if(root == NULL) return 0;
        
        int option1 = diameter(root -> left); // diameter exits in left side of tree
        int option2 = diameter(root -> right); // diameter exits in right side of tree
        int option3 = 1 + height(root -> left) + height(root -> right);
        
        return max(option1, max(option2, option3));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root) - 1;        
    }
};