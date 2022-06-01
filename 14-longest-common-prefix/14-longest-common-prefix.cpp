class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1){
            return strs[0];
        }
        
        string output = "";
        // int shortestStringLen = 1;
        
        for(int j=0; j<strs[0].length(); j++){
            for(int i=1; i<strs.size(); i++){
                // shortestStringLen = strs[i].size() < shortestStringLen
                if(j == strs[i].length()){ 
                    return output;
                }
                if(strs[0].at(j) != strs[i].at(j)){
                    cout<<output<<endl;
                    return output;
                }
            }
            output += strs[0].at(j);
        }
        cout<<output<<endl;
        return output;
    }
};