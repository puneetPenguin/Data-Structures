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

// Searching.
int search(Node *head, int value)
{
    Node *temp = head;
    int position = 0;  // 0 based indexing.
    while(temp!=NULL){
        if(temp->data == value){
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
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

    cout << "Enter element to be searched: ";
    int i;
    cin >> i;

    if (search(head, i) == -1) cout << "!!!:::Element Not Found:::!!!" << endl;
    else cout << "!!!:::Element found at index " << search(head, i) << ":::!!!" << endl;

    return 0;
}