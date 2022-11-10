#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(){
        val = 0;
        next = NULL;
    }
    Node(int val){
        this->val = val;
        next = NULL;
    }
    Node(int val , Node*next){
        this->val = val;
        this->next = next;
    }
};
class LinkedList{
    public:
    Node * head;
    Node * tail;
    int currnodes = 0;
    LinkedList(){
        head = NULL;
        tail = NULL;
        currnodes = 0;
    }
    LinkedList(Node*n){
        currnodes = 1;
        head = n;
        tail = n;
    }
    void traverse(){
        Node *dummy = head;
        while(dummy){
            cout << dummy->val<<" ";
            dummy = dummy->next;
        }
        cout << endl;
    }
    void insert(int val , int pos){
        Node * n = new Node(val);
        if(pos == 1){
            if(currnodes == 0){
                head = n;
                tail = n;
            }
            else{
                n->next = head;
                head = n;
            }
        }
        else if(pos == currnodes+1){
            n->next = NULL;
            tail->next = n;
            tail = n;
        }
        else{
            Node * prev = head;
            for(int i = 2 ; i<pos ; i++){
                prev = prev->next;
            }
            n->next = prev->next;
            prev->next = n;
        }
        currnodes++;
    }
    void deleteNode(int pos){
        if(pos == 1){
            head = head->next;
        }
        else{
            Node * prev = head;
            for(int i = 2 ; i<pos ; i++){
                prev = prev->next;
            }
            if(pos == currnodes){
                prev->next = NULL;
                tail = prev;
            }
            else{
                Node * curr = prev->next;
                prev->next = curr->next;
            }
        }
        currnodes--;
    }
    int searchElem(int elem){
        int pos = -1;
        Node * dummy = head;
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
        Node * dummy = head;
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
        Node * dummy = head;
        for(int i = 2 ; i<=pos+1 ; i++){
            dummy = dummy->next;
        }
        return dummy->val;
    }
    void concatenate(LinkedList & l){
        tail->next = l.head;
        l.tail->next = NULL;
        tail = l.tail;
        currnodes += l.currnodes;
    }
};
