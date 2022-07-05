// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool isSafe(int x, int y, int n, vector<vector<int>> &m, vector<vector<int>>& visited){
        if((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) return true;
        
        return false;
    }
    
    void solve(int x, int y, string path, int n, vector<vector<int>> &m, vector<vector<int>>& visited, vector<string>& ans){
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        // move down
        int newX = x+1;
        int newY = y;
        if(isSafe(newX, newY, n, m, visited)){
            path.push_back('D');
            solve(newX, newY, path, n, m, visited, ans);
            path.pop_back();
        }
        // move left
        newX = x;
        newY = y-1;
        if(isSafe(newX, newY, n, m, visited)){
            path.push_back('L');
            solve(newX, newY, path, n, m, visited, ans);
            path.pop_back();
        }
        // move right
        newX = x;
        newY = y+1;
        if(isSafe(newX, newY, n, m, visited)){
            path.push_back('R');
            solve(newX, newY, path, n, m, visited, ans);
            path.pop_back();
        }
        // move up
        newX = x-1;
        newY = y;
        if(isSafe(newX, newY, n, m, visited)){
            path.push_back('U');
            solve(newX, newY, path, n, m, visited, ans);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0] == 0) return ans;
        
        vector<vector<int>> visited = m;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        
        int srcX = 0;
        int srcY = 0;
        string moves = "";
        
        solve(srcX, srcY, moves, n, m, visited, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends