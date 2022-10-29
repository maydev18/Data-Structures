#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;
int main(){
    BST bst;
    vector<int> v = {5,4,10,7,20,6,8,15,25};
    bst.insert(v);
    bst.flattenTreeInLL(bst.root);
    bst.levelOrder();
    return 0;    
}