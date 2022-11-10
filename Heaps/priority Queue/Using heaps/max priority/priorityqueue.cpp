#include <iostream>
#include "MaxPriorityQueue.h"
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    MaxPriorityQueue q;
    q.enque(5);
    q.enque(10);
    q.enque(6);
    q.enque(20);
    q.enque(15);
    return 0;
}