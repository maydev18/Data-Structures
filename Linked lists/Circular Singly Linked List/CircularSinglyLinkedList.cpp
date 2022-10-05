#include <iostream>
#include "CircularSinglyLinkedList.h"
using namespace std;
int main(){
    LinkedList <int> l,l1;
    int choice = 1;
    do{
        Node<int> * node = new Node<int>();
        int userChoice,pos,val,elem;
        cout << "1. Insert an element at head \n";
        cout << "2. Insert an element at tail \n";
        cout << "3. Insert an element at a position \n";
        cout << "4. Delete an element at head \n";
        cout << "5. Delete an element at tail \n";
        cout << "6. Delete an element at a position \n";
        cout << "7. Search for an element in Linked List \n";
        cout << "8. Print size of linked list \n";
        cout << "9. Print linked list \n";
        cout << "10. Print element before a position \n";
        cout << "11. Print element after a position \n";
        cout << "12. Check if list is empty or not \n";
        cout << "13. Concatenate \n";
        cout << "14. Exit \n";
        cout << "Enter your choice: ";
        cin >> userChoice;
        switch (userChoice)
        {
        case 1:
            cout << "enter the value of node : ";
            cin >> node->val;
            l.insert(node , 1);
            break;
        case 2:
            cout << "enter the value of node : ";
            cin >> node->val;
            l.insert(node , l.currnodes+1);
            break;
        case 3:
            cout << "enter the value of node : ";
            cin >> node->val;
            cout << "enter the position : ";
            cin >> pos;
            l.insert(node,pos);
            break;
        case 4:
            l.deleteNode(1);
            break;
        case 5:
            l.deleteNode(l.currnodes);
            break;
        case 6:
            cout << "enter the position : ";
            cin >> pos;
            l.deleteNode(pos);
            break;
        case 7:
            cout << "enter the node value to be searched: ";
            cin >> val;
            pos = l.searchElem(val);
            if(pos == -1){
                cout << "Element not found!!"<< endl;
            }
            else{
                cout << "Element found at position: " << pos << endl;
            }
            break;
        case 8:
            cout << "The size of linked list is: " << l.getSize();
            break;
        case 9:
            l.traverse();
            break;
        case 10:
            cout << "Enter the position: ";
            cin >> pos;
            cout << l.printElemBeforePos(pos);
            break;
        case 11:
            cout << "Enter the position: ";
            cin >> pos;
            cout << l.printElemAfterPos(pos);
            break;
        case 12:
            l.isEmpty()?cout << "List is empty"<<endl:cout <<"List is not empty"<<endl;
            break;
        case 13:
            cout << "Enter the number of elements in the list to be concatenated: ";
            cin >> val;
            pos = 1;
            while(pos <= val){
                cout << "enter the value of " << pos << " node: ";
                cin >> elem;
                node = new Node<int>(elem);
                l1.insert(node,pos);
                pos++;
            }
            l.concatenate(l1);
            break;
        case 14:
            choice = 0;
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Wrong choice entered, Exiting program!!!"<<endl;
            choice = 0;
        }
        cout << endl<<endl;
    }while(choice);
    return 0;
}