#include <iostream>
#include "Queue.h"
using namespace std;
int main(){
    Queue q;
    int val , user = 1;
    do{
        int choice;
        cout << "1. push\n";
        cout << "2. pop\n";
        cout << "3. display\n";
        cout << "4. Show Top\n";
        cout << "5. Exit\n";
        cout << "your choice : ";
        cin >> choice ;
        switch(choice){
            case 1:
                cout << "Enter the element: ";
                cin >> val;
                q.push(val);
                break;
            case 2: 
                q.pop();
                break;
            case 3:
                q.traverse();
                break;
            case 4:
                if(q.list.currnodes==0){
                    cout << "Queue is empty"<<endl;
                }
                else{
                    cout <<"Top element is : " << q.top()<<endl;
                }
                break;
            case 5:
                user = 0;
                cout << "exiting program !"<<endl;
                break;
            default :
                cout << "Wrong choice entered "<<endl;
                cout <<"Exiting program "<<endl;
                user = 0;
        }
        cout << endl<<endl;
    }while(user);
}