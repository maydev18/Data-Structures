#include <iostream>
#include "D:\vs code mayank\Data Structures\Linked lists\singly linked list\singlylinkedlist.h"
using namespace std;
class Stack{
    public:
        LinkedList list;
        void push(int num);
        void pop();
        void rotate(int x);
        void traverse();
        int top();
};
void Stack :: push(int x){
    list.insert(x , 1);
}
void Stack :: pop(){
    list.deleteNode(1);
}

void Stack :: rotate(int x){
    Node * temp = list.head;
    while(x!=1){
        temp =  temp->next;
        x--;
    } 
    Node * curr = temp->next;
    temp->next = NULL;
    list.tail->next = list.head;
    list.tail = temp;
    list.head = curr;
}
int Stack :: top(){
    return list.head->val;
}
void Stack :: traverse(){
    list.traverse();
}