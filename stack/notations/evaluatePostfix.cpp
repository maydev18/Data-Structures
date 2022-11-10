#include <iostream>
#include <stack>
#include <string>
#include <math.h>
using namespace std;
class EvaluatePostfix{
    public:
        int eval(string exprsn){
            stack<int> stk;
            int i = 0;
            string infix = "";
            while(i < exprsn.size()){
                if(exprsn[i] >= '0' && exprsn[i] <='9'){
                    stk.push(exprsn[i] - '0');
                }
                else{
                    int s1 = stk.top();
                    stk.pop();
                    int s2 = stk.top();
                    stk.pop();
                    int result;
                    if(exprsn[i] == '+'){
                        result = s2+s1;
                    }
                    else if(exprsn[i] == '-'){
                        result = s2-s1;
                    }
                    else if(exprsn[i] == '*'){
                        result = s2*s1;
                    }
                    else if(exprsn[i] == '$'){
                        result = pow(s2,s1);
                    }
                    else{
                        result = s2/s1;
                    }
                    stk.push(result);
                }
                i++;
            }
            return stk.top();
        }

};
int  main(){
    EvaluatePostfix e;
    cout << e.eval("623+-382/+*2$3+");
    return 0;
}