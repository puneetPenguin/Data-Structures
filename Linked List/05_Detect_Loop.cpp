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

// Checking for loop.
bool loop_exists(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

int main()
{
    Node *head = NULL;

    head = push_back(head, 1);
    head = push_back(head, 2);
    head = push_back(head, 12);
    head = push_back(head, 11);
    head = push_back(head, 4);
    head = push_back(head, 7);
    head = push_back(head, 9);
    head = push_back(head, 18);

    // creation of loop.
    head->next->next->next->next->next = head;

    if(loop_exists(head)) cout << "!!!:::LOOP EXISTS:::!!!" << endl;
    else cout << "!!!:::NO LOOP EXIST:::!!!" << endl;

    return 0;
}