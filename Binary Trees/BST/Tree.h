#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
class TreeNode{
    public:
        int value;
        TreeNode * right;
        TreeNode * left;
        TreeNode(int val){
            value = val;
            right = NULL;
            left = NULL;
        }
        TreeNode(int val , TreeNode * left , TreeNode * right){
            value = val;
            this->left = left;
            this->right = right;
        }
};
class BST{
    private:
        void recursiveLevelOrderHelper(int i , TreeNode * root);
    public:
    TreeNode * root;
    BST(){
        root = NULL;
    }
    void insert(int val);
    void insert(vector<int> v);
    void levelOrder();
    void recursiveLevelOrder();
    
    void preOrder(TreeNode * root);
    void iterativePreOrder();
    void inOrder(TreeNode * root);
    void iterativeInOrder();
    void postOrder(TreeNode * root);
    void iterativePostOrder();
    TreeNode * searchNode(int value);
    int height(TreeNode * root);
};

void BST :: insert(int val){
    TreeNode * node = new TreeNode(val);
    if(root == NULL){
        root = node;
    }
    else{
        TreeNode * temp = root;
        TreeNode * prev = temp;
        while(temp){
            prev = temp;
            if(temp->value >= node->value){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        if(prev->value >= node->value){
            prev->left = node;
        }
        else{
            prev->right = node;
        }
    }
}

void BST :: insert(vector<int> v){
    for(int i : v){
        insert(i);
    }
}

void BST :: levelOrder(){
    queue<TreeNode *> q;
    if(root!=NULL){
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode * temp = q.front();
                q.pop();
                cout << temp->value << " ";
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            cout << endl;
        }
    }
}
void BST :: recursiveLevelOrder(){
    int height = this->height(root);
    for(int i = 1 ; i<=height ; i++){
        recursiveLevelOrderHelper(i , root);
        cout << endl;
    }
}
void BST :: recursiveLevelOrderHelper(int i , TreeNode * root){
    if(root == NULL) return;
    if(i == 1){
        cout << root->value <<" ";
        return;
    }
    else{
        recursiveLevelOrderHelper(i-1 , root->left);
        recursiveLevelOrderHelper(i-1 , root->right);
    }
}
void BST :: preOrder(TreeNode * root){
    if(root == NULL) return;
    cout << root->value << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void BST :: iterativePreOrder(){
    stack<TreeNode *> s;
    if(root){
        s.push(root);
        while(!s.empty()){
            TreeNode * top = s.top();
            s.pop();
            cout << top->value << " ";
            if(top->right) s.push(top->right);
            if(top->left) s.push(top->left);
        }
    }
}
void BST :: inOrder(TreeNode * root){
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->value << " ";
    inOrder(root->right);
}
void BST :: iterativeInOrder(){
    stack<TreeNode *> s;
    if(root){
        TreeNode * temp = root;
        while(true){
            if(temp){
                s.push(temp);
                temp = temp->left;
            }
            else{
                if(s.empty()) break;
                temp = s.top();
                s.pop();
                cout << temp->value << " ";
                temp = temp->right;
            }
        }
    }
}
void BST :: postOrder(TreeNode * root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->value << " ";
}
void BST :: iterativePostOrder(){
    // *****************************************using 2 stacks*****************************************
    // stack<TreeNode *> s1,s2;
    // s1.push(root);
    // while(!s1.empty()){
    //     TreeNode * temp = s1.top();
    //     s1.pop();
    //     s2.push(temp);
    //     if(temp->left) s1.push(temp->left);
    //     if(temp->right) s1.push(temp->right);
    // }
    // while(!s2.empty()){
    //     cout << s2.top()->value << " ";
    //     s2.pop();
    // }

    //******************************************using 1 stack******************************************
    
}
TreeNode * BST :: searchNode(int value){
    TreeNode * temp =  root;
    while(temp){
        if(temp->value == value){
            return temp;
        }
        else if(temp->value > value){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return NULL;
}
int BST :: height(TreeNode * root){
    if(!root) return 0;
    return 1 + max(height(root->right) , height(root->left));
}