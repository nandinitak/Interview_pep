class Solution {
public:
    // 1 pass solution
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head, *prev = head;
        
        while(n--){
            temp = temp->next;
        }

        if(!temp){ // n == Length
            return head->next; 
        }

        while (temp->next) {
            temp = temp->next;
            prev = prev->next;
        }

        ListNode* deleteNode = prev->next;
        prev->next = prev->next->next;
        delete(deleteNode);

        return head;
    }
};