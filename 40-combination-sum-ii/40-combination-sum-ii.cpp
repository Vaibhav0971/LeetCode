class Solution {
    
    void solve(int index, int target, vector<int>& c, vector<int>& output, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(output);
            return;
        }
        
        if(target < c[0] || index >= c.size()) return;
        
        for(int i=index; i<c.size(); i++){
            
            if(i > index && c[i] == c[i-1]) continue;
            
            // if statement is just to optimise a bit
            if((target - c[i]) >= c[0] || (target - c[i]) == 0){
                output.push_back(c[i]);
                solve(i+1, target - c[i], c, output, ans); 
                output.pop_back();
            }
        } 
    }
    
    
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        
        sort(candidates.begin(), candidates.end());
        
        solve(index, target, candidates, output, ans);
        
        return ans;        
    }
};