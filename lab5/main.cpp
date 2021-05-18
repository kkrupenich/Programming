#include <iostream>
#include "queue.h"
#include "stack.h"
#include "main.h"

using namespace std;
 
void check(int *a)
{
    int valid = 0;
    char inpStr[1024];
    char buffer = 0;
    while(!valid)
        {
            buffer = 0;
            if((scanf("%1023[^\n]%c",inpStr,&buffer) != 2) || buffer != '\n')
            {
                if(printf("Incorrect input. Try again: "))
                    getchar();
            }
            else
            if((sscanf(inpStr,"%d%c",&*a,&buffer) != 1) || buffer != '\n')
                printf("Incorrect input. Try again: ");
            else
            valid = 1;
        }
}

int main()
{
    Queue q;
    int n,m;

    cout << "Enter Stack's count: ";
	check(&n);
    while(n < 0)
    {
        cout << "Incorrect input. Try again: ";
        check(&n);
    }

    cout << "Enter info's count: ";
	check(&m);
    while(m < 0)
    {
        cout << "Incorrect input. Try again: ";
        check(&m);
    }
    int a;

    for(int i = 0; i < m; i++)//input in queue
    {
        Item* item = new Item;
        cout << "Enter Stack: ";
        check(&a);
        while(a < 0 || a >= n)
        {
            cout << "Incorrect input. Try again: ";
            check(&a);
        }
        item->iStack = a;

        cout << "Enter operation: ";
        cin >> item->operation;

        cout << "Enter data: ";
        check(&a);
        while(a < 0)
        {
            cout << "Incorrect input. Try again: ";
            check(&a);
        }
        item->data = a;
        q.push(item);
    }

    Stack *st = new Stack[n];

    cout << endl;
    for(int i = 0; !q.isEmpty(); i++)//input in stack
    {
        Item* item = new Item;
        item = q.pop();
        if(item->operation == 'A')
            st[item->iStack].push(item->data);
        else if (item->operation == 'D')
            st[item->iStack].pop();
    }
    for(int i = 0; i < n; i++) //output
    {
        cout << "Stack " << i + 1 << ": ";
        while(!st[i].isEmpty())
            cout << st[i].pop() << ' ';
        cout << endl;
    }
    return 0;
}