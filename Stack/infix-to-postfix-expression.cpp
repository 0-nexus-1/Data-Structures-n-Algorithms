#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Stack
{
    int top;
    int size;
    int *a;

public:
    Stack(int s)
    {
        top = -1;
        size = s;
        a = new int[size];
    }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};

bool Stack::isEmpty()
{
    return (top < 0);
}

bool Stack::isFull()
{
    return (top == size - 1);
}

int Stack::peek()
{
    return a[top];
}

bool Stack::push(int x)
{
    if (top >= (size - 1))
    {
        cout << "Stack Overflow";
        return false;
    }

    else
    {
        top++;
        a[top] = x;
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return -1;
    }

    else
    {
        int x = a[top];
        top--;
        return x;
    }
}

int priority(char alpha)
{
    if (alpha == '+' || alpha == '-')
    {
        return 1;
    }

    if (alpha == '*' || alpha == '/')
    {
        return 2;
    }

    if (alpha == '^')
    {
        return 3;
    }

    return 0;
}

string convert(string infix)
{
    int i = 0;
    string postfix = "";

    Stack s(20);
    while (infix[i] != '\0')
    {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            postfix += infix[i];
            i++;
        }

        else if (infix[i] == '(')
        {
            s.push(infix[i]);
            i++;
        }

        else if (infix[i] == ')')
        {
            while (s.peek() != '(')
                postfix += s.pop();
            s.pop();
            i++;
        }

        else
        {
            while (!s.isEmpty() && priority(infix[i]) <= priority(s.peek()))
            {
                postfix += s.pop();
            }

            s.push(infix[i]);
            i++;
        }
    }

    while (!s.isEmpty())
    {
        postfix += s.pop();
    }

    cout << "\nPostfix expression is: " << postfix;
    return postfix;
}

int main()
{
    string infix;
    cout << "\nEnter Infix expression: ";
    cin >> infix;

    string postfix;
    postfix = convert(infix);

    cout << endl
         << endl;
    return 0;
}
