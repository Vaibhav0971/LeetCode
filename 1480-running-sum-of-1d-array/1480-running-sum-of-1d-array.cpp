class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        long long int count = 0;
        
        for(int i=0; i<nums.size(); i++){
            count += nums[i];
            nums[i] = count;
        }
        
        return nums;        
    }
};