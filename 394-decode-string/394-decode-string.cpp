class Solution {
    string solve(string& s, int& index){
        string ans = "";
     
        while(index < s.length() && s[index] != ']'){
            if(!isdigit(s[index])) {
                ans += s[index];
                index++;
            }
            else{
                int num = 0;
                while(index < s.length() && isdigit(s[index])){
                    num = num * 10 + s[index] - '0';
                    index++;
                }
                
                index++; // skip '['
                string temp = solve(s, index);
                index++; // skip ']'
                
                while(num-- > 0) ans += temp;
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