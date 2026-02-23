// Q3.
// "Netflix2" animation studio produces animated movies and aims to properly manage their
// "movie projects" and "staff". The studio works on many different movies projects and staff
// assigned to them. Write a program to perform the given tasks: [25 min, 5+5+2 Marks]
// a. To maintain information of a movie project. The movie information includes movie id,
// title, the total budget, and current cost of the movie. Moreover, each movie has two
// staff members, a project lead and chief animator. Apart from this, the movie project also
// has the following behavior: void Production (), This behavior allows project lead and
// chief animator to perform their assigned job and print that the task is in production. The
// class should have a global member that keeps track of total budget of all the movies
// created.
// b. Each staff information includes staffID, salary, employee type. Employee type can have
// only two possible values of project lead or chief animator. The class should have a global
// member that keeps track of total salaries of all the staff employed. Apart from this, an
// employee demonstrates the behavior double TrackProject (double currentCost) if the
// type of that employee is project lead. And double Animate (double currentCost) if the
// type of that employee is chief animator.
// i. Each time the chief animator animates, it adds PKR 10,000 to the current cost of
// the movie.
// ii. When a project lead tracks a project, he checks if the current cost of the movie is
// exceeding PKR 200,000. If it is exceeding budget, then he immediately shows a
// "warning: that cost is exceeding budget".
// c. Draw a UML / Class diagram that represents the above given system to highlight OOP
// features.

#include <iostream>
using namespace std;

class staff
{
    int staffid;
    int salary;
    string employeetype;

public:
    static double totalsalaries;

    staff(int i, int s, string et)
    {
        staffid = i;
        salary = s;
        employeetype = et;
        totalsalaries += salary;
    }

    double trackproject(double currentcost)
    {
        if (employeetype == "Project Lead")
        {
            if (currentcost > 200000)
            {
                cout << "Warning : that cost is exceeding budget";
            }
        }
        return currentcost;
    }

    double animate(double currentcost)
    {
        if (employeetype == "Chief Animator")
        {
            return currentcost + 10000;
        }
        return currentcost;
    }
};

double staff ::totalsalaries = 0;

class movieproject
{
    int movieid;
    string title;
    int totalbudget;

public:
    double currentcost;
    staff *projectlead;   // Reference to project lead
    staff *cheifanimator; // Reference to cheif animator
    static double globalTotalBudget;

    movieproject(int id, string t, int totalbud, staff *pl, staff *ca)
    {
        movieid = id;
        title = t;
        totalbudget = totalbud;
        currentcost = 0;
        projectlead = pl;   // VERY IMPORTANT
        cheifanimator = ca; // VERY IMPORTANT
        globalTotalBudget += totalbudget;
    }

    void setcost(double cost)
    {
        currentcost = cost;
    }

    void production()
    {
        cout << "Task is in production for movie: " << title << endl;

        currentcost = cheifanimator->animate(currentcost);
        projectlead->trackproject(currentcost);

        cout << "\nCurrent Cost: " << currentcost << endl;
    }
};

double movieproject::globalTotalBudget = 0;

int main()
{
    staff s1(101, 75000, "Project Lead");
    staff s2(102, 60000, "Chief Animator");

    movieproject m1(1999, "Mujhe Kyu Nikala", 500000, &s1, &s2);

    m1.setcost(250000);
    m1.production();

    return 0 ;
}