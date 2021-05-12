#include "AI.hpp"

Computer::Computer() {
    i = j = prev_i = prev_j = -1;
    isHit = false;
    dir = Direction::up;
    PrevSunk = true;
    sunk = 0;
}


bool Computer::Strike(Map& UserMap) {

    DetectCoords(UserMap);
    while (i < 0 || i >= 10 || j < 0 || j >= 10) {
        ChangeDirection();
        DetectCoords(UserMap);
    }

    isHit = UserMap.Strike(i, j);

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
    else if (!isHit && !PrevSunk) {
        ChangeDirection();
    }

    return isHit;
}

void Computer::DetectCoords(Map& UserMap){
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