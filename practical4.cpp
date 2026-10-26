#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node*prev;
    node*next;
    
    node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;

    }
};
class doublylinkedlist{
    head = nullptr;

}
void insert(int val){
    node *p=new node(val);
    if (head == nullptr){
        head=p;

    }else{
        node*q = head;
        while(q->next !=nullptr)
        {
            q=q->next;

        }
        q->next = p;
        p->prev = q;
    }
}
void remove(int val){
    node*p,*q;
    q = head;

    if(q->data==val){
        p=head;
        head=head->next;
        head->prev=nullptr;
        delete p;
        return;
    }
    while (q->next!=null){
        if(q->next->data==val){
            p=q->next;
            q->next = p->next;
            p->next->prev=q;
            delete p;
            return;
        }
        q=q->next;
    }
    cout<<"value"<<val<<"not found in the list.\n";

}
void displayforward(){
    node*q=head;
    cout<<"forward:";
    while(q!=nullptr){
        cout<<q->data<<"<->";
        q = q->next;

    }
    cout<<"NULL\n";
}
void displaybackward(){
    node*q=head;
    if(q==nullptr){
        cout<<"backward:NULL\n";
        return;
    }
    while(q->next!= nullptr){
        q=q->next;

    }
    cout<<"backward:";
    while(q!=nullptr){
        cout<<q->data<<"<->";
        q=q->prev;
    }
    cout<<"NULL\n";

};
int main(){
    doublylinkedlist list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.displayforward();
    list.displaybackward();

    list.remove(20);
    list.displayforward();
    list,displaybackward();

    return 0;
}