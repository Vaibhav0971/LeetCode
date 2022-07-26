/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL) return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        ListNode* temp = head -> next;
        
        
        while(temp != NULL && temp != head && fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
            
            if(slow == fast) return true;
            temp = temp -> next;
        }
        
        if(temp == head) return true;
        
        return false;
    }
};