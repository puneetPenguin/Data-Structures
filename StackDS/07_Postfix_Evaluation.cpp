#include <iostream> 
#include <string>
#include <stack>
using namespace std;

bool isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return false;
    return true;
}

int evaluatePostfix(string postfix)
{
    stack<int> st;
    int x, y;
    for(int i=0; i<postfix.length(); i++){
        if(isOperand(postfix[i]))
            st.push((int)postfix[i]-48);
        else{
            y = st.top();
            st.pop();
            x = st.top();
            st.pop();

            char op = postfix[i];

            switch (op)
            {
            case '+':
                st.push(x+y);
                break;
            case '-':
                st.push(x-y);
                break;
            case '*':
                st.push(x*y);
                break;
            case '/':
                st.push(x/y);
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;

    cout << "Value of postfix expression is: " << evaluatePostfix(exp) << endl;

    return 0;
}