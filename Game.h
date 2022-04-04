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
    Tube* tubes;
public:
    Game();
    Game(int a);
    Game(const Game &g1);
    void setPrevious (Game *p) {prev=p;}
    Game *getPrevious() {return prev;}
    bool move(Game &n, int a, int b);
    void print();
    Game operator= (Game o);
    bool operator==(const Game& s) const;
    vector<Game *> expand();
    int getDepth();
    Game *getGoal();

    void getPath();
    void getPath(Game &game);

    string getKey();
};

#endif // GAME_H