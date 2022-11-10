#include <iostream>
#include "D:\vs code mayank\Data Structures\Heaps\maxheap\MaxHeap.h"
using namespace std;
class MaxPriorityQueue{
    public:
    MaxHeap mp = MaxHeap(1000);
    int size(){
        return mp.size();
    }
    void enque(int val){
        mp.insert(val);
    }
    void dequeue(){
        mp.remove();
    }
    int front(){
        return mp.extractMax();
    }
};