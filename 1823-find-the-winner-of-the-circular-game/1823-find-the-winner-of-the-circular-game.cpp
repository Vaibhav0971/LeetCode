class Solution {

int solve(int k, int index, vector<int>& arr){    
    if(arr.size() == 1) return arr[0];
    
    int newIndex = index + k - 1;
    
    if(newIndex < arr.size()){
        arr.erase(arr.begin() + newIndex);
        index = newIndex;
    }
    else{
        int temp = (index + k) % arr.size();
        if(temp == 0) temp = arr.size();
        
        newIndex = temp - 1;
        arr.erase(arr.begin() + newIndex);
        index = newIndex;
    }
    
    return solve(k, index, arr);    
}
    
    
public:
    int findTheWinner(int n, int k) {
        vector<int> arr;
        
        for(int i=1; i<=n; i++) arr.push_back(i);
        
        return solve(k, 0, arr);        
    }
};