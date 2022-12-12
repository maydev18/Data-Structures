#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
    Node(){
        key = 0;
        left = NULL;
        right = NULL;
        height = 0;
    }
    Node(int key){
        this->key = key;
        left =  NULL;
        right = NULL;
        height = 1;
    }
};
class Tree
{
    public:
    Node * root = NULL;
    int odd = 0 , even = 0;
    int height(Node *N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;
        y->height = max(height(y->left) , height(y->right)) + 1;
        x->height = max(height(x->left) , height(x->right)) + 1;
        return x;
    }
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;
        x->height = max(height(x->left) , height(x->right)) + 1;
        y->height = max(height(y->left) , height(y->right)) + 1;
        return y;
    }

    int getBalance(Node *N)
    {
        if (N == NULL) return 0;
        return height(N->left) - height(N->right);
    }

    Node *insert(Node *node, int key)
    {
        if (node == NULL)
            return (new Node(key));

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;
        node->height =1 + max(height(node->left) , height(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // Right Left Case
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    void levelorder(){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                Node * top = q.front();
                q.pop();
                cout << top->key << " ";
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            cout << endl;
        }
    }
    void inorder(Node * root){
        if(!root) return;
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
    int numnodes(Node * temp , int a , int b){
        if(!temp) return 0;
        if(temp->key > b){
            return numnodes(temp->left , a , b);
        }
        else if(temp->key < a){
            return numnodes(temp->right , a , b);
        }
        else{
            return numnodes(temp->right , a , b) + numnodes(temp->left ,a ,b) + 1;
        }
    }
    void diff(Node * temp , int level){
        if(!temp) return;
        if(level&1){
            odd += temp->key;
            diff(temp->left , level+1);
            diff(temp->right , level+1);
        }
        else{
            even += temp->key;
            diff(temp->left , level+1);
            diff(temp->right , level+1);
        }
    }
};
int search(int low , int high , int key ,int arr[]){
    if(low > high) return -1; //not found;
    int mid1 = low + (high-low)/3;
    int mid2 = high - (high-low)/3;
    if(arr[mid1] == key) return mid1;
    if(arr[mid2] == key) return mid2;
    if(arr[mid1] > key){
        return search(low , mid1-1 , key , arr);
    }
    else if(arr[mid2] < key){
        return search(mid2+1 , high , key , arr);
    }
    else{
        return search(low+1 , high-1 , key , arr);
    }
}
int main()
{
    // Tree tree;
    // tree.root = new Node(14);
    // tree.root = tree.insert(tree.root, 17);
    // tree.root = tree.insert(tree.root, 11);
    // tree.root = tree.insert(tree.root, 7);
    // tree.root = tree.insert(tree.root, 53);
    // tree.root = tree.insert(tree.root, 4);
    // tree.root = tree.insert(tree.root, 13);
    // tree.root = tree.insert(tree.root, 12);
    // tree.root = tree.insert(tree.root, 8);
    // tree.root = tree.insert(tree.root, 60);
    // tree.root = tree.insert(tree.root, 19);
    // tree.root = tree.insert(tree.root, 16);
    // tree.root = tree.insert(tree.root, 20);
    // tree.levelorder();
    // cout << tree.numnodes(tree.root , 10,20);
    // tree.diff(tree.root , 1);
    // cout << abs(tree.odd - tree.even);
    int arr [] = {1,2,3,4,5,6,7,8,9};
    cout << search(0 , 8 ,34 , arr);
    return 0;
}
