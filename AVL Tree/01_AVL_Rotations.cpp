#include <bits/stdc++.h>
using namespace std;


/* NODE FOR AVL TREE */
class Node
{
public:
    Node *leftChild;
    int data;
    Node *rightChild;
    int height;

    Node(int x){
        data = x;
        leftChild = rightChild = nullptr;
        // height of every node will add 1 to root.
        height = 1;
    }
} *root = nullptr;


/* HEIGHT FUNCTION */
int getHeight(Node *n)
{
    // For empty subtree, consider height = 0.
    if(n == nullptr) 
        return 0;

    return n->height;
}


/* CALCULATION OF BALANCED FACTOR */
int getBF(Node *n)
{
    if(n == nullptr)
        return 0;
    
    return getHeight(n->leftChild) - getHeight(n->rightChild);
}


/* LEFT ROTATION */
Node *leftRotate(Node *x)
{
    Node *y = x->rightChild;
    // this is the node that will get displaced.
    Node *t2 = y->leftChild;  

    // changing links.
    x->rightChild = t2;
    y->leftChild = x;

    // Update height now.
    x->height = max(getHeight(x->leftChild), getHeight(x->rightChild)) + 1;
    y->height = max(getHeight(y->leftChild), getHeight(y->rightChild)) + 1;

    // 'y' will be the new value in place of 'x' after rotation.
    return y;
}


/* RIGHT ROTATION */
Node *rightRotate(Node *y)
{
    Node *x = y->leftChild;
    Node *t2 = x->rightChild;

    x->rightChild = y;
    y->leftChild = t2;

    x->height = max(getHeight(x->leftChild), getHeight(x->rightChild)) + 1;
    y->height = max(getHeight(y->leftChild), getHeight(y->rightChild)) + 1;

    return x;
}


/* INSERTION IN AVL TREES - Important point to note is that BF will be +ve for ll and lr cases, and -ve for rr and rl cases.*/
Node *insert(Node *root, int key)
{
    // firstly normally insert as in a BST.
    if(root == nullptr)
        return new Node(key);

    if(key > root->data)
        root->rightChild = insert(root->rightChild, key);
    else
        root->leftChild = insert(root->leftChild, key);

    // update nodes height on returning time after insertion.
    root->height = 1 + max(getHeight(root->leftChild), getHeight(root->rightChild));

    // checking imbalance and doing rotations.
    int bf = getBF(root);

    // LL case.
    if(bf > 1 && key < root->leftChild->data){
        return rightRotate(root);
    }
    // RR case.
    if(bf < -1 && key > root->rightChild->data){
        return leftRotate(root);
    }
    // LR case.
    if(bf > 1 && key > root->leftChild->data){
        root->leftChild = leftRotate(root->leftChild);
        return rightRotate(root);
    }
    // RL case.
    if(bf < -1 && key < root->rightChild->data){
        root->rightChild = rightRotate(root->rightChild);
        return leftRotate(root);
    }
    return root;
}


/* TRAVERSALS */
void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->leftChild);
        cout << root->data << " ";
        inorder(root->rightChild);
    }
}


int main()
{
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}