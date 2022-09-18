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
class ListElement{
    public:
    ListNode* node;
    int row;
    
    ListElement();
    
    ListElement(ListNode* node, int row){
        this -> node = node;
        this -> row = row;
    }
};

class compartor{
    public:
    bool operator()(ListElement* a, ListElement* b){
        return a -> node -> val > b -> node -> val; 
    }
};


class Solution {
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {        
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        
        if(lists.size() == 0) return head -> next;
        
        priority_queue<ListElement*, vector<ListElement*>, compartor> q;
        
        for(int i=0; i<lists.size(); i++){
            if(lists[i]){
                ListElement* temp = new ListElement(lists[i], i);
                q.push(temp);
            }
        }
        
        while(!q.empty()){
            ListElement* temp = q.top();
            q.pop();
            tail -> next = temp -> node;
            tail = tail -> next;
            
            if(temp -> node -> next){
                ListElement* toPush = new ListElement(temp -> node -> next, temp -> row);
                q.push(toPush);
            }
        }
        
        tail -> next = NULL;
        
        return head -> next;
    }
};













