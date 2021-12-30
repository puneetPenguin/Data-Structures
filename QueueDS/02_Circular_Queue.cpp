#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int size;
    int f;
    int r;
    int *arr;

public:
    CircularQueue()
    {
        f = 0;
        r = 0;
    }
    CircularQueue(int n)
    {
        size = n;
        f = 0;
        r = 0;
        arr = new int[size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void CircularQueue::enqueue(int x)
{
    if((r+1)%size == f) cout << "!!!:::Queue is Full:::!!!" << endl;
    else{
        r++;
        arr[r] = x;
    }
}

int CircularQueue::dequeue()
{
    int x = -1;
    if(r == f) cout << "!!!:::Queue is Empty:::!!!" << endl;
    else{
        f = (f+1)%size;
        x = arr[f];
    }
    return x;
}

void CircularQueue::display()
{
    cout << "Circular-Queue: ";
    int i = f+1;
    do{
        cout << arr[i] << " ";
        i = (i+1)%size;
    }while(i!=(r+1)%size);
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter size of queue: ";
    cin >> size;

    CircularQueue *q = new CircularQueue(size);

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int temp;
    cout << "Enter elements: ";
    while(n--){
        cin >> temp;
        q->enqueue(temp);
    }

    q->display();

    cout << "First element dequeued is: " << q->dequeue() << endl;
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();

    q->enqueue(45);
    
    q->display();

    return 0;
}