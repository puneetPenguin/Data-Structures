#include <iostream>
#include <stack>
#include <string>
using namespace std;

// ASCII can be used: ( = 41 , ) = 42, [ = 91, ] = 93, { = 123, } = 125.
bool checkBracket(char a, char b)
{
    int diff = abs((int)a - (int)b);
    if(diff < 3)
        return true;
    return false;
}

bool isBalanced(string exp)
{
    stack<char> st;
    
    for(int i=0; i<exp.length(); i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
            st.push(exp[i]);

        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(st.empty()){
                return false;
            }
            else{
                if(checkBracket(st.top() ,exp[i]))
                    st.pop();
                else
                    return false;
            }
        }
    }
    if(st.empty()) return true;

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