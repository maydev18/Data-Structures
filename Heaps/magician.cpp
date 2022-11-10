#include <iostream>
#include "D:\vs code mayank\Data Structures\Linked lists\singly linked list\singlylinkedlist.h"
using namespace std;
class Magic{
    public:
        LinkedList arr[20];
        int getMiddleDigits(int val){
            val/=10;
            int num = val%10;
            val/=10;
            num += 10*(val%10);
            return num;
        }
        void insert(int val){
            int num = getMiddleDigits(val);
            arr[num%20].insert(val,arr[num%20].getSize()+1);
        }
        void search(int val){
            int num = getMiddleDigits(val);
            int pos = arr[num%20].searchElem(val);
            if(pos == -1){
                cout << "element not found" << endl;
            }
            else{
                cout << "element found at " <<num%20 << " index and at position " << pos << endl;
            }
        }
        void print(){
            for(int i= 0 ; i<20 ; i++){
                cout << i << "  | ";
                arr[i].traverse();
            }
        }
};
int main(){
    Magic m;
    m.insert(1206);
    m.insert(7822);
    m.insert(6467);
    m.insert(8990);
    m.insert(1211);
    m.insert(4444);
    m.insert(6701);
    m.insert(5468);
    m.insert(7345);
    m.insert(8210);
    m.print();
    m.search(8210);
    return 0;
}