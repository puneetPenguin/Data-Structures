#include <iostream>
#include <queue>
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
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        cout << root->data << " ";
        inorder(root->rchild);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {     
        postorder(root->lchild);
        postorder(root->rchild);
        cout << root->data << " ";
    }
}

int main()
{
    cout << "Enter root: ";
    Node *root = create_tree();

    cout << "Preorder of tree is: ";
    preorder(root);
    cout << endl;

    cout << "Inorder of tree is: ";
    inorder(root);
    cout << endl;

    cout << "Postorder of tree is: ";
    postorder(root);
    cout << endl;

    return 0;
}