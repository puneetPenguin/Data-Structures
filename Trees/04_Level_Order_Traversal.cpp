// This is done with the help of stack.
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

void levelOrderTraversal(Node *root)
{
    // Create a queue to store address of nodes.
    queue<Node *> q;
    // Print root node and push its address in queue.
    cout << root->data << " ";
    q.push(root);
    // Print remaining nodes.
    while(!q.empty()){
        // Put root at the first element of queue.
        root = q.front();
        q.pop();
        // Check if left child exists then print and enqueue.
        if(root->lchild){
            cout << root->lchild->data << " ";
            q.push(root->lchild);
        }
        // Check same for right child.
        if(root->rchild){
            cout << root->rchild->data << " ";
            q.push(root->rchild);
        }
    } cout << endl;
}

int main()
{
    cout << "Enter root: ";
    Node *root = create_tree();

    cout << "Level order traversal of tree is: ";
    levelOrderTraversal(root);
    cout << endl;    

    return 0;
}