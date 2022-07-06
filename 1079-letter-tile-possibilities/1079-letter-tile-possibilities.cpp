class Solution {
void solve(map<int, bool> flag, string tiles, string output, set<string>& ans){
    for(int i=0; i<tiles.length(); i++){
        char ch = tiles[i];
        if(flag[i] == false){
            output.push_back(ch);
            ans.insert(output);
            flag[i] = true;
            solve(flag, tiles, output, ans);
            output.pop_back();
            flag[i] = false;
        }
    }
}
    
    
public:
    int numTilePossibilities(string tiles) {
        string output = "";
        set<string> ans;
        map<int, bool> flag;
        
        solve(flag, tiles, output, ans);
        
        return ans.size();        
    }
};