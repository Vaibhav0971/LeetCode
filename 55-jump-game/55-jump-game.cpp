class Solution {
public:
    bool canJump(vector<int>& nums) {
//         int index = 0;
//         int distance = 0;
        
//         for(int distance; index < nums.size() && index <= distance; ++index){            
                     
//                 distance = max(index + nums[index], distance);
            
//         }
        
//         return index == nums.size();
        
        
        int index = 0;
        for (int distance = 0; index < nums.size() && index <= distance; ++index)
            distance = max(index + nums[index], distance);
        return index == nums.size();
        
        
        
        
        // int i = 0;
        // for (int reach = 0; i < nums.size() && i <= reach; ++i)
        //     reach = max(i + nums[i], reach);
        // return i == nums.size();
    }
};