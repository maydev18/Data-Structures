#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Notation{
    public:
        bool precedence(char top , char ch){
            if(top == '$' && ch =='$') return true;

            else if(top == '$') return true; 

            else if(ch == '$') return false;

            else if((top == '/' || top == '*') && (ch == '/' || ch == '*')){
                return true;
            }
            else if((top == '+' || top == '-') && (ch == '+' || ch == '-')){
                return true;
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
                            //if here precedence is same then we also pops
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
};
int main(){
    Notation n;
    // cout << n.infixToPostfix("((A-(B+C))*D)$(E+F)");
    // cout << n.infixToPostfix("((A-(B/C))*((A/K)-L))");
    cout << n.infixToPostfix("A-B+C");
    return 0;
}