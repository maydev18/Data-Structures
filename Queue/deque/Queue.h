#include <iostream>
#include "D:\vs code mayank\Data Structures\Linked lists\Doubly Linked List\DoublyLinkedlist.h"
using namespace std;
template <typename T> class Deque{
    public:
        LinkedList<T> list;
        void push_back(T elem);
        void push_front(T elem);
        void pop_back();
        void pop_front();
        T get_front();
        T get_back();
        void traverse();
};
template<typename T> void Deque<T> :: push_back(T elem){
    Node<T> * node = new Node<T>(elem);
    if(list.currnodes == 0){
        list.insert(node , 1);
    }
    else{
        list.insert(node , list.currnodes+1);
    }
}
template<typename T> void Deque<T> :: push_front(T elem){
    Node<T> * node = new Node<T>(elem);
    list.insert(node , 1);
}
template<typename T> void Deque<T> :: pop_back(){
    list.deleteNode(list.currnodes);
}
template<typename T> void Deque<T> :: pop_front(){
    list.deleteNode(1);
}
template <typename T> void Deque<T> :: traverse(){
    list.traverse();
}

