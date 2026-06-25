
class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp=head;
        while(temp)
        {
            if(temp->child){
            Node* c=temp->child;
            temp->child=NULL;
            c=flatten(c);
            Node* a=temp->next;
            temp->next=NULL;
            temp->next=c;
            c->prev=temp;
            while(c->next)
            {
                c=c->next;
            }
            c->next=a;
            if(a) a->prev=c;
            }
             temp=temp->next;
        }
        return head;
    }
};