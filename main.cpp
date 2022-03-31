#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <ctime>
#include "Game.h"
#include "Tube.h"
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

Game *BFS(Game *initial,Game *goal, long long &examined, long long &mem)
{
    queue<Game *> agenda;
    vector<Game> closed;

    agenda.push(initial);
    examined=0;
    mem=1;
    while (agenda.size()>0)
    {
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        Game *s = agenda.front();
        agenda.pop();
        if (find(closed.begin(), closed.end(), *s)==closed.end())
        {
            examined++;
            if (*s==*goal)
                return s;
            closed.push_back(*s);
            vector<Game *> children =s->expand();
            for (unsigned int i=0;i<children.size();i++)
            {
                if (find(closed.begin(), closed.end(), *children[i])==closed.end())
                    agenda.push(children[i]);
            }
        }
    }
    return nullptr;
}


int main(){
    long long mem,examined;

    Game* game = new Game();

    //game -> move(*game, 0, 2);
    //game -> move(*game, 0, 3);
    //game -> move(*game, 1, 3);
    //game -> move(*game, 1, 0);
    //game -> move(*game, 1, 3);
    //game -> move(*game, 0, 2);
    //game -> move(*game, 1, 2);
    //game -> move(*game, 1, 3);


    Game* goal;
    goal = game->getGoal();

    if(*goal==*game)
        cout << "yes!";

    cout<<endl<<"BFS: ";
    Game* bsol;
    bsol=BFS(game,goal,examined,mem);
    if (bsol!=nullptr)
        cout<<"depth = "<<bsol->getDepth()<<", Mem: "<<mem<<", Examined: "<<examined<<endl;
    else
        cout<<"Problem unsolvable"<<endl;
    return 0;
}