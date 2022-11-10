#include <iostream>
using namespace std;
class MinHeap{
    public:
        int * heap;
        int curr = 1;
        MinHeap(){}
        MinHeap(int size){
            heap = new int[size+1];
        }
        MinHeap(int heap[] , int size);//this will take the heapay and heapify it
        void insert(int val);
        void traverse();
        int extractMin();
        void remove();
        int size();
        void heapify(int index);
        void remove(int val);
};
void MinHeap :: heapify(int index){
    int left = index*2;
    int right = index*2+1;
    while(true){
        if(left < curr && heap[left] < heap[index] && heap[left] < heap[right]){
            swap(heap[index],heap[left]);
            index = left;
        }
        else if(right < curr && heap[right] < heap[index] && heap[right] < heap[left]){
            swap(heap[index],heap[right]);
            index = right;
        }
        else break;
        left = 2*index;
        right = 2*index+1;
    }
}
MinHeap :: MinHeap(int arr[] , int size){
    curr = size + 1;
    heap = new int[curr];
    for(int i = 0 ; i<size ; i++){
        heap[i+1] = arr[i];
    }
    delete(arr);
    for(int i = size/2 ; i >= 1 ; i--){
        heapify(i);
    }
}
void MinHeap :: insert(int val){
    if(curr == 1){
        heap[curr++] = val;
    }
    else{
        heap[curr] = val;
        int pos = curr;
        curr++;
        while(pos > 1 && heap[pos/2] > val){
            swap(heap[pos/2] , heap[pos]);
            pos/=2;
        }
    }
}
void MinHeap :: traverse(){
    for(int i= 1 ; i<curr ; i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}
int MinHeap :: extractMin(){
    return heap[1];
}
int MinHeap :: size(){
    return curr-1;
}
void MinHeap :: remove(){
    if(size() == 0){
        cout << "Nothing to delete" << endl;
        return;
    }
    int pos = 1;
    heap[1] = heap[--curr];
    int left = pos*2;
    int right = pos*2+1;
    while(true){
        /*edge case need to be taken care of - when the heap[pos] is smaller than both left and right value, in that 
        case take the max of left and right and swap with the heap[pos](when the left is greater than the heap[pos] 
        but it is less than the right so if we dont take care of it right child remains smaller than the parent even 
        after swapping the parent with left. example - [40,30,35,20,15] remove(40))*/
        if(left < curr && heap[left] < heap[pos] && heap[left] < heap[right]){
            swap(heap[pos],heap[left]);
            pos = left;
        }
        else if(right < curr && heap[right] < heap[pos] && heap[right] < heap[left]){
            swap(heap[pos],heap[right]);
            pos = right;
        }
        else break;
        left = 2*pos;
        right = 2*pos+1;
    }
}
void MinHeap :: remove(int val){
    int pos;
    for(int i = 1 ; i < curr ; i++){
        if(heap[i] == val){
            pos = i;
            break;
        }
    }
    heap[pos] = heap[--curr];
    int left = pos*2;
    int right = pos*2+1;
    while(true){
        if(left < curr && heap[left] < heap[pos] && heap[left] < heap[right]){
            swap(heap[pos],heap[left]);
            pos = left;
        }
        else if(right < curr && heap[right] < heap[pos] && heap[right] < heap[left]){
            swap(heap[pos],heap[right]);
            pos = right;
        }
        else break;
        left = 2*pos;
        right = 2*pos+1;
    }
}