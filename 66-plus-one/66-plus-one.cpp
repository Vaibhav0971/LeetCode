class Solution {
    
    vector<int> addOne(vector<int>& digits, int len) {
        
        if(len == 1 && digits[len-1] == 9){
            digits[len-1] = 0;
            digits.insert(digits.begin(), 1);
            return digits;
        }
        
        if(digits[len-1] < 9){
            digits[len-1] = digits[len-1] + 1;
            return digits;
        }
        else{
            digits[len-1] = 0;
            return addOne(digits, len - 1);
        }
        
    }
    
public:
    vector<int> plusOne(vector<int>& digits) {
        
        return addOne(digits, digits.size());
    }
};