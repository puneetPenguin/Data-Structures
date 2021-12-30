#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int f;
    int r;
    int *arr;

public:
    Queue()
    {
        f = -1;
        r = -1;
    }
    Queue(int n)
    {
        size = n;
        f = -1;
        r = -1;
        arr = new int[size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    if(r == size-1) cout << "!!!:::Queue is Full:::!!!" << endl;
    else{
        r++;
        arr[r] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if(r == f) cout << "!!!:::Queue is Empty:::!!!" << endl;
    else{
        f++;
        x = arr[f];
    }
    return x;
}

void Queue::display()
{
    cout << "Queue: ";
    for(int i=f+1; i<=r; i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main()
{
    int size;
    cout << "Enter size of queue: ";
    cin >> size;

    Queue *q = new Queue(size);

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

    q->display();

    return 0;
}