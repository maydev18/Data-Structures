#include <iostream>
#include "D:\vs code mayank\Data Structures\Heaps\minheap\MinHeap.h"
using namespace std;
class MinPriorityQueue{
    public:
    MinHeap mp = MinHeap(1000);
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
        return mp.extractMin();
    }
};