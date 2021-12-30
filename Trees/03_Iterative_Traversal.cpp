// This is done with the help of stack.
#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;

    Node(int x)
    {
        data = x;
    }
};

Node *create_tree()
{
    Node *root = NULL;

    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    root = new Node(x);

    cout << "Enter left child for " << x << ": ";
    root->lchild = create_tree();

    cout << "Enter right child for " << x << ": ";
    root->rchild = create_tree();

    return root;
}

void preorder(Node *root)
{
    stack<Node *> st;
    while(root!=NULL || !st.empty()){
        if(root!=NULL){
            cout << root->data << " ";
            st.push(root);
            root = root->lchild;
        }
        else{
            root = st.top();
            st.pop();
            root = root->rchild;
        }
    } cout << endl;
}

void inorder(Node *root)
{
    stack<Node *> st;
    while(root!=NULL || !st.empty()){
        if(root!=NULL){
            st.push(root);
            root = root->lchild;
        }
        else{
            root = st.top();
            st.pop();
            cout << root->data << " ";
            root = root->rchild;
        }
    } cout << endl;
}

// Postorder is quite tricky. We need to push address in stack 2 times, once for going to left and coming back, and 2nd for printing the element.
// To identify when to print and when to traverse, we will use negative integers typcasted from address and positive address.
void postorder(Node *root)
{
    stack<intptr_t> stk;
    Node *t = root;
    intptr_t temp = 0;

    while (t || !stk.empty())
    {
        if (t)
        {
            stk.push(reinterpret_cast<intptr_t>(t));
            t = t->lchild;
        }
        else
        {
            temp = reinterpret_cast<intptr_t>(stk.top());
            stk.pop();

            if (temp > 0)
            {
                stk.push(-temp);
                t = ((Node *)temp)->rchild;
            }
            else
            {
                cout << ((Node *)(-temp))->data << " ";
                t = nullptr;
            }
        }
    }
}

int main()
{
    cout << "Enter root: ";
    Node *root = create_tree();

    cout << "Iterative-Preorder of tree is: ";
    preorder(root);
    cout << endl;

    cout << "Iterative-Inorder of tree is: ";
    inorder(root);
    cout << endl;

    cout << "Iterative-Postorder of tree is: ";
    postorder(root);
    cout << endl;
    

    return 0;
}