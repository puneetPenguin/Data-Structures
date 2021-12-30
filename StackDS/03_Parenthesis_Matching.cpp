#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string exp)
{
    stack<char> st;
    
    for(int i=0; i<exp.length(); i++){
        if(exp[i]=='('){
            st.push(exp[i]);
        }
        else if(exp[i]==')'){
            if(st.empty())
                return false;
            st.pop();
        }
    }

    if(st.empty()) 
        return true;

    return false;
}

int main()
{
    string s;
    cout << "Enter the expression: ";
    cin >> s;

    bool chk = isBalanced(s);

    if(chk)
        cout << "!!!:::BALANCED:::!!!" << endl;
    else
        cout << "!!!:::NOT BALANCED:::!!!" << endl;

    return 0;
}