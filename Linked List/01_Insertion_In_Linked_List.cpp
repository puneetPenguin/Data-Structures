#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Calculating Length.
int length_of_linked_list(Node *head)
{
    int l = 0;
    while(head!=NULL){
        l++;
        head = head->next;
    }
    return l;
}

// Printing.
void print_linked_list(Node *head){
    cout << "----------------------------------------------------------" << endl;
    cout << "Linked List is: " << endl;
    while(head!=NULL){
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << "NULL" << endl;
    cout << "----------------------------------------------------------" << endl;
}

// Insertion at end.
Node *push_back(Node *head, int x)
{
    Node *newNode = new Node(x);

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Insertion at front.
Node *push_front(Node *head, int x)
{
    Node *newNode = new Node(x);
    newNode->next = head;
    head = newNode;
    return head;
}

// Insert at index.
Node *insert(Node *head, int value, int index)
{
    int length = length_of_linked_list(head);
    if (index<0 || index>=length){
        cout << "!!!:::Invalid Index:::!!!" << endl;
        return head;
    }
    else if (index==0){
        return push_front(head, value);
    } 
    else if (index==length-1){
        return push_back(head, value);
    }
    else{
        Node *newNode = new Node(value);

        Node *curr = head;
        Node *prev = NULL;
        int i = 0;

        while(i<index){
            prev = curr;
            curr = curr->next;
            i++;
        }

        prev->next = newNode;
        newNode->next = curr;

        return head;
    }
}


int main()
{
    Node *head = NULL;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int item;
    cout << "Enter values: ";
    while(n--){
        cin >> item;
        // Note: When head is modified remember to use it as assignment on head...
        head = push_back(head, item);
    }

    print_linked_list(head);

    cout << "Enter value and index to insert: ";
    int v, ind;
    cin >> v >> ind;

    head = insert(head, v, ind);

    print_linked_list(head);

    return 0;
}