#include <iostream>
#include <stack>
using namespace std;
bool isValid(string s) {
    stack<char> stk;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            stk.push(s[i]);
        }
        else{
            if(stk.empty()) return false;
            if(s[i] == ')' && stk.top()=='('){
                stk.pop();
            }
            else if(s[i] == '}' && stk.top()=='{'){
                stk.pop();
            }
            else if(s[i] == ']' && stk.top()=='['){
                stk.pop();
            }
            else{
                return false;
            }
        }
    }
    if(stk.empty()){
        return true;
    }
    else return false;
}
int main(){
    string valid = "[(({{}}))]";
    string invalid = "(())}}()";
    cout << isValid(valid) << endl;
    cout << isValid(invalid) << endl;
}