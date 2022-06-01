class Solution {   
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0, e=nums.size()-1, m=e/2;
        
        while(s<=e){
            if(nums[m] == target){
                return m;
            }
            
            if(target > nums[m]) s = m + 1;
            else e = m - 1;
            
            m=s+(e-s)/2;
        }
        
        return m;
    }
};