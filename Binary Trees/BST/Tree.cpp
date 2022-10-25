#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;
int main(){
    BST bst;
    vector<int> v = {5,8,2,4,10,6,24,9};
    bst.insert(v);
    // cout << bst.height(bst.root);
    // bst.recursiveLevelOrder();
    // bst.inOrder(bst.root);
    // bst.iterativeInOrder();
    bst.postOrder(bst.root);
    cout << endl;
    bst.iterativePostOrder();
    cout << endl;
    return 0;
}