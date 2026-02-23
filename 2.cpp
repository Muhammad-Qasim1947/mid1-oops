// Q2. In the world of Al, let's make a robot that cleans the house by taking x, y position. A robot
// has information of its current position as an x-axis point (left and right) and y-axis point (forward
// and reverse). The Robot can move Left, Right, Forward and Backwards. For this purpose, the robot has the following methods: [25 min, 6+6 Marks]

// moveLeft that moves the robot from the current position to the left for 'd' distance.
// moveRight that moves the robot from the current position to the right for 'd' distance.
// moveForward that moves the robot forward for 'd' distance.
// moveReverse that moves the robot backwards for 'd' distance.

// a. Write a program that includes Robot class with appropriate variables and functions. Do
// include default and parameterized constructors with default values. Must include a copy
// constructor that can be used to copy values of an object and assigned to another. Just
// for the fun of it, copy constructor creates an opposite image of existing object, i.e.
// assignment of x to y and y to x. Depending on the variable type and code requirements,
// define accessor/ mutator functions.
// b. Write a member function void commands (string act, int d) that moves the robot by
// reading each character from the string. For example, act = "RRLF" then there are four actions, and the
// actions will move robot in right direction with d points, then right
// direction with d points, then left direction with d points, then forward direction with d
// points. Following is the character-wise action: [L for moveLeft, R for moveRight, F for
// moveForward, B for moveReverse].

#include <iostream>
using namespace std;

class robot
{
    int x, y;

public:
    // Default constructor
    robot()
    {
        x = 0;
        y = 0;
    }

    // Parameterized constructor with default values
    robot(int XPos = 0, int YPos = 0)
    {
        x = XPos;
        y = YPos;
    }

    // Copy constructor
    robot(const robot &obj)
    {
        x = obj.y;
        y = obj.x;
    }

    // Accessors
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }

    // Mutators
    int setx(int xpos)
    {
        x = xpos;
    }
    int sety(int ypos)
    {
        y = ypos;
    }

    // movement functions
    void moveLeft(int d)
    {
        x -= d;
    }

    void moveRight(int d)
    {
        x += d;
    }

    void moveForward(int d)
    {
        y += d;
    }

    void moveReverse(int d)
    {
        y -= d;
    }

    void commands(string act, int d)
    {
        for (int i = 0; i < act.length(); i++)
        {
            char ch = act[i];

            if (ch == 'L')
                moveLeft(d);
            else if (ch == 'R')
                moveRight(d);
            else if (ch == 'F')
                moveForward(d);
            else if (ch == 'B')
                moveReverse(d);
        }
    }

    void display()
    {
        cout << "Robot Position: (" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    robot r1(10, 20);

    r1.commands("RRLF", 5);
    r1.display();

    // Copy constructor (opposite image)
    robot r2 = r1;
    r2.display();

    return 0;

}