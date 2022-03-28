#include "Labyrinth.h"
int countItem = 0;
bool ifValid = true;
bool legal(MazeCell* current, const std::string& moves){
    //If it goes north and if it is valid
    if(moves[0] == 'N' && current->north != nullptr){
        //If the next move in "moves" tries to a cell wall that is set to nullptr then the move
        //is not legal
        current = current->north;
        if(moves[1] == 'N' && current->north == nullptr){
            return false;
        }
        if(moves[1] == 'E' && current->east == nullptr){
            return false;
        }
        if(moves[1] == 'W' && current->west == nullptr){
            return false;
        }

    }
    if(moves[0] == 'S' && current->south != nullptr){
        //If the next move in "moves" tries to a cell wall that is set to nullptr then the move
        //is not legal
        current = current->north;
        if(moves[1] == 'S' && current->south == nullptr){
            return false;
        }
        if(moves[1] == 'E' && current->east == nullptr){
            return false;
        }
        if(moves[1] == 'W' && current->west == nullptr){
            return false;
        }

    }
    if(moves[0] == 'E' && current->east != nullptr){
        //If the next move in "moves" tries to a cell wall that is set to nullptr then the move
        //is not legal
        current = current->north;
        if(moves[1] == 'N' && current->north == nullptr){
            return false;
        }
        if(moves[1] == 'E' && current->east == nullptr){
            return false;
        }
        if(moves[1] == 'S' && current->south == nullptr){
            return false;
        }

    }
    if(moves[0] == 'W' && current->west != nullptr){
        //If the next move in "moves" tries to a cell wall that is set to nullptr then the move
        //is not legal
        current = current->north;
        if(moves[1] == 'N' && current->north == nullptr){
            return false;
        }
        if(moves[1] == 'S' && current->south == nullptr){
            return false;
        }
        if(moves[1] == 'W' && current->west == nullptr){
            return false;
        }

    }
    //return true if none of these condition are met
    return true;
}
bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    /* TODO: Delete this comment and the remaining lines, then implement this function. */
    if(countItem == 3 && moves.length() == 0){
        return true;
    }
    if(!legal(start, moves)){
        return false;
    }
    if(start->whatsHere != Item::NOTHING){
        countItem++;
    }
    if(moves[0] == 'N' && start->north != nullptr){
        isPathToFreedom(start->north, moves.substr(1,moves.length()-1));
    }
    if(moves[0] == 'S' && start->south != nullptr){
        isPathToFreedom(start->south, moves.substr(1,moves.length()-1));
    }
    if(moves[0] == 'E' && start->east != nullptr){
        isPathToFreedom(start->east, moves.substr(1,moves.length()-1));
    }
    if(moves[0] == 'W' && start->west != nullptr){
        isPathToFreedom(start->west, moves.substr(1,moves.length()-1));
    }
    return false;
}