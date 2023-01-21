#include <iostream>
#include <string>
using namespace std;

class node
{
protected:
private:
public:
    int data;
    node *next;

    // Constructors
    node(int x)
    {
        data = x;
        next = NULL;
    }
    // Destructors
};

void InsertLast(node *&head, int x)
{
    node *n = new node(x);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void InsertFirst(node *&head, int x)
{
    node *n = new node(x);
    n->next = head;
    head = n;
}

void dispaly(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(node *head, int num)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    node *head = NULL;

    cout << "\n\t\t" << __TIME__ << "\t\t" << __DATE__ << endl
         << endl;

    cout << "\4 ";
    InsertLast(head, 31);
    InsertLast(head, 32);
    InsertLast(head, 33);

    cout << "Inserted at Tail____" << endl;
    dispaly(head);
    cout << "\4 ";

    InsertFirst(head, 34);
    cout << "Inserted at Head____" << endl;
    dispaly(head);

    cout << "\4 " << search(head, 33) << endl;
    return 0;
}
