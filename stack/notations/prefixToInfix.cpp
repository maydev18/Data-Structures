#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Notation{
    public:
        string prefixToInfix(string prefix){
            stack<string> stk;
            int i = prefix.size()-1;
            while(i >= 0){
                if(prefix[i] >= 'A' && prefix[i] <='Z'){
                    string s = "";
                    s.push_back(prefix[i]);
                    stk.push(s);
                }
                else{
                    string s1 = stk.top();
                    stk.pop();
                    string s2 = stk.top();
                    stk.pop();
                    string result = '(' + s1 + prefix[i] + s2 + ')';
                    stk.push(result);
                }
                i--;
            }
            return stk.top();
        }


};
int main(){
    Notation n;
    cout << n.prefixToInfix("*-A/BC-/AKL");
    // cout << n.prefixToInfix("*-A/BC-/AKL");
    return 0;
}