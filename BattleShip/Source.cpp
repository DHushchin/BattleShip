#include <SFML/Graphics.hpp>
#include "Boat.hpp"
#include "Map.hpp"


/*
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;


struct statistics {
    bool gameInProgress;
    int row;
    int col;
    int guess;
    int hit;
    int miss;
    int space;
    string boatname;
    int sunk = 0;
    statistics() {
        bool gameInProgress = true;
        int row = 0;
        int col = 0;
        int guess = 0;
        int hit = 0;
        int miss = 0;
        int space = 0;
        string boatname = "";
        int sunk = 0;
    }
    statistics(const statistics& other) {
        this->gameInProgress = other.gameInProgress;
        this->row = other.row;
        this->col = other.col;
        this->guess = other.guess;
        this->hit = other.hit;
        this->miss = other.miss;
        this->space = other.space;
        this->boatname = other.boatname;
        this->sunk = other.sunk;
    }
};


void playGame(int CompMap[][10], vector<Boat>& CompBoatList, int UserMap[][10], vector<Boat>& UserBoatList);
int getSpace(int map[][10], int row, int col);
void findCoord(int& row, int& col);
void UserStrike(int map[][10], vector<Boat>& boatList, int& row, int& col, int& space, int& guess, int& miss, int& hit, int& sunk, string& boatname, bool& gameInProgress);


int main()
{
    int CompMap[10][10];
    int UserMap[10][10];
    vector<Boat> CompBoatList;
    vector<Boat> UserBoatList;
    string play;
    initGrid(CompMap);
    initGrid(UserMap);
    //printBoard(map); // uncomment to see initialised map
    setBoat(CompMap, Carrier, 1, CompBoatList);  
    setBoat(CompMap, Battleship, 2, CompBoatList);
    setBoat(CompMap, Battleship, 3, CompBoatList);
    setBoat(CompMap, Destroyer, 4, CompBoatList);
    setBoat(CompMap, Destroyer, 5, CompBoatList);
    setBoat(CompMap, Destroyer, 6, CompBoatList);
    setBoat(CompMap, Submarine, 7, CompBoatList);
    setBoat(CompMap, Submarine, 8, CompBoatList);
    setBoat(CompMap, Submarine, 9, CompBoatList);
    setBoat(CompMap, Submarine, 10, CompBoatList);

    setBoat(UserMap, Carrier, 1, UserBoatList);
    setBoat(UserMap, Battleship, 2, UserBoatList);
    setBoat(UserMap, Battleship, 3, UserBoatList);
    setBoat(UserMap, Destroyer, 4, UserBoatList);
    setBoat(UserMap, Destroyer, 5, UserBoatList);
    setBoat(UserMap, Destroyer, 6, UserBoatList);
    setBoat(UserMap, Submarine, 7, UserBoatList);
    setBoat(UserMap, Submarine, 8, UserBoatList);
    setBoat(UserMap, Submarine, 9, UserBoatList);
    setBoat(UserMap, Submarine, 10, UserBoatList);

    cout << "Welcome to Battleship game. Press \"PLAY\" to play the game" << endl << endl;
    cout << "The board will show a \'5\' for a hit and a \'9\' for a miss" << endl << endl;
    cin >> play; cout << endl;
    if (play == "PLAY")
    {
        playGame(CompMap, CompBoatList, UserMap, UserBoatList);
    }
    return 0;
}



void playGame(int CompMap[][10], vector<Boat>& CompBoatList, int UserMap[][10], vector<Boat>& UserBoatList)
{
    statistics Comp;
    statistics User;

    while (Comp.gameInProgress && User.gameInProgress)
    {
        printGameMap(UserMap, "User: ");
        printGameMap(CompMap, "Computer: ");
        //printMap(UserMap);
        //printMap(CompMap);
        UserStrike(UserMap, UserBoatList, User.row, User.col, User.space, User.guess, User.miss, User.hit, User.sunk, User.boatname, User.gameInProgress);
        //CompStrike();

    }//end of while game is playing loop

    if (!Comp.gameInProgress)
        cout << "Thank you for playing! You have sunk all my battleships in " << User.guess << " moves!" << endl;
    else
        cout << "Thank you for playing! I have sunk all your battleships in " << Comp.guess << " moves!" << endl;
}//end of playGame function

int getSpace(int map[][10], int row, int col)
{
    return map[row][col];
}

void findCoord(int& row, int& col) {
    cout << "Enter a row coordinate: ";
    cin >> row;
    cout << "Enter a column coordinate: ";
    cin >> col;
    cout << endl;
}


void UserStrike(int map[][10], vector<Boat>& boatList, int& row, int& col, int& space, int& guess, int& miss, int& hit, int& sunk, string& boatname, bool& gameInProgress) {
    findCoord(row, col);
    space = getSpace(map, row, col);

    while (space == 5) {
        findCoord(row, col);
        space = getSpace(map, row, col);
    }
    guess++;

    switch (space)
    {
    case 0:
        cout << "You have missed" << endl;
        map[row][col] = 9;
        miss++;
        break;
    case 1:
        map[row][col] = 5;
        hit++;

        boatname = boatList[6].getBoat(row, col);  //Check to see if boat is Submarine 1
        if (boatname == "Submarine 1")
        {
            cout << "You have bombed " << boatname << "!" << endl;
            boatList[6].setHit();
            sunk = boatList[6].checkSunk(Submarine);
            if (sunk == 9)
            {
                cout << "You have sunk Submarine 1." << endl;
            }
        }
        else if (boatname.empty())
        {
            boatname = boatList[7].getBoat(row, col);  //Check to see if boat is Submarine 2
            if (boatname == "Submarine 2")
            {
                cout << "You have bombed " << boatname << "!" << endl;
                boatList[7].setHit();
                sunk = boatList[7].checkSunk(Submarine);
                if (sunk == 9)
                {
                    cout << "You have sunk Submarine 2." << endl;
                }
            }
            else if (boatname.empty())
            {
                boatname = boatList[8].getBoat(row, col);  //Check to see if boat is Submarine 3
                cout << "You have bombed " << boatname << "!" << endl;
                boatList[8].setHit();
                sunk = boatList[8].checkSunk(Submarine);
                if (sunk == 9)
                {
                    cout << "You have sunk Submarine 3." << endl;
                }
            }
            else if (boatname.empty())
            {
                boatname = boatList[9].getBoat(row, col);  //Check to see if boat is Submarine 4
                cout << "You have bombed " << boatname << "!" << endl;
                boatList[9].setHit();
                sunk = boatList[9].checkSunk(Submarine);
                if (sunk == 9)
                {
                    cout << "You have sunk Submarine 4." << endl;
                }
            }
        }
        boatname.clear();
        break;
    case 2:
        map[row][col] = 5;
        hit++;
        boatname = boatList[3].getBoat(row, col);  //Check to see if boat is Destroyer 1
        if (boatname == "Destroyer 1")
        {
            cout << "You have bombed " << boatname << "!" << endl;
            boatList[3].setHit();
            sunk = boatList[3].checkSunk(Destroyer);
            if (sunk == 9)
            {
                cout << "You have sunk Destroyer 1." << endl;
            }
        }
        else if (boatname.empty())
        {
            boatname = boatList[4].getBoat(row, col);  //Check to see if boat is Destroyer 2
            if (boatname == "Destroyer 2")
            {
                cout << "You have bombed " << boatname << "!" << endl;
                boatList[4].setHit();
                sunk = boatList[4].checkSunk(Destroyer);
                if (sunk == 9)
                {
                    cout << "You have sunk Destroyer 2." << endl;
                }
            }
            else if (boatname.empty())
            {
                boatname = boatList[5].getBoat(row, col);  //Check to see if boat is Destroyer 3
                cout << "You have bombed " << boatname << "!" << endl;
                boatList[5].setHit();
                sunk = boatList[5].checkSunk(Destroyer);
                cout << "sunk is " << sunk << endl;
                if (sunk == 9)
                {
                    cout << "You have sunk Destroyer 3." << endl;
                }
            }
        }
        boatname.clear();
        break;
    case 3:
        map[row][col] = 5;
        hit++;

        boatname = boatList[1].getBoat(row, col);  //Check to see if boat is Battleship 1
        if (boatname == "Battleship 1")
        {
            cout << "You have bombed " << boatname << "!" << endl;
            boatList[1].setHit();
            sunk = boatList[1].checkSunk(Battleship);
            if (sunk == 9)
            {
                cout << "You have sunk Battleship 1." << endl;
            }
        }
        if (boatname.empty())
        {
            boatname = boatList[2].getBoat(row, col);  //Check to see if boat is Battleship 2
            cout << "You have bombed " << boatname << "!" << endl;
            boatList[2].setHit();
            sunk = boatList[2].checkSunk(Battleship);
            if (sunk == 9)
            {
                cout << "You have sunk Battleship 2." << endl;
            }
        }
        boatname.clear();
        break;
    case 4:
        cout << "You have bombed the aircraft carrier! " << endl;
        map[row][col] = 5;
        hit++;
        boatList[0].setHit();
        sunk = boatList[0].checkSunk(Carrier);
        if (sunk == 9) cout << "You have sunk the aircraft carrier." << endl;
        break;
    }//end of switch
    if (hit == 30) {
        gameInProgress = false;
    }
}