class Solution {
    
    // My Solution
    void solve(int index, int target, vector<int>& c, vector<int>& output, vector<vector<int>>& ans){
        if(index >= c.size()) return;
        
        if(target == 0){
            ans.push_back(output);
            return;
        }
        
        if(target < c[0]) return;
        
        for(int i=index; i<c.size(); i++){
            if((target - c[i]) >= c[0] || (target - c[i]) == 0){
                output.push_back(c[i]);
                solve(i, target - c[i], c, output, ans);                
                output.pop_back();
            }
        }        
    }
    
    // Love Solution
    void solve2(int index, int target, vector<int>& c, vector<int>& output, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(output);
            return;
        }
        
        if(target < 0 || index >= c.size())
            return;
        
        // exclude
        solve2(index+1, target, c, output, ans);
        
        //include
        output.push_back(c[index]);
        solve2(index, target-c[index], c, output, ans);
        output.pop_back();
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        
        sort(candidates.begin(), candidates.end());
        
        solve(index, target, candidates, output, ans);
        
        return ans;
    }
};