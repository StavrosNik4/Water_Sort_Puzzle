#include "Game.h"
#include <iostream>

Game::Game() {
    n = 4;
    tubes = new Tube[n];

    tubes[0].push('0');
    tubes[0].push('1');
    tubes[0].push('1');
    tubes[0].push('0');

    tubes[1].push('1');
    tubes[1].push('0');
    tubes[1].push('1');
    tubes[1].push('0');

    setPrevious(nullptr);
}

/*
Game::Game(Game &g1) {
    n = g1.n;
    tubes = g1.tubes;
    setPrevious(g1.getPrevious());
}
 */

// a way to visualize the game
void Game::print() {
    for(int i = 0; i < n; i++)
    {
        tubes[i].print();
        cout << '\n';
    }
    cout << "------------------\n";
}

bool Game::move(Game &n, int a, int b) {
    if(n.tubes[b].isEmpty() || (!(n.tubes[a].isEmpty()) && n.tubes[b].getTop() == n.tubes[a].getTop() && !(n.tubes[b].isFull())))
    {
        char tmp = n.tubes[a].getTop();
        while(n.tubes[a].getTop() == tmp && !(n.tubes[b].isFull())){
            n.tubes[b].push(tmp);
            n.tubes[a].pop();
        }
        return true;
    }
    return false;
}

bool Game::operator==(const Game &s) const {
    for(int i = 0; i < n; i++)
    {

    }
}

Game Game::operator= (Game o)
{
    n = o.n;
    tubes = o.tubes;
    prev = o.prev;
    return *this;
}

vector<Game *> Game::expand() {
    vector<Game *> children;
    Game *child;
    //child = new Game(*this);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            child = new Game(*this);
            if(i==j)
                continue;
            else{
                if(move(*child, i,j))
                    children.push_back(child);
                else
                    delete child;
            }
        }
    }
    return children;
}

int Game::getDepth()
{
    int counter =0;
    Game *p = this;
    while (p->prev!=nullptr)
    {
        p=p->prev;
        counter++;
    }
    return counter;
    //return path.size();
}

Game *Game::getGoal(){
    Game *goal = new Game();

    for(int i=0; i<n-2; i++)
        for(int j=0; j<n; j++)
            goal -> tubes[i].pop();

    for(int i=0; i<4; i++)
        goal -> tubes[0].push('1');

    for(int i=0; i<4; i++)
        goal -> tubes[1].push('0');

    return goal;
}
