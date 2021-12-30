#include <bits/stdc++.h>
using namespace std;
#define ll long long


/* DEFINING A NODE FOR TREE */
class TreeNode
{
public:
    TreeNode *leftChild;
    int data;
    TreeNode *rightChild;

    TreeNode(int x){
        data = x;
    }
};


/* CREATION OF TREE */
TreeNode *createTree()
{
    // Creating temporary pointers to store node addresses values.
    TreeNode *p = nullptr;
    TreeNode *t = nullptr;

    queue<TreeNode *> q;

    int x;
    cout << "Enter value for root: ";
    cin >> x;
    // Create root node and push in queue.
    TreeNode *root = new TreeNode(x);
    root->leftChild = root->rightChild = nullptr;
    q.push(root);

    // Repeat while queue is not empty.
    while(!q.empty()){
        // Store front element of queue and pop it.
        p = q.front();
        q.pop();

        // Make left node and link it and push in queue.
        cout << "Enter left child for " << p->data << ": ";
        cin >> x;
        if(x!=-1){
            t = new TreeNode(x);
            t->leftChild = t->rightChild = nullptr;

            p->leftChild = t;   

            q.push(t);
        }

        // Do same for right nodes.
        // Make left node and link it and push in queue.
        cout << "Enter right child for " << p->data << ": ";
        cin >> x;
        if(x!=-1){
            t = new TreeNode(x);
            t->leftChild = t->rightChild = nullptr;

            p->rightChild = t;   

            q.push(t);
        }
    }
    return root;
}


/* RECURSIVE PREORDER */
void recursivePreOrder(TreeNode *root)
{
    if(root){
        cout << root->data << " ";
        recursivePreOrder(root->leftChild);
        recursivePreOrder(root->rightChild);
    }
}


/* RECURSIVE INORDER */
void recursiveInOrder(TreeNode *root)
{
    if(root){
        recursiveInOrder(root->leftChild);
        cout << root->data << " ";
        recursiveInOrder(root->rightChild);
    }
}


/* RECURSIVE POSTORDER */
void recursivePostOrder(TreeNode *root)
{
    if(root){
        recursivePostOrder(root->leftChild);
        recursivePostOrder(root->rightChild);
        cout << root->data << " ";
    }
}


/* ITERATIVE PREORDER */
void iterativePreOrder(TreeNode *root)
{
    stack <TreeNode *> st;
    TreeNode *t = root;

    while(!st.empty() || t!=nullptr){
        if(t!=nullptr){
            cout << t->data << " ";
            st.push(t);
            t = t->leftChild;
        }
        else{
            t = st.top();
            st.pop();

            t = t->rightChild;
        }
    }
}


/* ITERATIVE INORDER */
void iterativeInOrder(TreeNode *root)
{
    stack <TreeNode *> st;
    TreeNode *t = root;

    while(!st.empty() || t!=nullptr){
        if(t!=nullptr){
            st.push(t);
            t = t->leftChild;
        }
        else{
            t = st.top();
            st.pop();

            cout << t->data << " ";

            t = t->rightChild;
        }
    }
}


/* RECURSIVE POSTORDER */
void iterativePostOrder(TreeNode *root)
{
    ll temp;
    stack <ll> st;
    TreeNode *t = root;

    while(!st.empty() || t!=nullptr){
        if(t!=nullptr){
            st.push((ll)t);
            t = t->leftChild;
        }
        else{
            temp = st.top();
            st.pop();

            if(temp>0){
                st.push(-temp);
                t = ((TreeNode *)temp)->rightChild;
            }
            else{
                cout << ((TreeNode *)-temp)->data << " ";
            }
        }
    }
}


/* COUNT NODES */
int count(TreeNode* root)
{
    TreeNode *t = root;
    int x, y;

    if(t == NULL) 
        return 0;
    
    x = count(root->leftChild);
    y = count(root->rightChild);

    return x + y + 1;
}


/* HEIGHT */
int height(TreeNode* root)
{
    TreeNode *t = root;
    int x, y;

    if(t == NULL) 
        return 0;
    
    x = height(root->leftChild);
    y = height(root->rightChild);

    return max(x+1, y+1);
}  


int main()
{
    TreeNode *root = createTree();

    cout << "-------------------------------------------" << endl;
    cout << "Recursive Preorder: ";
    recursivePreOrder(root);
    cout << endl;

    cout << "Iterative Preorder: ";
    iterativePreOrder(root);
    cout << endl;
    cout << "-------------------------------------------" << endl;


    cout << "-------------------------------------------" << endl;
    cout << "Recursive Inorder: ";
    recursiveInOrder(root);
    cout << endl;

    cout << "Iterative Inorder: ";
    iterativeInOrder(root);
    cout << endl;
    cout << "-------------------------------------------" << endl;


    cout << "-------------------------------------------" << endl;
    cout << "Recursive Postorder: ";
    recursivePostOrder(root);
    cout << endl;

    cout << "Iterative Postorder: ";
    iterativePostOrder(root);
    cout << endl;
    cout << "-------------------------------------------" << endl;

    cout << "Number of nodes: " << count(root) << endl << endl;

    cout << "Height of tree: " << height(root) << endl << endl;

    return 0;
}