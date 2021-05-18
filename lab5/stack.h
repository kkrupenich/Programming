#ifndef stack_h
#define stack_h

struct node
{
    int data;
    node* next = nullptr;
};

class Stack
{
public:
    node* head;
    node* tail;

    Stack()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data);
    int pop();
    bool isEmpty();
};


#endif