class Solution {
    int solve(vector<int>& nums, int start, int end){
        if(start > end){
            return 0;
        }
        
        int choice1 = nums[start] + min(solve(nums, start+2, end), solve(nums, start+1, end-1));
        int choice2 = nums[end] + min(solve(nums, start, end-2), solve(nums, start+1, end-1));
        
        return max(choice1, choice2);
    }
    
    
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        if(nums.size() == 1) return true;
        
        int ans = solve(nums, 0, nums.size()-1);
        
        int sum = 0;
        for(auto i : nums)
            sum += i;
        
        return ans >= (sum - ans); 
    }
};