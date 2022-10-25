#include <iostream>
using namespace std;
template <typename T> class Node{
    public:
    T val;
    Node* next;
    Node(){
        val = 0;
        next = NULL;
    }
    Node(T val){
        this->val = val;
        next = NULL;
    }
    Node(T val , Node*next){
        this->val = val;
        this->next = next;
    }
};
template <typename T> class LinkedList{
    public:
    Node <T>* cursor;
    int currnodes = 0;
    LinkedList();
    LinkedList(Node<T>* n);
    void traverse();
    void insert(Node<T> * n , int pos);
    void deleteNode(int pos);
    int searchElem(int elem);
    int getSize();
    bool isEmpty();
    int printElemBeforePos(int pos);
    int printElemAfterPos(int pos);
    void concatenate(LinkedList<T>& l);
};
template<typename T> LinkedList<T> ::LinkedList(){
    cursor = NULL;
    currnodes = 0;
}
template<typename T> LinkedList<T> ::LinkedList(Node<T> * n){
    currnodes = 1;
    cursor = n;
}
template<typename T> void LinkedList<T> ::traverse(){
    Node<T>*dummy = cursor->next->next;
    cout << cursor->next->val<<" ";
    while(dummy != cursor->next){
        cout << dummy->val<<" ";
        dummy = dummy->next;
    }
    cout << endl;
}
template<typename T> void LinkedList<T> ::insert(Node<T> * n , int pos){
    if(pos == 1){
        if(currnodes == 0){
            cursor = n;
            cursor->next = n;
        }
        else{
            n->next = cursor->next;
            cursor->next = n;
        }
    }
    else if(pos == currnodes+1){
        n->next = cursor->next;
        cursor->next = n;
        cursor = n;
    }
    else{
        Node<T> * prev = cursor->next;
        for(int i = 2 ; i<pos ; i++){
            prev = prev->next;
        }
        n->next = prev->next;
        prev->next = n;
    }
    currnodes++;
}
template<typename T> void LinkedList<T> ::deleteNode(int pos){
    if(currnodes == 1){
        cursor = NULL;
        currnodes--;
        return;
    }
    if(pos == 1){
        Node<T>* n = cursor->next;
        cursor->next = n->next;
    }
    else{
        Node<T>* prev = cursor->next;
        for(int i = 2 ; i<pos ; i++){
            prev = prev->next;
        }
        Node<T> * curr = prev->next;
        prev->next = curr->next;
    }
    currnodes--;
}
template<typename T> int LinkedList<T> ::searchElem(int elem){
    int pos = -1;
    Node<T>* dummy = cursor->next;
    if(elem ==cursor->val) return currnodes;
    int currpos = 1;
    while(dummy!=cursor){
        if(dummy->val == elem){
            pos = currpos;
            break;
        }
        currpos++;
        dummy = dummy->next;
    }
    return pos;
}
template<typename T> int LinkedList<T> ::getSize(){
    return currnodes;
}
template<typename T> bool LinkedList<T> ::isEmpty(){
    if(currnodes == 0) return true;
    return false;
}
template<typename T> int LinkedList<T> ::printElemBeforePos(int pos){
    Node<T>* dummy = cursor->next;
    if(pos == 1){
        return cursor->val;
    }
    for(int i = 2 ; i<pos ; i++){
        dummy = dummy->next;
    }
    return dummy->val;
}
template<typename T> int LinkedList<T> ::printElemAfterPos(int pos){
    if(pos == currnodes){
        return cursor->next->val;
    }
    Node<T>* dummy = cursor->next;
    for(int i = 2 ; i<=pos+1 ; i++){
        dummy = dummy->next;
    }
    return dummy->val;
}
template<typename T> void LinkedList<T>::concatenate(LinkedList<T>& l){
    Node<T> * n = cursor->next;
    cursor->next = l.cursor->next;
    l.cursor->next = n; 
    cursor = l.cursor;
    currnodes += l.currnodes;
}
