// Q3. Suppose you are developing a system for a University Hostel Management. The hostel contains
// multiple rooms, and each room contains furniture and residents. The system must store and manage
// information about hostel rooms, students living in them, and the furniture assigned to each room.
// You are required to design classes according to the following requirements.
// a) Class Design Requirements
// 1. Furniture (Composition Relationship)
// Each room has furniture that cannot exist independently of the room.
// Create a class Furniture with:
// ● Furniture type (Bed, Table, Chair)
// ● Quantity
// ● Constructor to initialize values
// ● A function to display furniture details

#include <iostream>
using namespace std;

class furniture
{
    string furnituretype;
    int quantity;

public:
    furniture(string ft, int q) : furnituretype(ft), quantity(q) {};

    void display()
    {
        cout << "furniture type :  " << furnituretype << " quantity : " << quantity << endl;
    }
};

class student
{
public:
    int studentid;
    string studentname;
    string dept;

    student(int sid, string stdname, string d) : studentid(sid), studentname(stdname), dept(d) {}

    void display()
    {
        cout << "student id :  " << studentid << " student name : " << studentname << " department : " << dept << endl;
    }
};

class room
{
public:
    int roomnum;
    int currentcount = 0;
    static int totalstudents;
    student *stud[4];
    furniture bed;
    furniture chair;
    furniture table;

    room(int rnum, furniture b, furniture c, furniture t) : roomnum(rnum), bed(b), chair(c), table(t) {}

    void addstudent(student *s)
    {
        if (currentcount < 4)
        {
            stud[currentcount++] = s;
            totalstudents++;
        }
        else
        {
            cout << "room is full" << endl;
        }
    }

    void removestudent(int studentid)
    {
        for (int i = 0; i < 4; i++)
        {
            if (stud[i]->studentid == studentid)
            {
                for (int j = i; j < currentcount - 1; j++)
                {
                    stud[j] = stud[j + 1];
                }
                currentcount--;
                totalstudents--;
                cout << "Student with ID " << studentid << " removed.\n";
                return;
            }
        }
        cout << "Student with ID " << studentid << " not found!\n";
    }

    void display()
    {
        cout << "==== Room No: " << roomnum << " ====\n";
        bed.display();
        chair.display();
        table.display();
        cout << "Residents:\n";
        for (int i = 0; i < currentcount; i++)
        {
            stud[i]->display();
        }
    }

    static void totalstud()
    {
        cout << "\nTotal students in all rooms: " << totalstudents << endl;
    }
};

int room ::totalstudents = 0;

int main()
{
    student s1(101, "qasim", "cs");
    student s2(102, "yash", "fintech");
    student s3(103, "mahboor", "ee");

    furniture f1("bed", 4);
    furniture f2("chair", 9);
    furniture f3("table", 2);

    room r1(804, f1, f2, f3);

    r1.addstudent(&s1);
    r1.addstudent(&s2);
    r1.addstudent(&s3);

    // Display room details
    r1.display();

    cout << "\nRemoving student with ID 102...\n";
    r1.removestudent(102); // remove Yash

    // Display again after removal
    r1.display();

    room::totalstud();

    return 0;
}