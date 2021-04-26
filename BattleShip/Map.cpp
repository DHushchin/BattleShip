#include "Map.hpp"


using namespace std;

void initGrid(int map[][10])
{
    for (int col = 0; col < 10; col++) //Outer column loop
    {
        for (int row = 0; row < 10; row++) //Inner row loop
        {
            map[col][row] = 0;
        }
    }
}

void printMap(int map[][10])  //Print the board with the boats placed on it
{
    cout << "   0|1|2|3|4|5|6|7|8|9" << endl << endl;
    for (int i = 0; i < 10; i++)  //column loop
    {
        for (int j = 0; j < 10; j++)  //row loop
        {
            if (j == 0)
            {
                cout << i << "  "; //print row number and spaces before new row
            }
            cout << map[i][j];
            if (j != 9)
            {
                cout << "|";
            }
        }
        cout << endl; //new line at end of column
    }
    cout << endl;
}

void printGameMap(int map[][10], string player) //This is the board that is printed for playing the game.  You cannot see the boats
{
    cout << player << endl;
    cout << "   0|1|2|3|4|5|6|7|8|9" << endl << endl;
    for (int i = 0; i < 10; i++)  //column loop
    {
        for (int j = 0; j < 10; j++)  //row loop
        {
            if (j == 0) cout << i << "  "; //print row number and spaces before new row           
            if (map[i][j] == 5) cout << 5; //if the space is a hit, print it           
            else if (map[i][j] == 9) cout << 9; //if the space is a miss, print it           
            else cout << 0;  //otherwise, just print a 0
            if (j != 9) cout << "|";
        }
        cout << endl; //new line at end of column
    }
    cout << endl;
}

bool setBoat(int map[][10], int BoatSize, int name, vector<Boat>& boatList)
//This function places the individual boats onto the initialised grid
{
    int col = 0;
    int row = 0;
    char dir = 'v';
    bool placementFailure = true;
    char check = 'v';
    int cS = 0;

    dir = getDirection(rand() % 2);  //randomly pick which direction to place boat
    col = resetColAndRow(col, row, BoatSize, dir);  //This function returns a random column and row (by reference) of where to place the boat

    while (placementFailure)
    {
        if (dir == 'h')
        {
            cS = checkSpaces(map, col, row, BoatSize, dir);//check to make sure the boat can be placed without overlapping another boat
            if (cS == 1)//if the boat overlaps, generate another random column, row and direction and start the loop again
            {
                dir = getDirection(rand() % 2);
                col = resetColAndRow(col, row, BoatSize, dir);
                cS = 0;
                continue;
            }
            editMap(map, col, row, BoatSize, dir);//place the boat on the grid
            editBoatInfo(map, col, row, BoatSize, dir, boatList, name);//create the boat object
            return 0;
        }//end of 'if horizontal'
        else if (dir == 'v')
        {
            cS = checkSpaces(map, col, row, BoatSize, dir);
            if (cS == 1)
            {
                dir = getDirection(rand() % 10);
                col = resetColAndRow(col, row, BoatSize, dir);
                cS = 0;
                continue;
            }
            editMap(map, col, row, BoatSize, dir);
            editBoatInfo(map, col, row, BoatSize, dir, boatList, name);
            return 0;
        }
    }//end of while loop
}//end of setBoat function

char getDirection(int d)
{
    if (d == 0) return 'h';  //randomly pick which direction to place boat
    else return 'v';
}

void editMap(int map[][10], int col, int row, int BoatSize, char dir)
//This function puts the numbers that correspond to the boat type on the grid
{
    if (dir == 'h')
    {
        for (int i = 0; i < BoatSize; i++)
        {
            map[row][col++] = BoatSize;
            cout << endl;
        }
    }
    else if (dir == 'v')
    {
        for (int i = 0; i < BoatSize; i++)
        {
            map[row++][col] = BoatSize;
            cout << endl;
        }
    }
    else
    {
        cout << "Error!  No direction passed" << endl;
    }
    //printBoard(grid);  //uncomment to see finished grid
}

int checkSpaces(int map[][10], int col, int row, int size, char d)
//check the grid to make sure that none of the boats will overlap
{
    int check = 0;
    if (d == 'h')
    {
        for (int i = col; i < col + size; i++)
        {
            check = map[row][i];
            if (check != 0) return 1;
        }

        return 0;
    }
    else
    {
        for (int i = row; i < row + size; i++)
        {
            check = map[i][col];
            if (check != 0) return 1;
        }

        return 0;
    }
}

int resetColAndRow(int col, int& row, int BoatSize, char d)
{
    switch (BoatSize) //Generate random column and row based on boat size so we don't go over the edge of the grid
    {
    case Submarine:
        if (d == 'h')
        {
            col = rand() % 10;
            row = rand() % 10;
        }
        else
        {
            col = rand() % 10;
            row = rand() % 10;
        }
        break;
    case Destroyer:
        if (d == 'h')
        {
            col = rand() % 9;
            row = rand() % 10;
        }
        else
        {
            col = rand() % 10;
            row = rand() % 9;
        }
        break;
    case Battleship:
        if (d == 'h')
        {
            col = rand() % 8;
            row = rand() % 10;
        }
        else
        {
            col = rand() % 10;
            row = rand() % 8;
        }
        break;
    case Carrier:
        if (d == 'h')
        {
            col = rand() % 7;
            row = rand() % 10;
        }
        else
        {
            col = rand() % 10;
            row = rand() % 7;
        }
    }
    return col;
}

void editBoatInfo(int map[][10], int col, int row, int BoatSize, char d, vector<Boat>& boatList, int name)
//This function creates the boat objects
{
    switch (name)
    {
    case 1: //4
        if (d == 'h')
        {
            vector<int> r1(4);
            // put coordinate data into the vectors using at()
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
            }
            vector<int> c1(4);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
                col++;
            }
            //Aircraft Carrier
            Boat carrierBoat('h', 4, r1, c1, 0, "Aircraft Carrier");
            boatList.push_back(carrierBoat);
        }
        else if (d == 'v')
        {
            vector<int> r1(5);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
                row++;
            }
            vector<int> c1(5);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
            }
            //Aircraft Carrier
            Boat carrierBoat('v', 4, r1, c1, 0, "Aircraft Carrier");
            boatList.push_back(carrierBoat);
        }
        break;
    case 2: //3
        if (d == 'h')
        {
            vector<int> r1(3);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
            }
            vector<int> c1(3);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
                col++;
            }
            //Battleship 1
            Boat battleship1Boat('h', 3, r1, c1, 0, "Battleship 1");
            boatList.push_back(battleship1Boat);
        }
        else if (d == 'v')
        {
            vector<int> r1(3);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
                row++;
            }
            vector<int> c1(3);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
            }
            //Battleship 1
            Boat battleship1Boat('v', 3, r1, c1, 0, "Battleship 1");
            boatList.push_back(battleship1Boat);
        }
        break;
    case 3: //3
        if (d == 'h')
        {
            vector<int> r1(3);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
            }
            vector<int> c1(3);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
                col++;
            }
            //Battleship 2
            Boat battleship2Boat('h', 3, r1, c1, 0, "Battleship 2");
            boatList.push_back(battleship2Boat);
        }
        else if (d == 'v')
        {
            vector<int> r1(3);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
                row++;
            }
            vector<int> c1(3);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
            }
            //Battleship 2
            Boat battleship2Boat('v', 3, r1, c1, 0, "Battleship 2");
            boatList.push_back(battleship2Boat);
        }
        break;
    case 4: //2
        if (d == 'h')
        {
            vector<int> r1(2);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
            }
            vector<int> c1(2);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
                col++;
            }
            //Destroyer 1
            Boat destroyer1Boat('h', 2, r1, c1, 0, "Destroyer 1");
            boatList.push_back(destroyer1Boat);
        }
        else if (d == 'v')
        {
            vector<int> r1(2);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
                row++;
            }
            vector<int> c1(2);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
            }
            //Destroyer 1
            Boat destroyer1Boat('v', 2, r1, c1, 0, "Destroyer 1");
            boatList.push_back(destroyer1Boat);
        }
        break;
    case 5: //2
        if (d == 'h')
        {
            vector<int> r1(2);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
            }
            vector<int> c1(2);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
                col++;
            }
            //Destroyer 2
            Boat destroyer2Boat('h', 2, r1, c1, 0, "Destroyer 2");
            boatList.push_back(destroyer2Boat);
        }
        else if (d == 'v')
        {
            vector<int> r1(2);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
                row++;
            }
            vector<int> c1(2);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
            }
            //Destroyer 2
            Boat destroyer2Boat('v', 2, r1, c1, 0, "Destroyer 2");
            boatList.push_back(destroyer2Boat);
        }
        break;
    case 6: //2
        if (d == 'h')
        {
            vector<int> r1(2);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
            }
            vector<int> c1(2);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
                col++;
            }
            //Destroyer 3
            Boat destroyer3Boat('h', 2, r1, c1, 0, "Destroyer 3");
            boatList.push_back(destroyer3Boat);
        }
        else if (d == 'v')
        {
            vector<int> r1(2);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
                row++;
            }
            vector<int> c1(2);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
            }
            //Destroyer 3
            Boat destroyer3Boat('v', 2, r1, c1, 0, "Destroyer 3");
            boatList.push_back(destroyer3Boat);
        }
        break;
    case 7: //1
        if (d == 'h')
        {
            vector<int> r1(1);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
            }
            vector<int> c1(1);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
                col++;
            }
            //Submarine1
            Boat submarine1Boat('h', 1, r1, c1, 0, "Submarine 1");
            boatList.push_back(submarine1Boat);
        }
        else if (d == 'v')
        {
            vector<int> r1(1);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
                row++;
            }
            vector<int> c1(1);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
            }
            //Submarine 1
            Boat submarine1Boat('v', 1, r1, c1, 0, "Submarine 1");
            boatList.push_back(submarine1Boat);
        }
        break;
    case 8: //1
        if (d == 'h')
        {
            vector<int> r1(1);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
            }
            vector<int> c1(1);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
                col++;
            }
            //Submarine 2
            Boat submarine2Boat('h', 1, r1, c1, 0, "Submarine 2");
            boatList.push_back(submarine2Boat);
        }
        else if (d == 'v')
        {
            vector<int> r1(1);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
                row++;
            }
            vector<int> c1(1);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
            }
            //Submarine 2
            Boat submarine2Boat('v', 1, r1, c1, 0, "Submarine 2");
            boatList.push_back(submarine2Boat);
        }
        break;
    case 9: //1
        if (d == 'h')
        {
            vector<int> r1(1);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
            }
            vector<int> c1(1);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
                col++;
            }
            //Submarine 3
            Boat submarine3Boat('h', 1, r1, c1, 0, "Submarine 3");
            boatList.push_back(submarine3Boat);
        }
        else if (d == 'v')
        {
            vector<int> r1(1);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
                row++;
            }
            vector<int> c1(1);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
            }
            //Submarine 3
            Boat submarine3Boat('v', 1, r1, c1, 0, "Submarine 3");
            boatList.push_back(submarine3Boat);
        }
        break;
    case 10: //1
        if (d == 'h')
        {
            vector<int> r1(1);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
            }
            vector<int> c1(1);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
                col++;
            }
            //Submarine 4
            Boat submarine4Boat('h', 1, r1, c1, 0, "Submarine 4");
            boatList.push_back(submarine4Boat);
        }
        else if (d == 'v')
        {
            vector<int> r1(1);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = row;
                row++;
            }
            vector<int> c1(1);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = col;
            }
            //Submarine 4
            Boat submarine4Boat('v', 1, r1, c1, 0, "Submarine 4");
            boatList.push_back(submarine4Boat);
        }
        break;
    }
}