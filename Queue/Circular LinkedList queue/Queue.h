#include <iostream>
#include "D:\vs code mayank\Data Structures\Linked lists\Circular Singly Linked List\CircularSinglyLinkedlist.h"
class Queue{
    public:
        LinkedList<int> list;
        void push(int elem);
        void pop();
        void traverse();
        int top();
};
void Queue :: push(int elem){
    Node<int> * node = new Node<int>(elem);
    list.insert(node , list.getSize()+1);
}
void Queue :: pop(){
    if(list.getSize()==0){
        cout << "Underflow" << endl;
        return;
    }
    cout << "popped element is : "<<list.cursor->next->val<<endl;
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
    return list.cursor->val;
}
