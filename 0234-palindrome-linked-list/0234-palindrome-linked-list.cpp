// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* Middle(ListNode* head){
//         ListNode* slow=head;
//         ListNode* fast=head;
//         while(fast && fast->next){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         return slow;
//     }
//     ListNode* ReverseLinklist(ListNode* head){
//         ListNode* prev= nullptr;
//         while(head){
//             ListNode* Next=head->next;
//             head->next=prev;
//              prev=head;
//             head=Next;
//         }
//         return prev;
//     }
//     bool isPalindrome(ListNode* head) {
//           if (!head || !head->next) return true;

//         ListNode *middle=Middle(head);
//         bool ispalin=false;
//         ListNode* head2=ReverseLinklist(middle);
//         ListNode* temp=head;
//         while(head2){
//             if(temp->val!=head2->val)
//             ispalin=false;
//             else{
//                 ispalin=true;
//             }
//             temp=temp->next;
//             head2=head2->next;
//         }
//         return ispalin;
//     }
// };
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
