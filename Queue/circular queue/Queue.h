#include <iostream>
using namespace std;
class Queue{
    public:
        int arr[5] = {0};
        int size = 0;
        int front = 0;
        int rear = 0;
        void push(int val);
        void display();
        void pop();
        int top();
};
void Queue :: push(int val){
    if(size == 5){
        cout << "overflow" << endl;
        return;
    }
    arr[rear] = val;
    rear = (rear+1)%5;
    size++;
}
void Queue :: pop(){
    if(size == 0){
        cout << "Underflow" << endl;
        return;
    }
    cout << "popped element is: " << arr[front] << endl;
    front = (front+1)%5;
    size--;
}
void Queue::display(){
    int temp = size;
    int curr = front;
    while(temp>0){
        cout << arr[curr] <<" ";
        curr = (curr+1)%5;
        temp--;
    }
    cout << endl;
}
int Queue::top(){
    return arr[rear-1];
}

