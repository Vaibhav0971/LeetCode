#include <vector>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        std::vector< int > arr;
        while (x>0){
            arr.push_back(x%10);
            x = x/10;
        }
        for(int i=0; i<arr.size(); i++){
            if(arr[i] != arr[arr.size() - 1 - i]){
                return false;
            }
        }
        return true;
    }
};