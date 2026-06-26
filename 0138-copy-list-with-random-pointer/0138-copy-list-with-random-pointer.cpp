

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        Node* dummy= new Node(100);
        Node* tempc=dummy;
        while(temp)
        {
            Node* a=new Node(temp->val);
            tempc->next=a;
            tempc=tempc->next;
            temp=temp->next;
        }
        Node* t2=dummy->next;
        Node* t1=head;
        Node* duplicate=new Node(-1);
        Node* tempd=duplicate;
        while(t1)
        {
            duplicate->next=t1;
            t1=t1->next;
            duplicate=duplicate->next;

            duplicate->next=t2;
            t2=t2->next;
            duplicate=duplicate->next;
        }
        t1=head;
        t2=dummy->next;
        while(t1)
        {
            if(t1->random) t2->random=t1->random->next;
            t1=t1->next->next;
            if(t2->next) t2 = t2->next->next;
        }
        dummy=dummy->next;
        Node* d1=new Node(100);
        Node* d2=new Node(200);
        t1=d1;
        t2=d2;
        Node* t=head;
        while(t)
        {
            t1->next=t;
            t=t->next;
            t1=t1->next;

            t2->next=t;
            t=t->next;
            t2=t2->next;
        }
        t1->next=NULL;
        t2->next=NULL;
        d1=d1->next;
        d2=d2->next;
        return d2;
    }
};