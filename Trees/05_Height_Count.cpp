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

// Most of operations on trees use postorder form like here in count and height.
int count(Node *root)
{
    if(root==NULL)
        return 0;

    return count(root->lchild) + count(root->rchild) + 1;
}

int height(Node *root)
{
    int x, y;
    if(root!=NULL)
    {
        x = height(root->lchild);
        y = height(root->rchild);
        // The path where we will find greater number of nodes will be height.
        if(x>y){
            return x+1;
        }
        else{
            return y+1;
        }
    }
    return 0;
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

int main()
{
    cout << "Enter root: ";
    Node *root = create_tree();

    cout << "Preorder of tree is: ";
    preorder(root);
    cout << endl;

    cout << "Number of nodes: " << count(root) << endl;

    cout << "Height: " << height(root) << endl;

    return 0;
}