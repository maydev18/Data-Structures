#include <iostream>
#include "MinHeap.h"
using namespace std;
int main(){
    int arr[] = {20,25,10,4,30,36,40,22,28};
    MinHeap mp(arr , 9);
    mp.traverse();
    mp.remove(40);
    mp.traverse();
}