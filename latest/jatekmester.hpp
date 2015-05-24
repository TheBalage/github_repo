#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP

#include "graphics.hpp"
#include "widgets.hpp"

class JatekMester: public Widget
{
protected:


public:
    JatekMester( int _x, int _y, int _size_x, int _size_y );
    void draw();

    void handle(genv::event ev);


};

#endif

