#include <iostream>
#include "stack.h"

using namespace std;

void Stack::push(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = nullptr;

    if(!head)
    {
        head = temp;
        tail = temp;
        temp = nullptr;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
int Stack::pop()   
{
    int dat;
    if(head == tail)
    {
        dat = head->data;
        head = tail = nullptr;
        return dat;
    }

    node *current = head;
    node *previous = nullptr;
    while (current->next)
    {
        previous = current;
        current = current->next;
    }
    tail = previous;
    previous->next = nullptr;
    dat = current->data;
    delete current;
    return dat;
} 
bool Stack::isEmpty()
{
    return head == NULL;
}