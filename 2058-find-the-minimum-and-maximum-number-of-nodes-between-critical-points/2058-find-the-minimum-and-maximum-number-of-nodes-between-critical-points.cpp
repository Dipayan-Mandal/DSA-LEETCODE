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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head;
        ListNode* a=head;
        ListNode* b=head->next;
        if(a==NULL || b==NULL || b->next==NULL) return {-1,-1};
        int maxd=0;
        ListNode* c=head->next->next;
        int idx=1;
        int fidx=-1;
        int sidx=0;
        while(c)
        {
            if(b->val<a->val && b->val<c->val || b->val>a->val && b->val>c->val)
            {
                if(fidx==-1) fidx=idx;
                else sidx=idx;
            }
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;
            
        }
        if(sidx==0) return{-1,-1};
            else maxd=sidx-fidx;
        a=head;
        b=head->next;
        c=head->next->next;
        idx=1;
        fidx=-1;
        sidx=-1;
        int mind=INT_MAX;
        while(c)
        {
            if(b->val<a->val && b->val<c->val || b->val>a->val && b->val>c->val)
            {
                fidx=sidx;
                sidx=idx;
                if(fidx!=-1){
                mind=min(mind,(sidx-fidx));
                }
            }
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;
        }
            return {mind,maxd};
    }
};