#include <iostream>
#include <unordered_map>
#include "Game.h"
#include "Timer.h"
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

/*
 * BFS implementation with unordered_map and queue structures.
 */

Game *BFS2(Game *initial,Game *goal, long long &examined, long long &mem)
{
    queue<Game *> agenda;
    unordered_map <string ,Game *> closed;

    agenda.push(initial);
    examined=0;
    mem=1;
    while (agenda.size()>0)
    {
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        Game *s = agenda.front();
        agenda.pop();
        if (closed.count(s->getKey())==0)
        {
            examined++;
            if (*s==*goal)
                return s;
            pair<string ,Game *> k (s->getKey(),s);
            closed.insert(k);
            vector<Game *> children =s->expand();
            for (unsigned int i=0;i<children.size();i++)
                if (closed.count(children[i]->getKey())==0)
                    agenda.push(children[i]);
        }
    }
    return nullptr;
}

/*
 * BFS implementation with vector and queue structures
 */


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

    Timer timer;
    long long mem,examined;

    int n;
    cout << "Give number of tubes:";
    cin >> n;

    timer.start();

    Game* game = new Game(n);

    Game* goal;
    goal = game->getGoal();


    cout << "Initial state: " << endl;
    game->print();
    cout << "Final state:" << endl;
    goal->print();

    cout<<endl<<"BFS: ";
    Game* bsol;
    bsol=BFS2(game,goal,examined,mem);
    if (bsol!=nullptr)
        cout<<"depth = "<<bsol->getDepth()<<", Mem: "<<mem<<", Examined: "<<examined<<endl<<endl;
    else {
        cout << "Problem unsolvable" << endl;
        timer.stop();
        cout << "Mem: " << mem << ", Examined: " << examined << endl;
        cout << "Seconds: " << timer.getSec() << endl;
        return 0;
    }

    cout << "Step by step:" << endl;
    bsol -> getPath(*bsol);

    timer.stop();

    cout << "Seconds: " << timer.getSec() << endl;


    return 0;
}