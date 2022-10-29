#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <sstream>
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
        //This section contains all the helper functions which help other main functions to do their tasks.
        void recursiveLevelOrderHelper(int i , TreeNode * root);
        TreeNode * deleteByPredecessorHelper(TreeNode * node);
        TreeNode * deleteBySuccessorHelper(TreeNode * node);
        bool deleteByCopyingflag = 0;
        void deleteByCopyingHelper(int key);
        TreeNode * prevLL = NULL;
    public:
        BST(){}
        BST(TreeNode * root){
            this->root = root;
        }
        TreeNode * root = NULL;
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
        void verticalOrderTraversal();
        void topView();
        void bottomView();
        void leftView();
        void rightView();
        TreeNode * searchNode(int value);
        int height(TreeNode * root);
        int maxWidth();
        TreeNode * successor(TreeNode * node);
        TreeNode * predecessor(TreeNode * node);
        void deleteByPredecessor(int key);
        void deleteBySuccessor(int key);
        void deleteByCopying(int key);
        TreeNode * leastCommonAncestor(TreeNode * root , int key1 , int key2);
        void nodesAtDistanceK(int target , int k); //starting from the node whose value is target print all other nodes which are at a distance K from it.
        string serialise();
        friend TreeNode * deserialise(string str);
        void flattenTreeInLL(TreeNode * root);
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
void BST :: verticalOrderTraversal(){
    queue<pair<TreeNode * , pair<int,int>>> q;
    map<int,map<int,multiset<int>>> mp;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int vertical = front.second.first;
        int level = front.second.second;
        mp[vertical][level].insert(front.first->value);
        if(front.first->left) q.push({front.first->left , {vertical-1 , level+1}});
        if(front.first->right) q.push({front.first->right , {vertical+1 , level+1}});
    }
    for(auto vertical : mp){
        for(auto level : vertical.second){
            for(auto val : level.second){
                cout << val << " ";
            }
        }
        cout << endl;
    }
}
void BST :: topView(){
    queue<pair<TreeNode* , int>> q;
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        if(!mp[front.second]){
            mp[front.second] = front.first->value;
        }
        if(front.first->left) q.push({front.first->left , front.second-1});
        if(front.first->right) q.push({front.first->right , front.second+1});
    }
    for(auto i : mp){
        cout << i.second << " ";
    }
}
void BST :: bottomView(){
    queue<pair<TreeNode* , int>> q;
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        mp[front.second] = front.first->value;
        if(front.first->left) q.push({front.first->left , front.second-1});
        if(front.first->right) q.push({front.first->right , front.second+1});
    }
    for(auto i : mp){
        cout << i.second << " ";
    }
}
void BST :: leftView(){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0 ; i<sz ; i++){
            TreeNode * temp = q.front();
            q.pop();
            if(i==0){
                cout << temp->value << " ";
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}
void BST :: rightView(){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0 ; i<sz ; i++){
            TreeNode * temp = q.front();
            q.pop();
            if(i==sz-1){
                cout << temp->value << " ";
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
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
int BST :: maxWidth(){
    queue<pair<TreeNode * , int>> q;
    q.push({root,0});
    int maxi = 1;
    while(!q.empty()){
        int sz = q.size();
        int first , last;
        int mini = q.front().second;
        for(int i = 1 ; i<=sz ; i++){
            TreeNode * temp = q.front().first;
            int curr = q.front().second - mini;
            q.pop();
            if(i == 1) first = curr;
            if(i == sz) last = curr;
            if(temp->left) q.push({temp->left , 2*curr+1});
            if(temp->right) q.push({temp->right , 2*curr+2});
        }
        maxi = max(maxi , last-first+1);
    }
    return maxi;
}
TreeNode * BST :: successor(TreeNode * node){
    if(!node->right) return node;
    node = node->right;
    while(node->left){
        node = node->left;
    }
    return node;
}
TreeNode * BST :: predecessor(TreeNode * node){
    if(!node->left) return node;
    node = node->left;
    while(node->right){
        node = node->right;
    }
    return node;
}
TreeNode * BST :: deleteByPredecessorHelper(TreeNode * node){
    if(!node->left && !node->right){
        return NULL;
    }
    if(!node->left){
        return node->right;
    }
    TreeNode * ans = predecessor(node);
    ans->right = node->right;
    return node->left;
}
void BST :: deleteByPredecessor(int key){
    if(key == root->value){
        root = deleteByPredecessorHelper(root);
    }
    TreeNode * temp = root;
    while(temp){
        if(temp->value < key){
            if(temp->right && temp->right->value == key){
                temp->right = deleteByPredecessorHelper(temp->right);
                break;
            }
            else{
                temp = temp->right;
            }
        }
        else{
            if(temp->left && temp->left->value == key){
                temp->left = deleteByPredecessorHelper(temp->left);
                break;
            }
            else{
                temp = temp->left;
            }
        }
    }
}
TreeNode * BST :: deleteBySuccessorHelper(TreeNode * node){
    if(!node->left && !node->right){
        return NULL;
    }
    if(!node->right){
        return node->left;
    }
    TreeNode * ans = successor(node);
    ans->left = node->left;
    return node->right;
}
void BST :: deleteBySuccessor(int key){
    TreeNode * temp = root;
    if(key == root->value){
        root = deleteBySuccessorHelper(root);
    }
    while(temp){
        if(temp->value < key){
            if(temp->right && temp->right->value == key){
                temp->right = deleteBySuccessorHelper(temp->right);
                break;
            }
            else{
                temp = temp->right;
            }
        }
        else{
            if(temp->left && temp->left->value == key){
                temp->left = deleteBySuccessorHelper(temp->left);
                break;
            }
            else{
                temp = temp->left;
            }
        }
    }
}
void BST :: deleteByCopyingHelper(int key){
    TreeNode * temp = root;
    while(temp){
        if(temp->value > key){
            if(temp->left && temp->left->value == key){
                temp->left = NULL;
                break;
            }
            else{
                temp = temp->left;
            }
        }
        else{
            if(temp->right && temp->right->value == key){
                // cout << temp->value <<" " <<temp->right->value << " " << key << endl;
                temp->right = NULL;
                break;
            }
            else{
                temp = temp->right;
            }
        }
    }
}
void BST :: deleteByCopying(int key){
    TreeNode * del = searchNode(key);
    if(deleteByCopyingflag == 0){
        TreeNode * pred;
        //following condition checks if node to be deleted have less than 2 child or not also it manages to delete the leaf node
        if(!del->left) pred = successor(del); // if it dont have left child then we cant find the predecessor
        else pred = predecessor(del);//it it has left child then find predecessor
        deleteByCopyingHelper(pred->value);
        del->value = pred->value;
        deleteByCopyingflag = 1;
    }
    else{
        TreeNode * succ;
        if(!del->right) succ = predecessor(del); // cannot find successor.
        else succ = successor(del); //successor exists
        deleteByCopyingHelper(succ->value);
        del->value = succ->value;
        deleteByCopyingflag = 0;
    }
    //It could have been done by keeping 2 separate checks for leaf and one child nodes, but I have made it pure copying based ,for leaf nodes its simple, but for one child nodes it deletes by copying not by simply remove the node.
}
TreeNode * BST :: leastCommonAncestor(TreeNode * root , int key1 , int key2){
    // we are using dfs(preorder) here
    if(!root || root->value == key1 || root->value == key2){
        return root;
    }
    TreeNode * l = leastCommonAncestor(root->left , key1 , key2);
    TreeNode * r = leastCommonAncestor(root->right , key1 , key2);
    if(!l) return r;
    else if(!r) return l;
    else return root;
}
void BST :: nodesAtDistanceK(int target , int k){
    map<TreeNode * , TreeNode *> parent;
    queue<TreeNode * > q;
    q.push(root);
    while(!q.empty()){
        TreeNode * front = q.front();
        q.pop();
        if(front->left){
            q.push(front->left);
            parent[front->left] = front;
        }
        if(front->right){
            q.push(front->right);
            parent[front->right] = front;
        }
    }
    TreeNode * search = searchNode(target);
    map<int,bool> visited;
    visited[search->value] = 1;
    q.push(search);
    while(!q.empty() && k--){
        int sz = q.size();
        while(sz--){
            TreeNode * front = q.front();
            q.pop();
            if(front->left && !visited[front->left->value]){
                q.push(front->left);
                visited[front->left->value] = 1;
            }
            if(front->right && !visited[front->right->value]){
                q.push(front->right);
                visited[front->right->value] = 1;
            }
            if(parent[front] && !visited[parent[front]->value]){
                q.push(parent[front]);
                visited[parent[front]->value] = 1;
            }
        }
    }
    while(!q.empty()){
        cout << q.front()->value <<" ";
        q.pop();
    }
    cout << endl;
}
string BST :: serialise(){
    queue<TreeNode *> q;
    string ans = "";
    if(!root) return "";
    q.push(root);
    while(!q.empty()){
        TreeNode * front = q.front();
        q.pop();
        if(!front) ans += "N ";
        else{
            ans += to_string(front->value) + " ";
            q.push(front->left);
            q.push(front->right);
        }
    }
    return ans;
}
TreeNode * deserialise(string str){
    if(str=="") return NULL;
    stringstream s(str);
    string num;
    s >> num;
    TreeNode * root = new TreeNode(stoi(num));
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        TreeNode * front = q.front();
        q.pop();
        s >> num;
        if(num == "N"){
            front->left = NULL;
        }
        else{
            front->left = new TreeNode(stoi(num));
            q.push(front->left);
        }
        s >> num;
        if(num == "N"){
            front->right = NULL;
        }
        else{
            front->right = new TreeNode(stoi(num));
            q.push(front->right);
        }
    }
    return root;
}
void BST :: flattenTreeInLL(TreeNode * root){
    //flatten the tree such that is appears as a preorder traveral where all nodes are at right and left pointers are NULL;
    //approach 1-> Using RLV traversal;
    if(!root) return;
    flattenTreeInLL(root->right);
    flattenTreeInLL(root->left);
    //The node whose RLV is completed just assign the prev to that node and assign the right of that node to the prev
    root->right = prevLL;
    root->left = NULL;
    prevLL = root;
}