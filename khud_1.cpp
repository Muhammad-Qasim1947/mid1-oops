// Q1. Suppose you’re working with the DECS society to arrange an  annual  picnic. You are required  to
// store specific information, like, the total budget and the remaining budget for the picnic, total number of
// tickets, number of tickets sold, a list of names of faculty members and students attending the picnic, etc.
// Create a class for PicnicManagement which will help the society with their budgeting and ticketing
// process.

// a. Create member variables, accessors and mutators, default and parameterized constructors with
// the following constraints:
// ● The total number of tickets, and total budget should not change once they have been
// initialized. The default number of tickets should be 2,000. The default total budget
// should be 2,000,000/=
// ● Any changes made to the budget remaining, number of tickets sold, list of students and
// faculty is to be reflected to anyone who is using the system.
// ● The number of tickets and budget should not be negative. In case of wrong inputs,
// default values should be used.

// b. Write a member function called bool utilizeFunds(int amount) which can be used by the EM
// team to book beach, lodges, etc. When using this function, the EM member has to specify what
// reason they are using the fund for, and how much amount is being used. These funds should be
// deducted from the remaining budget. If the funds exceed the remaining budget, and appropriate
// message should be displayed and false should be returned.

// c. Write a member function called int sellTicket(int amount) which can be used by contact persons
// to sell tickets. A maximum of two, and a minimum one ticket can be sold at a time. Whenever a
// ticket is sold, it should add 1,500/= to the remaining budget. During the function call, if the
// number of tickets remaining is lesser than the number of tickets to sell, it should sell the
// maximum possible tickets and then return the number of tickets that were not sold. (If I want to
// sell 2 tickets, and there is only 1 ticket left, it should sell me the 1 ticket and return 1)

#include <iostream>
using namespace std;

class picnic
{
    // These should NOT change once initialized
    const int totalTickets;
    const int totalBudget;

    // These should reflect changes to everyone
    static int remainingBudget;
    static int ticketsSold;
    static string Students[3];
    static string Faculty[3];
    static int Scount;
    static int Fcount;

public:
    picnic() : totalTickets(2000), totalBudget(2000000)
    {
        remainingBudget = totalBudget;
        ticketsSold = 0;
    }

    picnic(int ticket, int budget) : totalTickets(ticket > 0 ? ticket : 2000), totalBudget(budget > 0 ? budget : 2000000)
    {
        remainingBudget = totalBudget;
        ticketsSold = 0;
    }

    static void addfaculty(string name)
    {
        Faculty[Fcount++] = name;
    }

    static void addstudent(string name)
    {
        Students[Scount++] = name;
    }

    bool utilizefunds(int amount, string reason)
    {
        if (amount <= 0)
        {
            cout << "Invalid" << endl;
        }

        else if (amount > remainingBudget)
        {
            cout << "Insufficient funds" << endl;
            return false;
        }

        else
        {
            remainingBudget -= amount;
            cout << "The Amount Used : " << amount << " For " << reason <<endl;
            return true;
        }
    }

    int selltickets(int amount)
    {
        if (amount > 2)
        {
            amount = 2;
        }

        if (amount < 1)
        {
            amount = 1;
        }

        int remainingtickets = totalTickets - ticketsSold;

        if (remainingtickets <= 0)
        {
            cout << "No Tickets Remaining" << endl;
            return amount ;
        }

        if (amount > remainingtickets)
        {
            ticketsSold += remainingtickets;
            remainingBudget += remainingtickets * 1500;
            return amount - remainingtickets;
        }

        ticketsSold += amount;
        remainingBudget += amount * 1500;

        return 0; // all requested tickets sold ;
    }
};

int picnic::ticketsSold = 0;
int picnic::remainingBudget = 0;
string picnic::Students[3] = {"Qasim", "Yash", "Mahboor"};
string picnic::Faculty[3] = {"Ali", "Sara", "Abeeha"};
int picnic::Scount = 3;
int picnic::Fcount = 3;

int main()
{
    picnic p;

    cout << "Remaining tickets not sold: " << p.selltickets(2) << endl;

    p.utilizefunds(500000, "Beach Booking");

    // Add student
    picnic::addstudent("Nida");
    picnic::addfaculty("Bakhtawar");

    return 0;
}