#include "Tube.h"

Tube::Tube()
{
    //st = {' ', ' ', ' ', ' '};
    for(char & i : st)
        i = ' ';
    size = 0;
}

Tube::Tube(Tube &temp) {
    for(int i=0; i<temp.size; i++)
        st[i] = temp.getElement(i);
    size = temp.size;
}

bool Tube::isEmpty() {
    if(size==0)
        return true;
    return false;
}

bool Tube::isFull() {
    if(size==4)
        return true;
    return false;
}

char Tube::getElement(int i){
    return st[i];
}

void Tube::print() {
    for(int i=3; i>=0; i--)
    {
        cout << "|" << st[i] << "|\n";
    }
    cout << "\n";
}

int Tube::getTop() {
    if(size>0)
        return st[size-1];
    return -1;
}

bool Tube::push(char a) {
    if(size==4)
        return false;
    size++;
    st[size-1] = a;
    return true;
}

bool Tube::pop() {
    if(size==0)
        return false;
    st[size-1] = ' ';
    size--;
    return true;
}

bool Tube::operator==(Tube s) const{
    if(size==s.size) {
        if (size==0 && s.size == 0)
            return true;
        int i = 0;
        while (i < size) {
            if (st[i] != s.getElement(i))
                return false;
            i++;
        }
        return true;
    }
    else
        return false;
}

Tube Tube::operator=(Tube o) {
    for(int i=0; i<o.size; i++)
    {
        st[i] = o.getElement(i);
    }
    size = o.size;
    return *this;
}


