#include <iostream>
#include "stack.h"
using namespace std;
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.rotate(0);
    s.traverse();
}
