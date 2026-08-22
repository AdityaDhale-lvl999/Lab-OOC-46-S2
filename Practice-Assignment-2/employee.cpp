#include <iostream>
#include <string>
using namespace std;

class Employee
{
    string id;
    string name;
    float basicSalary, bonus, totalSalary;

public:
    void getData()
    {
        cout << "Enter Employee ID: ";
        cin >> id;

        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;

        cout << "Enter Bonus: ";
        cin >> bonus;
    }

    void calculateSalary()
    {
        totalSalary = basicSalary + bonus;
    }

    void putData()
    {
        cout << "\nEmployee Details" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Total Salary: " << totalSalary << endl;
    }
};

int main()
{
    Employee e;

    e.getData();
    e.calculateSalary();
    e.putData();

    return 0;
}