#include <iostream>
using namespace std;

class Stack{
public:
    int size;
    int top;
    int *arr;
};

bool isEmpty(Stack *st)
{
    return (st->top == -1);
}

bool isFull(Stack *st)
{
    return (st->top == (st->size - 1));
}

void push(Stack *st, int val)
{
    if(isFull(st)){
        cout << "!!!:::Stack Overflow:::!!!" << endl;
        return;
    }
    st->top++;
    st->arr[st->top] = val;
    return;
}

void pop(Stack *st)
{
    if(isEmpty(st)){
        cout << "!!!:::Stack Underflow:::!!!" << endl;
        return;
    }
    st->top--;
}

int top(Stack *st)
{
    if(isEmpty(st)){
        cout << "Stack is Empty." << endl;
        return -1;
    }
    return st->arr[st->top];
}

int peek(Stack *st, int position)
{
    // Note: (top - position + 1) will give the required index of the array we need;
    if((st->top)-position+1 < 0 || (st->top)-position+1 >= (st->size)){
        cout << "Invalid Position." << endl;
        return -1;
    }
    return st->arr[(st->top)-position+1];
}

int main()
{
    Stack *st;
    
    // Size.
    st->size = 10;

    // Init top.
    st->top = -1;

    // Pushing elements.
    push(st, 5);
    push(st, 6);
    push(st, 7);
    push(st, 8);
    
    // Find top.
    cout << "Top element is: " << top(st) << endl;

    // Find at 3rd position from top.
    cout << "Element at 3rd position from top is: " << peek(st, 3) << endl;

    // Pop.
    pop(st);
    pop(st);

    // Checking top after pop.
    cout << "Top element after popping 2 elements is: " << top(st) << endl;

    return 0;
}