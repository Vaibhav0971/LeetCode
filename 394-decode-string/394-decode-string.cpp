class Solution {
    string solve(string& s, int& index){
        string ans = "";
        
        while(index < s.length() && s[index] != ']'){
            if(!isdigit(s[index])){
                // get char before the number if any
                ans += s[index];
                index++;
            }
            else{
                // get the number
                int num = 0;
                while(index < s.length() && isdigit(s[index])){
                    num = num * 10 + s[index] - '0';
                    index++;
                }
                
                // we must have reached a starting bracket '[', so skip this
                index++;
                string temp = solve(s, index);
                // as we have retured them we must have reached a closing bracket ']', so skip this
                index++;
                
                // add the recursion result to the ans
                while(num-- > 0){
                    ans += temp;
                }
            }
        }
        
        return ans;
    }
    
    
public:
    string decodeString(string s) {
        int index = 0;
        return solve(s, index);
    }
};