#ifndef JATEKABLAK_HPP
#define JATEKABLAK_HPP

#include "graphics.hpp"
#include "widgets.hpp"

class JatekAblak: public Widget
{
protected:
    bool menu;
    int gomb_x;
    int gomb_y;

    class JatekMester;


public:
    JatekAblak( int _x, int _y, int _size_x, int _size_y);
    void draw();

    void handle(genv::event ev);


};

#endif
