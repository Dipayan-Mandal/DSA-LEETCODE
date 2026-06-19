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
     ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* a = list1;
        ListNode* b = list2;
        ListNode* temp=new ListNode(100);
        ListNode* dummy=temp;
        while(a && b)
        {
            if(a->val<=b->val)
            {
                dummy->next=a;
                a=a->next;
                dummy=dummy->next;
            }
            else
            {
                dummy->next=b;
                b=b->next;
                dummy=dummy->next;
            }
        }
        if(a==NULL) dummy->next=b;
        else dummy->next=a;
        return temp->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return 0;
        while(lists.size()>1){
        ListNode* a=lists[0];
        lists.erase(lists.begin());
        ListNode* b=lists[0];
        lists.erase(lists.begin());
        ListNode* c=merge(a,b);
        lists.push_back(c);
        }
        return lists[0];
    }
};