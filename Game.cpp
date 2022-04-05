#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>


Game::Game() {
    n = 7;
    tubes = new Tube[n];
    setPrevious(nullptr);
}


// a way to visualize the game
void Game::print() {
    for(int i = 3; i >= 0; i--)
    {
        for(int j = 0; j < n; j++)
            cout << '|' << tubes[j].getElement(i) << '|' << ' ';
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
}

Game *Game::                                        getGoal(){
    Game *goal = new Game(n);
    int colors[17] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'a' - 48, 'b' - 48, 'c' - 48, 'd' - 48, 'e' - 48, 'f' - 48, 'g'- 48};

    for(int i = 0; i<n-2; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            goal->tubes[i].pop();
        }
    }

    for(int i = 0; i<n-2; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            goal->tubes[i].push(colors[i] + 48);
        }
    }
    goal->setPrevious(nullptr);
    return goal;
}

Game::Game(const Game &g1) {
    n = g1.n;
    tubes = new Tube[n];
    for(int i=0; i<n; i++)
        tubes[i] = g1.tubes[i];
    prev = g1.prev;
}

Game::Game(int a) {
    n = a;
    tubes = new Tube[n];

    int colors[17][2] = {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}, {7, 4}, {8, 4}, {9, 4}, {10, 4}, {11, 4}, {12, 4}, {13, 4}, {14, 4}, {15, 4}, {16, 4}};

    int i=0, j=0;
    int t=4*(n-2);

    srand((unsigned)time(NULL));

    while(t>0)
    {
        int r = rand() % (n-2);
        if(colors[r][1] > 0)
        {
            if(colors[r][0]<10)
                tubes[i].push(colors[r][0] + 48);
            else
                tubes[i].push(colors[r][0] + 87);
            colors[r][1]--;
            t--;
            j++;
        }
        if(j==4)
        {
            i++;
            j=0;
        }
    }
    setPrevious(nullptr);
}

void Game::printPath(Game &game) {
    if(game.prev == nullptr)
    {
        game.print();
        return;
    }
    printPath(*game.prev);
    game.print();
}

string Game::getKey() {
    string arr[n];

    string str;

    for(int i=0; i<n; i++){
        string a;
        for(int j=3; j>=0; j--)
        {
            if(tubes[i].getElement(j)!=' ')
            {
                a.push_back(tubes[i].getElement(j));
            }
        }
        arr[i] = a;
    }

    int s = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + s);
    for(int y = 0; y < s; y++){
        str.append(arr[y]);
        str.append(arr[y]);
        str.append("-");
    }
    return str;
}
