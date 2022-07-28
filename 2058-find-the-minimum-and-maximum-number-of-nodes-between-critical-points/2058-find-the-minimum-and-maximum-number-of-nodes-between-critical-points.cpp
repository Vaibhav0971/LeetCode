class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int index = 1;
        int minD = INT_MAX;
        int maxD = INT_MIN;
        vector<int> CP;
        vector<int> ans;
        
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        ListNode* prev = head;
        ListNode* temp = head -> next;
        
        while(temp != NULL && temp -> next != NULL){
            index++;
            if((prev -> val < temp -> val) && (temp -> val > temp -> next -> val)){
                if(CP.size() > 0){
                    minD = min(index - CP[CP.size() - 1], minD);
                    maxD = max(index - CP[0], maxD);
                }
                CP.push_back(index);
            }
            else if((prev -> val > temp -> val) && (temp -> val < temp -> next -> val)){
                if(CP.size() > 0){
                    minD = min(index - CP[CP.size() - 1], minD);
                    maxD = max(index - CP[0], maxD);
                }
                CP.push_back(index);
            }
            prev = temp;
            temp = temp -> next;
        }
        
        if(CP.size() == 1 || CP.size() == 0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        ans.push_back(minD);
        ans.push_back(maxD);
        return ans;
    }
};