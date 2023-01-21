#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

class node
{
public:
    string employee_id;
    string name;
    string post;
    string department;
    float salary;

    node *next_add;
};

class employee
{
private:
    node *head;

public:
    employee();
    void introduction();
    void login();
    void control_panel();
    void insert();
    void search_id();
    void Edit();
    void del();
    void display();
    void salaray_slip();
    void search_dept();
};

employee::employee()
{
    head = NULL;
}

void employee::introduction()
{
    system("cls");
    cout << "\n\n\n";
    cout << "\n\t\t\t============================== ";
    cout << "\n\n\t\t\t\4 Employee Management System \4 ";
    cout << "\n\n\t\t\t============================== ";
}

void employee::login()
{
p:
    system("cls");
    string user;
    string pass;
    cout << "\n\n";
    cout << "\n\t\t\t============================== ";
    cout << "\n\n\t\t\t\t\4 Login Panel \4 ";
    cout << "\n\n\t\t\t============================== ";
    cout << "\n\t\t\tEnter Your Name: ";
    cin >> user;
    cout << "\t\t\tEnter Password: ";

    for (int i = 1; i <= 6; i++)
    {
        pass += getch();
        cout << "\4";
    }

    if (user == "MS" && pass == "123456")
    {
        cout << "\n\n\t\t\tCongratulations! Login Successful ";
        cout << "\n\n\t\t\t\t    Loading";

        for (int i = 1; i < 6; i++)
        {
            Sleep(500);
            cout << ".";
        }
        control_panel();
    }

    else if (user != "MS" && pass == "123456")
    {
        cout << "\n\n\t\t\tUsername is wrong! ";
    }

    else if (user == "MS" && pass != "123456")
    {
        cout << "\n\n\t\t\tYour Password is wrong! ";
    }

    else
    {
        cout << "\n\n\t\t\tBoth, Username and Password are wrong! ";
    }

    goto p;
}

void employee::control_panel()
{
p:
    system("cls");
    cout << "\n\t\t    Date: " << __TIME__ << "\t  Time: " << __DATE__ << endl
         << endl;
    int x;
    cout << "\n\t\t\t============================== ";
    cout << "\n\t\t\t     Employee Control Panel ";
    cout << "\n\t\t\t============================== ";
    cout << "\n\n\n 1. Insert Record ";
    cout << "\n 2. Search Record ";
    cout << "\n 3. Edit Record ";
    cout << "\n 4. Delete Record ";
    cout << "\n 5. Display Record ";
    cout << "\n 6. Salary Slip ";
    cout << "\n 7. Search Department ";
    cout << "\n 8. Exit ";
    cout << "\n\n Select your choice (Positive Integer from 1 to 8): ";
    cin >> x;

    switch (x)
    {
    case 1:
        insert();
        break;

    case 2:
        search_id();
        break;

    case 3:
        Edit();
        break;

    case 4:
        del();
        break;

    case 5:
        display();
        break;

    case 6:
        salaray_slip();
        break;

    case 7:
        search_dept();
        break;

    case 8:
        exit(0);

    default:
        cout << "\n\n ___Invalid choice, please try again___ ";
    }

    getch();
    goto p;
}

void employee::insert()
{
    node *temp = new node;
    cout << "\nEnter Employee ID: ";
    cin >> temp->employee_id;
    cout << "Enter Name: ";
    cin >> temp->name;
    cout << "Enter Post: ";
    cin >> temp->post;
    cout << "Enter Department: ";
    cin >> temp->department;
    cout << "Enter Salary: ";
    cin >> temp->salary;
    temp->next_add = NULL;

    fstream file;
    file.open("I'm_Here.txt", ios::out | ios::app);
    file << temp->employee_id << " " << temp->name << " " << temp->post << " " << temp->department << " " << temp->salary << endl;
    file.close();

    temp->next_add = head;
    head = temp;

    cout << "\nRecord Inserted! ";
}

void employee::search_id()
{
    system("cls");
    string id;
    cout << "\nEnter the ID of the employee to search: ";
    cin >> id;

    fstream file;
    file.open("I'm_Here.txt", ios::in);

    string cur_id;
    string name;
    string post;
    string department;
    float salary;
    bool found = false;

    while (file >> cur_id >> name >> post >> department >> salary)
    {
        if (cur_id == id)
        {
            cout << "\nEmployee ID: " << cur_id << "\nName: " << name << "\nPost: " << post << "\nDepartment: " << department << "\nSalary: " << salary << endl;
            found = true;
            break;
        }
    }

    file.close();
    if (!found)
    {
        cout << "\nRecord not found! ";
    }
}

void employee::Edit()
{
    system("cls");
    string id;
    cout << "\nEnter the ID of the employee to edit: ";
    cin >> id;

    fstream file;
    file.open("I'm_Here.txt", ios::in);
    string temp_file = "temp_I'm_Here.txt";
    fstream temp;
    temp.open(temp_file, ios::out);

    string cur_id;
    string name;
    string post;
    string department;
    float salary;
    bool found = false;

    while (file >> cur_id >> name >> post >> department >> salary)
    {
        if (cur_id != id)
        {
            temp << cur_id << " " << name << " " << post << " " << department << " " << salary << endl;
        }

        else
        {
            found = true;
            cout << "Enter the new Name: ";
            cin >> name;
            cout << "Enter the new Post: ";
            cin >> post;
            cout << "Enter the new Department: ";
            cin >> department;
            cout << "Enter the new Salary: ";
            cin >> salary;
            temp << cur_id << " " << name << " " << post << " " << department << " " << salary << endl;
        }
    }

    file.close();
    temp.close();

    if (found)
    {
        remove("I'm_Here.txt");
        rename(temp_file.c_str(), "I'm_Here.txt");
        cout << "\nRecord Edited! ";
    }

    else
    {
        cout << "\nRecord not found! ";
    }
}

void employee::del()
{
    system("cls");
    string id;
    cout << "\nEnter the ID of the employee to delete: ";
    cin >> id;

    fstream file;
    file.open("I'm_Here.txt", ios::in);
    string temp_file = "temp_I'm_Here.txt";
    fstream temp;
    temp.open(temp_file, ios::out);

    string cur_id;
    string name;
    string post;
    string department;
    float salary;
    bool found = false;

    while (file >> cur_id >> name >> post >> department >> salary)
    {
        if (cur_id != id)
        {
            temp << cur_id << " " << name << " " << post << " " << department << " " << salary << endl;
        }

        else
        {
            found = true;
        }
    }

    file.close();
    temp.close();

    if (found)
    {
        remove("I'm_Here.txt");
        rename(temp_file.c_str(), "I'm_Here.txt");
        cout << "\nRecord Deleted! ";
    }

    else
    {
        cout << "\nRecord not found! ";
    }
}

void employee::display()
{
    system("cls");
    cout << "\n\t\t\t============================== ";
    cout << "\n\t\t\t     Employee Records ";
    cout << "\n\t\t\t============================== ";

    fstream file;
    file.open("I'm_Here.txt", ios::in);

    string id;
    string name;
    string post;
    string department;
    float salary;

    while (file >> id >> name >> post >> department >> salary)
    {
        cout << "\nEmployee ID: " << id << "\nName: " << name << "\nPost: " << post << "\nDepartment: " << department << "\nSalary: " << salary << endl;
    }

    file.close();
}

void employee::salaray_slip()
{
    string id;
    cout << "Enter employee ID: ";
    cin >> id;

    fstream file;
    file.open("I'm_Here.txt", ios::in);

    if (!file)
    {
        cout << "File not found! ";
        return;
    }

    string employee_id;
    string name;
    string post;
    string department;
    float salary;
    bool found = false;

    while (file >> employee_id >> name >> post >> department >> salary)
    {
        if (employee_id == id)
        {
            cout << "\n\t\t\t============================== ";
            cout << "\n\t\t\t=                            = ";
            cout << "\n\t\t\t=    Employee Salary Slip    = ";
            cout << "\n\t\t\t=                            = ";
            cout << "\n\t\t\t============================== ";

            cout << "\n\n\t\t\tEmployee ID:         " << employee_id;
            cout << "\n\t\t\tName:                " << name;
            cout << "\n\t\t\tPost:                " << post;
            cout << "\n\t\t\tDepartment:          " << department;
            cout << "\n\t\t\tSalary:              " << salary;
            cout << "\n\n\t\t\t============================== ";
            cout << "\n\t\t\tTime:              " << __TIME__;
            cout << "\n\t\t\tDate:              " << __DATE__;
            cout << "\n\t\t\t============================== ";

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Employee not found!";
    }

    file.close();
}

void employee::search_dept()
{
    system("cls");
    string department;
    cout << "\nEnter the department to search: ";
    cin >> department;

    fstream file;
    file.open("I'm_Here.txt", ios::in);

    string id;
    string name;
    string post;
    string cur_department;
    float salary;
    bool found = false;

    while (file >> id >> name >> post >> cur_department >> salary)
    {
        if (cur_department == department)
        {
            cout << "\nEmployee ID: " << id << "\nName: " << name << "\nPost: " << post << "\nDepartment: " << cur_department << "\nSalary: " << salary << endl;
            found = true;
        }
    }

    file.close();
    if (!found)
    {
        cout << "\nNo employees found in that department! ";
    }
}

int main()
{
    employee obj;
    obj.introduction();
    obj.login();
}
