#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return false;
    return true;
}

string infixToPostfix(string infix)
{
    stack<int> st;
    string postfix = "";
    int i=0;
    while(i<infix.length())
    {
        if (isOperand(infix[i]))
            postfix += infix[i++];
        else
        {
            if (st.empty())
                st.push(infix[i++]);
            else if (precedence(infix[i]) > precedence(st.top()))
                st.push(infix[i++]);
            else
            {
                postfix += st.top();
                st.pop();
            }
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string s;
    cout << "Enter infix expression: ";
    cin >> s;

    cout << "Postfix expression is: ";
    cout << infixToPostfix(s) << endl;

    return 0;
}