class Solution {
    void solve(int n, int open, int close, string output, vector<string>& ans){
        if(open == 0 && close == 0){
            ans.push_back(output);
            return;
        }
        
        // add opening parentheses
        if(open > 0){
            output.push_back('(');
            solve(n, open-1, close, output, ans);
            output.pop_back();
        }
        
        // add closeing parentheses while checking the closing bracket does not exceed the opening
        if(close > 0 && ((n-open) > (n-close))){
            output.push_back(')');
            solve(n, open, close-1, output, ans);
            output.pop_back();
        }
        
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "(";
        
        solve(n, n-1, n, output, ans);
        
        return ans;
    }
};