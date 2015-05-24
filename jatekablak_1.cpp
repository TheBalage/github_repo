#include "jatekablak.hpp"

#include <iostream>
#include <vector>
#include <math.h>


using namespace genv;
using namespace std;



JatekAblak::JatekAblak(int _x, int _y, int _size_x, int _size_y)
    :  Widget( _x, _y, _size_x, _size_y ) //,r(200),g(40),b(40), szin(r,g,b) // Az õsosztály konstruktorának hívása
{
   // menu = true;
    voltkatt = false;
    elsokatt = true;
    gomb_x = 270;
    gomb_y = 130;
    oszlop = 0;
    menu = true;

            PI=3.14;
            acc = 0.01;
            r=25;
            oy=50;

//    vector<Babu*> babuk;
//    babuk p;
}

/*
JatekMester::JatekMester( int _x, int _y )
            :  Jatekmester( _x, _y )
{
    oszlop=0;
}*/

/*bool JatekAblak::set_menu( bool menu)
{
        cout << "MENU: " << menu << endl;
}*/



void JatekAblak::handle(event ev)
{
    ///Jatek inditasanak vizsgalata:
    /*if( menu && elsokatt && ev.type==ev_mouse && ev.button==1 && ev.pos_x>size_x/2-gomb_x/2 &&  ev.pos_x<size_x/2+gomb_x/2 && ev.pos_y>size_y/2-gomb_y/2 && ev.pos_y<size_y/2+gomb_y/2)
    {
        cout << "voltmenu"<<endl;
        menu = false;
        elsokatt = false;
    }*/
    menu = false;
    if( menu  == false )
        {
            if( ev.type==ev_mouse && ev.button==1 && elsokatt ) elsokatt = false;
            if( ev.type==ev_mouse && ev.button==1 && elsokatt==false )
               {
                for( int i=1; i<8; i++)
                {
                    if( /*ev.type==ev_mouse && ev.button==1 &&*/ ev.pos_x>i*(size_x/9) && ev.pos_x<(i+1)*(size_x/9) )
                    oszlop = i;
                    voltkatt = true;
                    //cout << oszlop <<endl;
                }
                // babuk.push_back(oszlop);
                // cout << babuk.size() << endl;
            }

        }
//    if( ev.type==ev.mouse && ev.button==1 && ev.pos_x>)
}

bool JatekAblak::menue( ){ return menu; }

void JatekAblak::dob( int o )
{

}


void JatekAblak::draw()
{   ///Menu kirajzolasa:
    /*gout << move_to(x+5,y+5) << color(0,200,200) << box(size_x-10,size_y-10);
    gout << move_to(x+size_x/2-gomb_x/2-4, y+size_y/2-gomb_y/2-4) << color(0,255,255) << box( gomb_x+8, gomb_y+8 );
    gout << move_to(x+size_x/2-gomb_x/2, y+size_y/2-gomb_y/2) << color(255,255,255) << box( gomb_x, gomb_y );*/
    menu = false;
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

        if ( voltkatt ) ///Akkor valami berajzolása
        {
                ox=x+(size_x/9)*oszlop + size_x/18;
                gout << move_to(ox+r,oy) << color(255,0,0);
                for(int i=0; i<=2*PI/acc*1.1; i++){
                    gout << line_to(cos((double)i*acc)*r + ox, -sin( (double)i*acc)*r + oy);
                }
        }

    }

    } ///Jatekmenet zaro zarojel


