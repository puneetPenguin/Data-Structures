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


// Deletion of head.
Node *delete_front(Node *head)
{
    Node *to_be_deleted = head;
    head = head->next;

    delete(to_be_deleted);

    return head;
}

// Deletion of tail.
Node *delete_last(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    delete curr;

    return head;
}

// Deletion at index. (0 based indexing)
Node *delete_at_index(Node *head, int index)
{
    int length = length_of_linked_list(head);

    if(index<0 || index>=length){
        cout << "!!!:::Invalid Index:::!!!" << endl;
        return head;
    }
    else if(index==0){
        return delete_front(head);
    }
    else if(index==length-1){
        return delete_last(head);
    }
    else{
        Node *prev = NULL;
        Node *curr = head;
        Node *nxt = head->next;
        int i = 0;

        while(i<index){
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            i++;
        }

        prev->next = nxt;
        delete curr;

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

    cout << "Enter index to be deleted: ";
    int i;
    cin >> i;

    delete_at_index(head, i);

    print_linked_list(head);

    return 0;
}