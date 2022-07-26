
class Solution {
    
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;        
    }
    
    ListNode* reverse(ListNode* head){
        if(head == NULL || head -> next == NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        
        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;        
    }
        
    
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* mid = findMid(head);
        
        ListNode* temp = mid;
        
        temp -> next = reverse(mid -> next);   
        
        temp = temp -> next;
        
        while(temp != NULL && head != temp){
            if(temp -> val != head -> val){
                return false;
            }
            temp = temp -> next;
            head = head -> next;            
        }
        
        return true;        
    }
};