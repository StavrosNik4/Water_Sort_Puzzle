#include "Game.h"
#include <iostream>

Game::Game() {
    n = 7;
    tubes = new Tube[n];

    tubes[0].push('2');
    tubes[0].push('1');
    tubes[0].push('0');
    tubes[0].push('0');

    tubes[1].push('1');
    tubes[1].push('4');
    tubes[1].push('4');
    tubes[1].push('3');

    tubes[2].push('4');
    tubes[2].push('4');
    tubes[2].push('2');
    tubes[2].push('0');

    tubes[3].push('3');
    tubes[3].push('2');
    tubes[3].push('2');
    tubes[3].push('3');

    tubes[4].push('1');
    tubes[4].push('3');
    tubes[4].push('0');
    tubes[4].push('1');

    setPrevious(nullptr);
}


// a way to visualize the game
void Game::print() {
    for(int i = 0; i < n; i++)
    {
        tubes[i].print();
        cout << '\n';
    }
    cout << "------------------\n";
}

bool Game::move(Game &game, int a, int b) {
    if(game.tubes[b].isEmpty() || (!(game.tubes[a].isEmpty()) && game.tubes[b].getTop() == game.tubes[a].getTop() && !(game.tubes[b].isFull())))
    {
        char tmp = game.tubes[a].getTop();
        while(game.tubes[a].getTop() == tmp && !(game.tubes[b].isFull())){
            game.tubes[b].push(tmp);
            game.tubes[a].pop();
        }
        game.setPrevious(this);
        return true;
    }
    return false;
}

bool Game::operator==(const Game &s) const {
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        flag = false;
        for(int j = 0; j < n; j++)
        {
            if(tubes[i] == s.tubes[j]) {
                flag = true;
                break;
            }
        }
        if(!flag)
            return false;
    }
    return flag;
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
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            child = new Game(*this);
            if (i == j) { continue; }
            else {
                if (move(*child, i, j))
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
    int counter = 0;
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
        goal -> tubes[0].push('0');

    for(int i=0; i<4; i++)
        goal -> tubes[1].push('1');

    for(int i=0; i<4; i++)
        goal -> tubes[2].push('2');

    for(int i=0; i<4; i++)
        goal -> tubes[3].push('3');

    for(int i=0; i<4; i++)
        goal -> tubes[4].push('4');
    return goal;
}

Game::Game(const Game &g1) {
    n = g1.n;
    tubes = new Tube[n];
    for(int i=0; i<n; i++)
        tubes[i] = g1.tubes[i];
    prev = g1.prev;
}
