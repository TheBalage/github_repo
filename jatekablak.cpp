#include "jatekablak.hpp"

#include <iostream>

using namespace genv;
using namespace std;

JatekAblak::JatekAblak(int _x, int _y, int _size_x, int _size_y)
    :  Widget( _x, _y, _size_x, _size_y ) //,r(200),g(40),b(40), szin(r,g,b) // Az õsosztály konstruktorának hívása
{
    menu = true;
    gomb_x = 270;
    gomb_y = 130;
}

class JatekMester{
    public:
        int x, y, meret;
        JatekMester( int xhely, int yhely )
        {

        }

};

void JatekAblak::handle(event ev)
{
    ///Jatek inditasanak vizsgalata:
    if( ev.type==ev_mouse && ev.button==1 && ev.pos_x>x+size_x/2-gomb_x/2 &&  ev.pos_x<x+size_x/2+gomb_x/2 && ev.pos_y>y+size_y/2-gomb_y/2 && ev.pos_y<y+size_y/2+gomb_y/2) menu = false;

//    if( ev.type==ev.mouse && ev.button==1 && ev.pos_x>)
}

void JatekAblak::draw()
{   ///Menu kirajzolasa:
    gout << move_to(x+5,y+5) << color(0,200,200) << box(size_x-10,size_y-10);
    gout << move_to(x+size_x/2-gomb_x/2-4, y+size_y/2-gomb_y/2-4) << color(0,255,255) << box( gomb_x+8, gomb_y+8 );
    gout << move_to(x+size_x/2-gomb_x/2, y+size_y/2-gomb_y/2) << color(255,255,255) << box( gomb_x, gomb_y );

    if( menu == false )     ///Maga a jatek kirajzolasa
    {
        gout << move_to(x+5,y+5) << color(200,200,0) << box(size_x-10,size_y-10);
        for( int i=1; i<9; i++)
        {
            gout << move_to(x+i*(size_x/9),y+size_y-5) << color(100,100,200) << line_to(x+i*(size_x/9),y+size_y-5*size_y/6);
        }
        for( int i=1; i<6; i++)
        {
            gout << move_to(x+size_x/9,y+size_y-i*size_y/6) << color(100,100,200) << line_to(x+8*size_x/9,y+size_y-i*size_y/6);
        }

    }

    } ///Jatekmenet zaro zarojel


