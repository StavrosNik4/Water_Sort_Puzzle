#ifndef TUBE_H
#define TUBE_H

#include <iostream>

using namespace std;

class Tube{
    public:
        Tube();     //default constructor
        Tube(Tube &temp);   // copy constructor
        bool push(char a);  // stack push method
        bool pop();         // stack pop method
        bool isEmpty();     // method to check if the tube is empty
        bool isFull();      // method to check if the tube is full
        char getTop();       // method to get
        Tube operator= (Tube o);        // assign overload
        bool operator==(Tube s) const; // equals overload
        char getElement(int i);       // method to get an element from the ith position of the tube
private:
    char st[4];
    int size;


};

#endif //TUBE_H