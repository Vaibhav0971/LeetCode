/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
    ListNode* solve(ListNode* &head, bool& anyChange){
        if(head == NULL) return head;
        
        int sum = 0;
        
        ListNode* temp = head;
        
        while(temp != NULL){
            sum += temp -> val;
            if(sum == 0){
                anyChange = true;
                return temp -> next;
            }
            temp = temp -> next;
        }        
        
        head -> next = solve(head -> next, anyChange);
        
        return head;
    }
    
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        while(true){
            bool anyChange = false;
            head = solve(head, anyChange);
            
            if(head == NULL || anyChange == false){
                break;
            }
        }
        
        return head;        
    }
};