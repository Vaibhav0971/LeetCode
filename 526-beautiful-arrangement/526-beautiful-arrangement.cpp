class Solution {
    void solve(int index, vector<int> nums, int& ans){
        if(index >= nums.size()){            
            ans++;
            return;
        }
        
        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]); 
            
            if(nums[index]%(index+1) == 0 || (index+1)%nums[index] == 0)
                solve(index+1, nums, ans);
            
            swap(nums[index], nums[i]);
        }
    }
    
public:
    int countArrangement(int n) {
        vector<int> nums;
        for(int i=1; i<=n; i++)
            nums.push_back(i);
        
        int ans = 0;
        int index = 0;
        
        solve(index, nums, ans);
        
        // for(auto i : ans)
        //     cout<<i<<", ";
        
        return ans;        
    }
};