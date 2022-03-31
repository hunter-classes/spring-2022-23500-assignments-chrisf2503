#include "Labyrinth.h"
int countItem = 0;
bool ifValid = false;
bool legal(MazeCell* current, const std::string& moves){
    //If it goes north and if it is valid
    MazeCell* copy = current;
    if(moves[0] == 'N' && copy->north != nullptr){
        //If the next move in "moves" tries to a cell wall that is set to nullptr then the move
        //is not legal
        copy = current->north;
        if(moves[1] == 'N' && copy->north == nullptr){
            return false;
        }
        if(moves[1] == 'E' && copy->east == nullptr){
            return false;
        }
        if(moves[1] == 'W' && copy->west == nullptr){
            return false;
        }

    }
    if(moves[0] == 'S' && copy->south != nullptr){
        //If the next move in "moves" tries to a cell wall that is set to nullptr then the move
        //is not legal
        copy = current->south;
        if(moves[1] == 'S' && copy->south == nullptr){
            return false;
        }
        if(moves[1] == 'E' && copy->east == nullptr){
            return false;
        }
        if(moves[1] == 'W' && copy->west == nullptr){
            return false;
        }

    }
    if(moves[0] == 'E' && copy->east != nullptr){
        //If the next move in "moves" tries to a cell wall that is set to nullptr then the move
        //is not legal
        copy = current->east;
        if(moves[1] == 'N' && copy->north == nullptr){
            return false;
        }
        if(moves[1] == 'E' && copy->east == nullptr){
            return false;
        }
        if(moves[1] == 'S' && copy->south == nullptr){
            return false;
        }

    }
    if(moves[0] == 'W' && copy->west != nullptr){
        //If the next move in "moves" tries to a cell wall that is set to nullptr then the move
        //is not legal
        copy = current->west;
        if(moves[1] == 'N' && copy->north == nullptr){
            return false;
        }
        if(moves[1] == 'S' && copy->south == nullptr){
            return false;
        }
        if(moves[1] == 'W' && copy->west == nullptr){
            return false;
        }

    }
    //return true if none of these condition are met
    return true;
}
bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    /* TODO: Delete this comment and the remaining lines, then implement this function. */
    if(start->whatsHere != Item::NOTHING){
        countItem++;
    }
    if(countItem == 3){
        ifValid = true;
        return ifValid;
        exit(1);
    }
    if(!legal(start, moves)){
        return false;
    }
    if(moves[0] == 'N' && start->north != nullptr){
        isPathToFreedom(start->north, moves.substr(1,moves.length()-1));
        return ifValid;

    }
    if(moves[0] == 'S' && start->south != nullptr){
        isPathToFreedom(start->south, moves.substr(1,moves.length()-1));
        return ifValid;

    }
    if(moves[0] == 'E' && start->east != nullptr){
        isPathToFreedom(start->east, moves.substr(1,moves.length()-1));
        return ifValid;

    }
    if(moves[0] == 'W' && start->west != nullptr){
        isPathToFreedom(start->west, moves.substr(1,moves.length()-1));
        return ifValid;
    }
    return ifValid;
}