#include <iostream>
#include "queue.h"

using namespace std;

void Queue::push(Item* item)
{
    if(head == NULL)
    {
        head = item;
        tail = item;
        item = NULL;
    }
    else
    {
        tail->next = item;
        tail = item;
    }
}
Item* Queue::pop()
{
    if(!head) return nullptr;
    if (tail == head)
    {
        Item *item = new Item;
        item = tail;
        tail = head = nullptr;
        return item;
    }
            
    Item *item = new Item;
    item = head;
    head = head->next;
    return item;
}
bool Queue::isEmpty()
{   
    return head == NULL; 
}