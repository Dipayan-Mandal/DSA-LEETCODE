/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * a=headA;
        ListNode * b=headB;
        int c=0;
        int d=0;
        while(a)
        {
            a=a->next;
            c++;
        }
        while(b)
        {
            b=b->next;
            d++;
        }
        a=headA;
        b=headB;
        if(c>d)
        {
            int diff = c - d;
            while(diff--)
            {
                a=a->next;
            }
        }
        else
        {
            int diff = d - c;
            while(diff--)
            {
                b=b->next;
            }
        }
        while(a)
        {
            if(a!=b)
            {
                a=a->next;
                b=b->next;
            }
            else
            {
                return a;
            }
        }
        return NULL;
    }
};