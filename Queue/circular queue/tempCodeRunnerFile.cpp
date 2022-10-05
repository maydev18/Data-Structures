int val , user = 1;
    do{
        int choice;
        cout << "1. push\n";
        cout << "2. pop\n";
        cout << "3. display\n";
        cout << "4. Exit\n";
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
                cout << "element popped"<<endl;
                break;
            case 3:
                q.display();
                break;
            case 4:
                user = 0;
                cout << "exiting program !"<<endl;
                break;
            default :
                cout << "Wrong choice entered "<<endl;
                cout <<"Exiting program "<<endl;
                user = 0;
        }
    }while(user);