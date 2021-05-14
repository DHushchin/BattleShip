#include "AI.hpp"

Computer::Computer() {
    i = j = prev_i = prev_j = -1;
    isHit = PrevHit = Finish = ChangeDir = false;
    dir = Direction::up;
    PrevSunk = true;
    sunk = 0;
}


bool Computer::Strike(Map& UserMap, bool& isSunk) {
    ChangeDir - false;
    if (!PrevHit && !PrevSunk && !Finish) {
        ChangeDirection();
        ChangeDir = true;
    }
    DetectCoords(UserMap);
    while (i < 0 || i >= 10 || j < 0 || j >= 10 || UserMap.getCell(i, j)->getBlocked()) {
        if (!Finish && !PrevSunk) {
            ChangeDirection();
            ChangeDir = true;
        }
        DetectCoords(UserMap);
    }

    isHit = UserMap.Strike(i, j, isSunk);

    if (isHit) {
        if (UserMap.getSunk() > sunk) {
            sunk++;
            PrevSunk = true;
        }
        else {
            prev_i = i, prev_j = j;
            PrevSunk = false;
        }
    }
    
    if (PrevHit && !isHit && !ChangeDir)
        Finish = true;
    else
        Finish = false;
    PrevHit = isHit;
    return isHit;
}


void Computer::DetectCoords(Map& UserMap) {
    if (!PrevSunk && !Finish) {
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
    else if (!PrevSunk && Finish) {
        if (dir == Direction::down) {
            while (UserMap.getCell(i, j)->getBlocked()) {
                --i;
            }
        }
        else if (dir == Direction::up) {
            while (UserMap.getCell(i, j)->getBlocked()) {
                ++i;
            }
        }
        else if (dir == Direction::left) {
            while (UserMap.getCell(i, j)->getBlocked()) {
                ++j;
            }
        }
        else if (dir == Direction::right) {
            while (UserMap.getCell(i, j)->getBlocked()) {
                --j;
            }
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


void Computer::ChangeDirection() {
    switch (dir) {
    case Direction::up:
        dir = Direction::down;
        break;
    case Direction::down:
        dir = Direction::right;
        break;
    case Direction::right:
        dir = Direction::left;
        break;
    case Direction::left:
        dir = Direction::up;
        break;
    }
}

