class ArrEl{
    public:
    int data;
    int row;
    int col;
    
    ArrEl(){}
    
    ArrEl(int a, int b, int c){
        data = a;
        row = b;
        col = c;
    }    
};

class comp{
    public:
    bool operator()(ArrEl* a, ArrEl* b){
        return a -> data > b -> data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<ArrEl*, vector<ArrEl*>, comp> q;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            maxi = max(nums[i][0], maxi);
            mini = min(nums[i][0], mini);
            ArrEl* temp = new ArrEl(nums[i][0], i, 0);
            q.push(temp);
        }
        
        int start = mini, end = maxi;
        
        while(!q.empty()){         
            ArrEl* temp = q.top();
            q.pop();
            
            mini = temp -> data;               
            
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }
            
            if(temp -> col + 1 < nums[temp -> row].size()){
                ArrEl* toPush = new ArrEl(nums[temp -> row][temp -> col + 1], temp -> row, temp -> col + 1);
                q.push(toPush);                
                maxi = max(maxi, toPush -> data);
            }
            else{
                break;
            }
        }
        
        ans.push_back(start);
        ans.push_back(end);
        
        return ans;        
    }
};








