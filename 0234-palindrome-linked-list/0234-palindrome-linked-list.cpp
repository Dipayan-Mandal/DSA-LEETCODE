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

    bool isPalindrome(ListNode* head) {
        ListNode* c=new ListNode(100);
        ListNode* temp=head;
        ListNode* tempc=c;
        while(temp)
        {
            ListNode* node=new ListNode(temp->val);
            tempc->next=node;
            temp=temp->next;
            tempc=tempc->next;
        }
        c=c->next;
        c=rev(c);
        while(head)
        {
            if(head->val!=c->val) return false;
            head=head->next;
            c=c->next;
        }
        return true;
    }
};