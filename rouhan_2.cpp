// Q2. Let’s say you’re working on a game called “Space Invaders”. Multiple players can play this game, and
// the game itself  stores the  top three scores achieved by players. Create a class  for  your  game  with  the
// following constraints:
// a. Following attributes and functionalities are available in your game:
// ● A list of high scores
// ● A list of usernames who scored these high scores
// ● Username (of the current user playing the game)
// ● Score (of the current user playing the game)
// ● Constructors to initialize the initial score to 0. Default name should be “Player 1” if not
// specified by the user.
// ● A function to display the high scores
// ● A function to play the game
// b. Provide proper functionality for the following two functions:
// ● void displayHighScore() – Should show a list of usernames and their high scores.
// Everyone should be able to see the highest scores obtained.
// ● Void playGame() – Should allow the user to play the game – you don’t have to provide
// functionality for gameplay – the function should generated a score(you can use the
// random function). This score is to be compared with the existing high scores. If the score
// is higher than any of the high scores, the ranking should be updated accordingly.
// For example:
// The current ranking is:
// 1. Abeeha 9,999
// 2. Bakhtawer 8,888
// 3. Nida 7,777
// If the current player “XYZ” scores a 9,000 – The updated high score should be:
// 1. Abeeha 9,999
// 2. XYZ 9,000
// 3. Bakhtawer 8,888
// c. Write a main function that will produce the following output by making use of your designed
// class, members, functions and objects:
// 1. Abeeha 9,999
// 1. YourName 10,000
// 2. XYZ 9,000
// 2. Abeeha 9,999
// 3. Bakhtawer 8,888
// 3. XYZ 9,000

#include <iostream>
using namespace std;

class spaceinvaders
{
public:
    int highscores[3];
    string usernames[3];
    string currentusername;
    int currentscore;

    

    spaceinvaders(string name, int currentsc) : currentusername(name), currentscore(currentsc)
    {
        for (int i = 0; i < 3; i++)
        {
            highscores[i] = 0;
            usernames[i] = "None" ;
        }
    }

    void displayhighscores()
    {
        cout << "====High Scores====" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "username : " << usernames[i] << endl;
            cout << "highscores : " << highscores[i] << endl;
        }
    }

    void playgame()
    {
        currentscore = 9000;
        cout << currentusername << " Scored : " << currentscore << endl;

        for (int i = 0; i < 3; i++)
        {
            if (currentscore > highscores[i])
            {
                for (int j = 2; j > i; j--)
                {
                    highscores[j] = highscores[j - 1];
                    usernames[j] = usernames[j - 1];
                }

                highscores[i] = currentscore;
                usernames[i] = currentusername;
                break;
            }
        }
    }
};

int main()
{

    spaceinvaders player1("Qasim" , 0);
    spaceinvaders player2("Yash" , 0);

    player1.playgame();
    player1.displayhighscores();

    player2.playgame();
    player2.displayhighscores();
}