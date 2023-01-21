#include <iostream>
#include <string>
#define n 10
using namespace std;

class queue
{
protected:
private:
    int *arr;
    int front;
    int rear;

public:
    // Constructors
    queue()
    {
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    void EnQueue(int x)
    {
        if (rear == n - 1)
        {
            cout << "Queue is Full! ";
            return;
        }
        rear++;
        arr[rear] = x;

        if (front == -1)
        {
            front++;
        }
    }

    void DeQueue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty! ";
            return;
        }
        front++;
    }

    int peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty! ";
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        if (front == -1 || front > rear)
        {
            return true;
        }
        return false;
    }
    
};

int main()
{
    queue q;
    q.EnQueue(21);
    q.EnQueue(22);
    q.EnQueue(23);
    q.EnQueue(24);
    q.EnQueue(25);

    cout << q.peek() << endl;
    q.DeQueue();

    cout << q.peek() << endl;
    q.DeQueue();

    cout << q.peek() << endl;
    q.DeQueue();

    cout << q.peek() << endl;
    q.DeQueue();

    // cout << q.peek() << endl;
    // q.DeQueue();

    cout << endl;

    cout << q.empty() << endl;

    return 0;
}
