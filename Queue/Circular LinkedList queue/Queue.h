#include <iostream>
#include "D:\vs code mayank\Data Structures\Linked lists\singly linked list\singlylinkedlist.h"
class Queue{
    public:
        LinkedList list;
        void push(int elem);
        void pop();
        void traverse();
        int top();
        void interleave();
};
void Queue :: push(int elem){
    list.insert(elem , list.getSize()+1);
}
void Queue :: pop(){
    if(list.getSize()==0){
        cout << "Underflow" << endl;
        return;
    }
    cout << "popped element is : "<<list.head->val<<endl;
    list.deleteNode(1);
}
void Queue::traverse(){
    if(list.currnodes == 0){
        cout <<"Queue is Empty"<<endl;
        return;
    }
    list.traverse();
}
int Queue :: top(){
    return list.tail->val;
}
void Queue :: interleave(){
    Node * slow = list.head;
    Node * fast = list.head;
    while(fast && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(list.currnodes & 1){
        slow = slow->next;
    }
    fast = list.head;
    Node * n1 = slow;
    Node * n2 = fast;
    while(true){
        n1 = slow->next;
        n2 = fast->next;
        if(slow->next == NULL && list.currnodes%2==0){
            fast->next = slow;
            return;
        }
        fast->next = slow;
        slow->next = n2;
        if(n1 == NULL && list.currnodes%2==1){
            fast->next = slow;
            slow->next = n2;
            n2->next = NULL;
            break;
        }
        slow = n1;
        fast = n2;
    }
}