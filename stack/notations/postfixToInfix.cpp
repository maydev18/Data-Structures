#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Notation{
    public:
        string postfixToInfix(string postfix){
            stack<string> stk;
            int i = 0;
            while(i < postfix.size()){
                if(postfix[i] >= 'A' && postfix[i] <='Z'){
                    string s = "";
                    s.push_back(postfix[i]);
                    stk.push(s);
                }
                else{
                    string s1 = stk.top();
                    stk.pop();
                    string s2 = stk.top();
                    stk.pop();
                    string result = '(' + s2 + postfix[i] + s1 + ')';
                    stk.push(result);
                }
                i++;
            }
            return stk.top();
        }


};
int main(){
    Notation n;
    cout << n.postfixToInfix("ABC+-D*EF+$");
    return 0;
}