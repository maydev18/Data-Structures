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
};
void Stack :: push(int x){
    Node * n = new Node(x);
    if(list.currnodes == 0){
        list.insert(n,1);
    }
    else{
        list.insert(n,list.currnodes+1);
    }
}
void Stack :: pop(){
    list.deleteNode(list.currnodes);
}

void Stack :: rotate(int x){
    Node * temp = list.head;
    x = list.currnodes-x-1;
    while(x--){
        temp =  temp->next;
    }
    Node * curr = temp->next;
    temp->next = NULL;
    list.tail->next = list.head;
    list.tail = temp;
    list.head = curr;
}
void Stack :: traverse(){
    list.traverse();
}