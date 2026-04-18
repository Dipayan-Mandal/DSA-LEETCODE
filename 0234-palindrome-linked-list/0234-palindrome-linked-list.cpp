
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* nh = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nh;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverseList(slow->next);
        ListNode* a=head;
        ListNode* b=newHead;
        while(b)
        {
            if(a->val!=b->val)
            return false;
            a=a->next;
            b=b->next;
        }
        return true;
    }
};