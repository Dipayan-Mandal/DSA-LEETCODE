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
public:
    ListNode* rev(ListNode* head)
    {
        if(head==NULL || head->next==NULL) return head;
        ListNode* nh=rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return nh;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* b=slow->next;
        slow->next=NULL;
        b=rev(b);
        //1-2
        //5-4-3
        ListNode* a=head;
        ListNode* temp=head;
        while(a && b)
        {
            temp=temp->next;
            a->next=b;
            a=temp;
            temp=b;

            temp=temp->next;
            b->next=a;
            b=temp;
            temp=a;
        }
        
    }
};