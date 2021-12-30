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
void print_linked_list(Node *head)
{
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

// Reversing.
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *nxt = head->next;

    while(nxt!=NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
    }
    
    curr->next = prev;
    head = curr;

    return head;
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

    head = reverse(head);

    print_linked_list(head);
    
    return 0;
}