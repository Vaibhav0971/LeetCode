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
    void solve(TreeNode* root, vector<string>& output, string str){
        if(root -> left == NULL && root -> right == NULL){
            if(str.length() > 0){
                str += "->";
                str += to_string(root -> val);
            }
            else{
                str += to_string(root -> val);
            }
            output.push_back(str);
            return;
        }
        
        if(str.length() > 0){
            str += "->";
            str += to_string(root -> val);
        }
        else{
            str += to_string(root -> val);
        }
        
        if(root -> left) 
            solve(root -> left, output, str);
        if(root -> right) 
            solve(root -> right, output, str);
        
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> output;
        string str;
        solve(root, output, str);
        return output;
    }
};