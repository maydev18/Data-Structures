#include <iostream>
#include <vector>
using namespace std;
class MaxHeap{
    public:
        int * heap;
        int curr = 1;
        MaxHeap(){}
        MaxHeap(int size){
            heap = new int[size+1];
        }
        MaxHeap(int heap[] , int size);//this will take the heapay and heapify it
        void insert(int val);
        void traverse();
        int extractMax();
        void remove();
        void remove(int val);
        int size();
        void heapify(int index);
};
void MaxHeap :: heapify(int index){
    int left = index*2;
    int right = index*2+1;
    while(true){
        if(left < curr && heap[left] > heap[index] && heap[left] > heap[right]){
            swap(heap[index],heap[left]);
            index = left;
        }
        else if(right < curr && heap[right] > heap[index] && heap[right] > heap[left]){
            swap(heap[index],heap[right]);
            index = right;
        }
        else break;
        left = 2*index;
        right = 2*index+1;
    }
}
MaxHeap :: MaxHeap(int arr[] , int size){
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
void MaxHeap :: insert(int val){
    if(curr == 1){
        heap[curr++] = val;
    }
    else{
        heap[curr] = val;
        int pos = curr;
        curr++;
        while(pos > 1 && heap[pos/2] < val){
            int temp = heap[pos/2];
            heap[pos/2] = val;
            heap[pos] = temp;
            pos/=2;
        }
    }
}
void MaxHeap :: traverse(){
    for(int i= 1 ; i<curr ; i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}
int MaxHeap :: extractMax(){
    return heap[1];
}
int MaxHeap :: size(){
    return curr-1;
}
void MaxHeap :: remove(){
    if(size() == 0){
        cout << "Nothing to delete" << endl;
        return;
    }
    int pos = 1;
    heap[1] = heap[--curr];
    int left = pos*2;
    int right = pos*2+1;
    while(true){
        if(left < curr && heap[left] > heap[pos] && heap[left] > heap[right]){
            swap(heap[pos],heap[left]);
            pos = left;
        }
        else if(right < curr && heap[right] > heap[pos] && heap[right] > heap[left]){
            swap(heap[pos],heap[right]);
            pos = right;
        }
        else break;
        left = 2*pos;
        right = 2*pos+1;
    }
}
void MaxHeap :: remove(int val){
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
        if(left < curr && heap[left] > heap[pos] && heap[left] > heap[right]){
            swap(heap[pos],heap[left]);
            pos = left;
        }
        else if(right < curr && heap[right] > heap[pos] && heap[right] > heap[left]){
            swap(heap[pos],heap[right]);
            pos = right;
        }
        else break;
        left = 2*pos;
        right = 2*pos+1;
    }
}