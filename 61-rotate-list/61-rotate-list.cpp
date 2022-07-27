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
    int getLength(ListNode* head){
        int count = 0;
        
        while(head != NULL){
            head = head -> next;
            count++;
        }        
        return count;
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k == 0) return head;
        
        int len = getLength(head);
        k = k % len;
        
        if(k == 0) return head;
        
        int rotate = len - k;
        
        ListNode* prev = NULL;
        ListNode* temp = head;
        
        while(temp != NULL && rotate > 0){
            prev = temp;
            temp = temp -> next;   
            rotate--;
        }
        
        prev -> next = NULL;
        ListNode* newHead = temp;
        
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        
        temp -> next = head;
        
        head = newHead;
        
        return head;        
    }
};