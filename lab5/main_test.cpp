#include <iostream>
#include "stack.h"
#include "queue.h"
#include "assert.h"

int main()
{
    Queue q;
    Item* item = new Item;
    item->data = 100;
    item->operation = 'A';
    item->iStack = 0;
    q.push(item);
    assert(q.pop() == item);

    int arr[] = {0,1,2,3,4};
    Stack st;
    for(int i = 0; i < 5; i++)
        st.push(arr[i]);
    assert(st.pop() == 4);
    assert(st.pop() == 3);
    st.pop();
    assert(st.pop() == 1);
    assert(st.isEmpty() == false);
    assert(st.pop() == 0);
    assert(st.isEmpty() == true);

    delete item;
    return 0;
}