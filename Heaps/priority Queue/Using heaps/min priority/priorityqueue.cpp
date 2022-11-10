#include <iostream>
#include "MinPriorityQueue.h"
using namespace std;
int main(){
    MinPriorityQueue q;
    q.enque(5);
    q.enque(10);
    q.enque(6);
    q.enque(20);
    q.enque(15);
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    cout << q.size() << endl;
    return 0;
}