#ifndef GAME_H
#define GAME_H
#include "Tube.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Game{
private:
    int n;          // number of tubes, must be: 4 <= n < 20
    Game* prev;     // pointer to parent state
    Tube* tubes;    // pointer for the dynamic array of n-tubes of the problem
public:
    Game();         // default constructor
    Game(int a);    // constructor with an int parameter for the number of tubes
    Game(const Game &g1);   // copy constructor
    void setPrevious (Game *p) {prev=p;}    // setter for the parent state
    Game* getPrevious() {return prev;}      // getter for the parent state
    bool move(Game &game, int a, int b);    // sends color from tube-a to tube-b
    void print();                           // prints the state
    bool operator==(const Game& s) const;   // equals overload
    vector<Game *> expand();                // expand method to produce the child(ren) of this method
    string getKey();                        // returns the string key representation of the state
    int getDepth();                         // returns the depth of the state
    Game* getGoal();                        // returns the goal of the initial state
    void printPath(Game &game);               // prints the step-by-step solution of how we got to this state
};

#endif // GAME_H