#ifndef queue_h
#define queue_h

struct Item
{
    int iStack;
    char operation;
    int data;
    Item *next;
};

class Queue
{
    public:
        Item *head, *tail;

        Queue()
        {
            head = nullptr;
            tail = nullptr;
        }

        void push(Item* item);
        Item* pop();
        bool isEmpty();
};

#endif