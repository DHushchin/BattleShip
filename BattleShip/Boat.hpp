#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Boat
{
private:

    char dir;
    int length;
    vector<int> boatrow;
    vector<int> boatcol;
    int hits;
    string name;

public:

    //Default contstructor
    Boat(char d, int lgth, vector<int> r, vector<int> c, int hit, string name);

    //set boat hit
    void setHit();

    int checkSunk(int BoatSize);

    //get boat grid coordinates
    void boatCoordinates();

    //check coordinate bombed to find particular boat
    string getBoat(int r, int c);
};

