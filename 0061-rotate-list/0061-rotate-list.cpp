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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        
        int count=0;
        if(temp==NULL || temp->next==NULL) return head;
        while(temp)
        {
            temp=temp->next;
            count++;
        }
        k%=count;
        if(k == 0)
            return head;
        int n=count-k-1;
        temp=head;
        while(n--)
        {
            temp=temp->next;
        }
        ListNode* nex=temp->next;
        ListNode* tail=nex;
        while(tail->next)
        {
            tail=tail->next;
        }
        tail->next=head;
        temp->next=NULL;
        return nex;

    }
};
