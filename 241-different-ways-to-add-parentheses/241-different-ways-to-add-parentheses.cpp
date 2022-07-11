class Solution {

public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        
        for(int i=0; i<expression.length(); i++){
            
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                
                vector<int> leftSide = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightSide = diffWaysToCompute(expression.substr(i+1));
                
                for(auto x : leftSide){
                    for(auto y : rightSide){
                        if(expression[i] == '+') ans.push_back(x + y);
                        if(expression[i] == '-') ans.push_back(x - y);
                        if(expression[i] == '*') ans.push_back(x * y);
                    }
                }                
            }
        }
                                        
        if(!ans.size()) ans.push_back(stoi(expression));        
        return ans;        
    }
};