#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
}*front=NULL, *rear=NULL;

void enqueue(int x)
{
    Node *t = new Node();
    // if t is still Null, that means heap is full.
    if(t==NULL) cout << "Queue is Full." << endl;
    else{
        t->data = x;
        // check if queue is empty, put front at first node.
        if(front==NULL) front = rear = t;
        else{
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    if(front==NULL) cout << "Queue is Empty." << endl;
    else{
        Node *p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

void display()
{
    Node *tr = front;
    cout << "Queue is: ";
    while(tr!=NULL){
        cout << tr->data << " -> ";
        tr = tr->next;
    } cout << "NULL" << endl;
}

int main()
{
    enqueue(45);
    enqueue(35);
    enqueue(25);
    enqueue(55);
    enqueue(75);
    enqueue(85);

    display();

    cout << "Dequeued element: " << dequeue() << endl;

    display();

    return 0;
}