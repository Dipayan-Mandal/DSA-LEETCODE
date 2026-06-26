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
    ListNode* rev(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* nh = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        return nh;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        ListNode* temp = head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        int n = 1;
        while (temp) {
            if (n == (left - 1))
                a = temp;
            if (n == left)
                b = temp;
            if (n == right)
                c = temp;
            if (n == right + 1)
                d = temp;
            temp = temp->next;
            n++;
        }
        if (a)
            a->next = NULL;
        c->next = NULL;
        c = rev(b);
        if(b) b->next = d;
        if (a)
            a->next = c;
        if (a)
            return head;
        return c;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int left = 1;
        int sz = 1;

        while (head) {
            ListNode* temp = head;
            int cnt = 0;

            while (temp && cnt < left + sz - 1) {
                temp = temp->next;
                cnt++;
            }

            int actual = min(sz, cnt - left + 1);

            if (actual % 2 == 0)
                head = reverseBetween(head, left, left + actual - 1);

            left += actual;
            sz++;

            if (actual <= 0)
                break;
        }

        return head;
    }
};