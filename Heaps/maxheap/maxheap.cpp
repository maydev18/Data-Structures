#include <iostream>
#include "MaxHeap.h"
using namespace std;
int main(){
    int arr[] = {5 , 10 , 30 , 20 , 70 , 90 , 60 , 50 , 80};
    MaxHeap mp(arr , 9);
    mp.insert(85);
    mp.traverse();
    mp.remove(60);
    mp.traverse();
    return 0;
}