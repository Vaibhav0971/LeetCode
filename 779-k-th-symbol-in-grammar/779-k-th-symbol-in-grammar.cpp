class Solution {
    
    void solve(string& num, int n){
        if(n <= 0) return;
        
        for(int i=num.length()-1; i>=0; i--){
            if(num[i] == '0'){
                num.replace(i, 1, "01");
            }
            else if(num[i] == '1'){
                num.replace(i, 1, "10");
            }
        }
        
        solve(num, n-1);
    }
     
    int solveOptimized(int n, int k){
        if(n == 1) return 0;
        
        int mid = pow(2, n-1)/2;
        
        if(k <= mid){
            return solveOptimized(n-1, k);
        }
        else{
            return !solveOptimized(n-1, k-mid);
        }
    }
    
    
public:
    int kthGrammar(int n, int k) {
        // string num = "0";        
        // solve(num, n-1);        
        // return num[k-1] - '0';        
        
        return solveOptimized(n, k);
    }
};