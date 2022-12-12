#include <iostream>
using namespace std;
template <typename T> class Node{
    public:
    T val;
    Node<T>* next;
    Node<T>* prev;
    Node(){
        val = 0;
        next = NULL;
        prev = NULL;
    }
    Node(T val){
        this->val = val;
        next = NULL;
        prev = NULL;
    }
    Node(T val , Node<T>*next , Node<T> * prev){
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};
template <typename T> class LinkedList{
    public:
    Node<T> * head;
    Node<T>* tail;
    int currnodes = 0;
    LinkedList(){
        head = NULL;
        tail = NULL;
        currnodes = 0;
    }
    LinkedList(Node<T>*n){
        currnodes = 1;
        head = n;
        tail = n;
    }
    void traverse(){
        Node<T>*dummy = head;
        while(dummy){
            cout << dummy->val<<" ";
            dummy = dummy->next;
        }
        cout << endl;
    }
    void insert(Node<T> * n , int pos){
        if(pos == 1){
            if(currnodes == 0){
                head = n;
                tail = n;
            }
            else{
                n->next = head;
                head->prev = n;
                head = n;
                n->prev = NULL;
            }
        }
        else if(pos == currnodes+1){
            n->next = NULL;
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        else{
            Node<T> * prev = head;
            for(int i = 2 ; i<pos ; i++){
                prev = prev->next;
            }
            n->next = prev->next;
            n->prev = prev;
            prev->next = n;
            n->next->prev = n;
        }
        currnodes++;
    }
    void deleteNode(int pos){
        if(currnodes == 1){
            head = NULL;
            tail = NULL;
            currnodes--;
            return;
        }
        if(pos == 1){
            head = head->next;
            head->prev = NULL;
        }
        else if(pos == currnodes){
            tail = tail->prev;
            tail->next = NULL;
        }
        else{
            Node<T> * prev = head;
            for(int i = 2 ; i<pos ; i++){
                prev = prev->next;
            }
            Node <T>* curr = prev->next;
            prev->next = curr->next;
            curr->next->prev = prev;
        }
        currnodes--;
    }
    int searchElem(int elem){
        int pos = -1;
        Node <T>* dummy = head;
        int currpos = 1;
        while(dummy){
            if(dummy->val == elem){
                pos = currpos;
                break;
            }
            currpos++;
            dummy = dummy->next;
        }
        return pos;
    }
    int getSize(){
        return currnodes;
    }
    bool isEmpty(){
        if(currnodes == 0) return true;
        return false;
    }
    int printElemBeforePos(int pos){
        if(pos == 1){
            cout << "No element exist before position 1"<< endl;
            exit(100);
        }
        Node<T> * dummy = head;
        for(int i = 2 ; i<pos ; i++){
            dummy = dummy->next;
        }
        return dummy->val;
    }
    int printElemAfterPos(int pos){
        if(pos == currnodes){
            cout << "No element exist after end position"<< endl;
            exit(100);
        }
        Node <T>* dummy = head;
        for(int i = 2 ; i<=pos+1 ; i++){
            dummy = dummy->next;
        }
        return dummy->val;
    }
    void concatenate(LinkedList & l){
        tail->next = l.head;
        l.head->prev = tail;
        l.tail->next = NULL;
        tail = l.tail;
        currnodes +=l.currnodes;
    }
    void printmiddle(){
        Node<T> * c1 = head;
        Node<T> * c2 = tail;
        if(getSize()%2==1){
            while(c1 != c2){
                c1 = c1->next;
                c2 = c2->prev;
            }
            cout << c2->val;
        }
        else{
            while(c1->next != c2){
                c1 = c1->next;
                c2 = c2->prev;
            }
            cout << c2->val;
        }
    }
};
