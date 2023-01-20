#include <iostream>
#include <string>
using namespace std;

#define s 10

class Stack_Implement
{
    int top;

public:
    int a[s];

    Stack_Implement()
    {
        top = -1;
    }

    bool push_IN_stack(int z);
    int pop_FROM_stack();
    int peek__OF_stack();
    bool Empty_stack();
};

bool Stack_Implement::push_IN_stack(int z)
{
    if (top >= (s - 1))
    {
        cout << "Stack Overflow! ";
        return false;
    }

    else
    {
        a[++top] = z;
        cout << z << " has pushed in Stack!" << endl;
        return true;
    }
}

int Stack_Implement::pop_FROM_stack()
{
    if (top < 0)
    {
        cout << "Stack Underflow! ";
        return 0;
    }

    else
    {
        int x = a[top--];
        return x;
    }
}

int Stack_Implement::peek__OF_stack()
{
    if (top < 0)
    {
        cout << "Stack is Empty! " << endl;
        return 0;
    }

    else
    {
        int x = a[top];
        return x;
    }
}

bool Stack_Implement::Empty_stack()
{
    return (top < 0);
}

int main()
{
    Stack_Implement x;
    x.push_IN_stack(1);
    x.push_IN_stack(2);
    x.push_IN_stack(3);
    x.push_IN_stack(4);
    x.push_IN_stack(5);

    cout << endl;
    cout << x.pop_FROM_stack() << " has popped out from Stack! " << endl;
    cout << x.pop_FROM_stack() << " has popped out from Stack! " << endl;

    cout << endl;
    cout << "Top element of Stack is: " << x.peek__OF_stack() << endl;
    cout << x.pop_FROM_stack() << " has popped out from Stack! " << endl;

    cout << endl;
    cout << "Now top element of Stack is: " << x.peek__OF_stack() << endl;
    cout << "Remainig elements present in Stack are: ";

    while (!x.Empty_stack())
    {
        cout << x.peek__OF_stack() << " ";
        x.pop_FROM_stack();
    }
    cout << endl
         << endl;

    // only for the verification
    if (x.Empty_stack())
    {
        cout << "Stack is Empty! ";
    }

    else
    {
        cout << x.peek__OF_stack() << " ";
        x.pop_FROM_stack();
    }

    return 0;
}