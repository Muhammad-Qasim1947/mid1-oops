// Define a class Address

// Attributes: addressLine, city, state

// Parameterized constructor to initialize all attributes

// Define a class Employee

// Attributes: id, name, and a pointer to Address

// Parameterized constructor to initialize id, name, and assign the Address pointer

// setAddress(Address* address) → allows changing the employee’s address

// display() → prints employee id, name, and full address in the format:

// id name addressLine city state

// In main()

// Create two Address objects:

// a1: "C-146, Sec-15", "Karachi", "Sindh"

// a2: "A-146, Sec-10", "Lahore", "Punjab"

// Create one Employee object e1 with id=101, name="Ali", and address a1

// Display employee details

// Change employee address to a2 using setAddress()

// Display employee details again

#include <iostream>
using namespace std;

class Address
{
public:
    string addressline;
    string city;
    string state;

    Address(string al, string c, string s) : addressline(al), city(c), state(s) {}
};

class employee
{
    int id;
    string name;
    Address *address;

public:
    employee(int i, string n, Address *add)
    {
        id = i;
        name = n;
        address = add;
    }

    void setAddress(Address *add)
    {
        address = add ;
    }

    void display()
    {
        cout << " " << id << " " << name << endl;
        cout << " " << address->addressline << " " << address->city << " " << address->state << endl;
    }
};

int main()
{
    Address a1("C-146 , Sec-15", "Karachi", "Sindh");
    Address a2("A-146, Sec-10", "Lahore", "Punjab");

    employee e1(101, "Ali", &a1);
    e1.display();

    e1.setAddress(&a2);
    e1.display();

    return 0;
}