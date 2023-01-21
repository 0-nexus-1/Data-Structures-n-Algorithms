#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "\n\t\tDate: " << __TIME__ << "\t\tTime: " << __DATE__ << endl
         << endl;
    cout << "Printing without Recurrsion and Loops. " << endl;
    int i = 1;

p:
    if (i <= 10)
    {
        cout << i << endl;
        i++;
        goto p;
    }
    return 0;
}
