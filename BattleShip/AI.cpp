#include "AI.hpp"

Computer::Computer() {
    i = j = prev_i = prev_j = -1;
    isHit = PrevHit = ChangeDir = FinishBoat = false;
    dir = Direction::up;
    PrevSunk = true;
    sunk = 0;
}


bool Computer::Strike(Map& UserMap, bool& isSunk) {
    ChangeDir = false;
    if (!FinishBoat && PrevHit)
        ChangeFireDirection();
    DetectCoords(UserMap);

    while (i < 0 || i > 9 || j < 0 || j > 9 || UserMap.getCell(i, j)->getBlocked()) {
        if (!FinishBoat)
            ChangeFireDirection();
        else {
            OppositeFireDirection(UserMap);
            break;
        }
        DetectCoords(UserMap);
    }

    isHit = UserMap.Strike(i, j, isSunk);

    if ((PrevHit && isHit && !PrevSunk) || (!PrevHit && isHit && !PrevSunk && ChangeDir))
        FinishBoat = true;

    if (isHit) {
        if (UserMap.getSunk() > sunk) {
            sunk++;
            PrevSunk = true;
            FinishBoat = false;
        }
        else {
            prev_i = i, prev_j = j;
            PrevSunk = false;
        }
    }

    PrevHit = isHit;
    return isHit;
}


void Computer::DetectCoords(Map& UserMap) {
    if (!PrevSunk) {
        switch (dir) {
        case Direction::up:
            i = prev_i - 1;
            j = prev_j;
            break;
        case Direction::down:
            i = prev_i + 1;
            j = prev_j;
            break;
        case Direction::right:
            i = prev_i;
            j = prev_j + 1;
            break;
        case Direction::left:
            i = prev_i;
            j = prev_j - 1;
            break;
        }
    }
    else {
        i = rand() % 10;
        j = rand() % 10;

        while (UserMap.getCell(i, j)->getBlocked()) {
            i = rand() % 10;
            j = rand() % 10;
        }
    }
}


void Computer::ChangeFireDirection() {
    switch (dir) {
    case Direction::up:
        dir = Direction::right;
        break;
    case Direction::right:
        dir = Direction::down;
        break;
    case Direction::down:
        dir = Direction::left;
        break;
    case Direction::left:
        dir = Direction::up;
        break;
    }
    ChangeDir = true;
}


void Computer::OppositeFireDirection(Map& UserMap) {
    if (dir == Direction::down) {
        do {
            --i;
        } while (UserMap.getCell(i, j)->getBlocked());
        dir = Direction::up;
    }
    else if (dir == Direction::up) {
        do {
            ++i;
        } while (UserMap.getCell(i, j)->getBlocked());
        dir = Direction::down;
    }
    else if (dir == Direction::left) {
        do {
            ++j;
        } while (UserMap.getCell(i, j)->getBlocked());
        dir = Direction::right;
    }
    else if (dir == Direction::right) {
        do {
            --j;
        } while (UserMap.getCell(i, j)->getBlocked());
        dir = Direction::left;
    }
}



