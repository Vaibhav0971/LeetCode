class Solution {
    
    void solve(int index, int k, int target, vector<int>& output, vector<vector<int>>& ans){
        
        if(target == 0 && k == 0){
            ans.push_back(output);
            return;
        }
        
        if(index > 9 || k < 0) return;
        
        for(int i=index; i<=9; i++){
            output.push_back(i);
            solve(i+1, k-1, target - i, output, ans);
            output.pop_back();   
        }   
    }
    
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 1;
        
        solve(index, k, n, output, ans);
        
        return ans;        
    }
};