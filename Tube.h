#ifndef TUBE_H
#define TUBE_H

#include <iostream>

using namespace std;

class Tube{
    public:
        Tube();
        Tube(Tube &temp);

        bool push(char a);
        bool pop();

        bool isEmpty();
        bool isFull();

        int getTop();

        void print();

        Tube operator= (Tube o);
        bool operator==(Tube s) const;

        char getElement(int i);

        char st[4];
        int size;
private:



};

#endif //TUBE_H