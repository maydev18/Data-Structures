#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Notation{
    public:
        void reverse(string & s){
            int n  = s.size();
            for(int i = 0 ; i < n/2 ; i++){
                char temp = s[i];
                s[i] = s[n-i-1];
                s[n-i-1] = temp;
            }
        }
        bool precedence(char top , char ch){
            if(top == '$' && ch =='$') return false;

            else if(top == '$') return true; 

            else if(ch == '$') return false;

            else if((top == '/' || top == '*') && (ch == '/' || ch == '*')){
                return false;
            }
            else if((top == '+' || top == '-') && (ch == '+' || ch == '-')){
                return false;
            }
            else if((top == '/' || top == '*') && (ch == '+' || ch == '-')){
                return true;
            }
            else{
                return false;
            }
        }
        string infixToPostfix(string infix){
            string postfix = "";
            stack<char> stk;
            int i = 0;
            while(i < infix.size()){
                if(infix[i] >= 'A' && infix[i] <= 'Z'){
                    postfix.push_back(infix[i]);
                }
                else{
                    if(infix[i] == '('){
                        stk.push(infix[i]);
                    }
                    else if(infix[i] == ')'){
                        while(stk.top()!='('){
                            postfix.push_back(stk.top());
                            stk.pop();
                        }
                        stk.pop();
                    }
                    //else it is a operator
                    else{
                        if(stk.empty()){
                            stk.push(infix[i]);
                        }
                        else{
                            // we only pop when the precedence is greater else just keep pushing
                            while(stk.size() && precedence(stk.top() , infix[i])){
                                postfix.push_back(stk.top());
                                stk.pop();
                            }
                            stk.push(infix[i]);
                        }
                    }
                }
                i++;
            }
            while(!stk.empty()){
                postfix.push_back(stk.top());
                stk.pop();
            }
            return postfix;
        }
        string infixToPrefix(string infix){
            reverse(infix);
            string postfix = infixToPostfix(infix);
            reverse(postfix);
            return postfix;
        }
};
int main(){
    Notation n;
    cout << n.infixToPrefix("X+Y*Z/W+U");
    return 0;
}