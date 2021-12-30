#include <bits/stdc++.h>
using namespace std;


/* NODES FOR TREE */
class TreeNode
{
public:
    TreeNode *leftChild;
    int data;
    TreeNode *rightChild;

    TreeNode(int x){
        data = x;
        leftChild = rightChild = nullptr;
    }
};


/* RECURSIVE INORDER */
void recursiveInOrder(TreeNode *root)
{
    if(root){
        recursiveInOrder(root->leftChild);
        cout << root->data << " ";
        recursiveInOrder(root->rightChild);
    }
}


/* SEARCHING IN BST */
TreeNode *search(TreeNode *root, int key)
{
    TreeNode *t = root;

    while(t){
        if(t->data == key)
            return t;
        else if(t->data < key)
            t = t->rightChild;
        else
            t = t->leftChild;
    }

    return nullptr;
}


/* INSERTION IN BST */
TreeNode *insert(TreeNode *root, int key)
{
    if (root == nullptr){
        root = new TreeNode(key);
        return root;
    }

    TreeNode *prev = nullptr;
    TreeNode *temp = root;
    TreeNode *curr;

    // Reach to the node position and maintain previous.
    while(temp!=NULL){
        prev = temp;
        if(temp->data == key)
            return root;
        else if(temp->data < key)
            temp = temp->rightChild;
        else
            temp = temp->leftChild;
    }

    curr = new TreeNode(key);

    // Insert node at position now.
    if(prev->data < key){
        prev->rightChild = curr;
    }
    else{
        prev->leftChild = curr;
    }
    return root;
}


/* INORDER PREDECESSOR and SUCCESSOR */
TreeNode *inorderPre(TreeNode *n)
{
    // Inorder predecessor is the rightmost child of left subtree.
    // So, go to left subtree first.
    n = n->leftChild;

    // Now, go to right most child.
    while(n->rightChild){
        n = n->rightChild;
    }
    return n;
}

TreeNode *inorderSucc(TreeNode *n)
{
    // Inorder successor is the leftmost child of right subtree.
    n = n->rightChild;

    while(n->leftChild){
        n = n->leftChild;
    }
    return n;
}


/* DELETION OF A NODE */

// Case 1 - When node is leaf node, delete it directly.
// Case 2 - When node have a single child, remove that node and link its child to the parent node.
// Case 3 - When node have two children, replace the node by inorder predecessor/ successor and do it recursively until you reach a leaf node to remove.

TreeNode *deleteNode(TreeNode *root, int key)
{
    // Case if root becomes null.
    if(root == nullptr)
        return nullptr;

    // If root lies in left subtree make the problem smaller.
    else if(key < root->data)
        root->leftChild = deleteNode(root->leftChild, key);

    // If root lies in right subtree make the problem smaller.
    else if(key > root->data)
        root->rightChild = deleteNode(root->rightChild, key);

    // Actual deletion process.
    else{
        // No child.
        if(root->leftChild == nullptr && root->rightChild == nullptr){
            delete root;
            root = nullptr;
        }
        
        // One or Two children.
        else{
            TreeNode *temp = inorderPre(root);
            root->data = temp->data;
            // As inorder predecessor lies in left subtree, call delete function for node that will replace the root.
            root->leftChild = deleteNode(root->leftChild, temp->data);
        }
    }
    return root;
}


int main()
{
    TreeNode *root = nullptr;

    int n;
    cout << "Enter root element: ";
    cin >> n;
    root = insert(root, n);

    cout << "Enter elements: ";
    while(cin >> n){
        root = insert(root, n);
    }
    
    cout << "Inorder of given BST is: ";
    recursiveInOrder(root);
    cout << endl;

    root = deleteNode(root, 3);
    cout << "Inorder after deleting 3 is: ";
    recursiveInOrder(root);
    cout << endl;

    return 0;
}