#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue<int> q;//max heap
    queue<int> r;
    q.push(34);
    q.push(23);
    q.push(12);
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    cout << q.size() << endl;
    cout << q.empty()<<endl;
    cout << endl << endl;

    priority_queue <int, vector<int>, greater<int>> p;  //min heap
    p.push(34);
    p.push(23);
    p.push(12);
    cout << p.top() << endl;
    p.pop();
    cout << p.top() << endl;
    cout << p.size() << endl;
    cout << p.empty()<<endl;
    return 0;
}