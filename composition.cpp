// A university wants to maintain its departments and heads of departments (HoD).

// Each department has a name and a HoD.

// A HoD is an Employee with id and name.

// HoD cannot exist without the Department → Composition relationship.

// Tasks:

// Define a class Employee with id, name, and a display() method.

// Define a class Department with:

// name of the department

// HoD (as an Employee object)

// Parameterized constructor to initialize department name and HoD details

// Display() method to print department name and HoD name

// In main()

// Create one department Computer Science with HoD "Dr. Ghufran", id=1234

// Display department and HoD information

// Note: Use composition: HoD exists only as part of the Department.

#include <iostream>
using namespace std;

class employee
{
    int id;
    string name;

public:
    employee(int i , string n) : id(i) , name(n){}

    void display()
    {
        cout << "id : " << id << "name : " << name << endl;
    }
};

class department
{
    string deptname;
    employee hod;

    public :
    department(string n, employee h) : deptname(n), hod(h) {};

    void display()
    {
        cout << "dept name : " << deptname << endl;
        hod.display();
    }
};

int main()
{
    employee h1(1234 , "dr.ghufran") ;
    department d1("cs" , h1) ;

    d1.display();

    return 0 ;
}