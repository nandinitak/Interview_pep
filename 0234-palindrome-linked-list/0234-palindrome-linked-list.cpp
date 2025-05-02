// 
class Solution {
public:
    ListNode* Middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* ReverseLinklist(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* Next = head->next;
            head->next = prev;
            prev = head;
            head = Next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* middle = Middle(head);
        ListNode* head2 = ReverseLinklist(middle);
        ListNode* temp1 = head;
        ListNode* temp2 = head2;
        while (temp2) {
            if (temp1->val != temp2->val)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};
