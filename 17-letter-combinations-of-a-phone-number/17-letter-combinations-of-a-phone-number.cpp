class Solution {
private: 
    void solve(string digits, int index, string mapping[], string output, vector<string>& ans){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        
        int number = digits[index] - '0';
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digits, index+1, mapping, output, ans);
            output.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        
        string output;
        string maping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int index = 0;
        solve(digits, index, maping, output, ans);
        return ans;        
    }
};