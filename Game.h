#ifndef GAME_H
#define GAME_H
#include "Tube.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Game{
private:
    int n;      // number of tubes, must be: 4 <= n < 20
    Game* prev;
public:
    Tube* tubes;

    Game();
    //Game(Game &g1);
    //explicit Game(int a);

    void setPrevious (Game *p) {prev=p;}
    Game *getPrevious() {return prev;}

    bool move(Game &n, int a, int b);

    void print();

    Game operator= (Game o);
    bool operator==(const Game& s) const;

    vector<Game *> expand();


    int getDepth();
    Game *getGoal();
};

#endif // GAME_H