#ifndef JATEKABLAK_HPP
#define JATEKABLAK_HPP

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
#include <iostream>





class JatekAblak: public Widget
{
protected:
    bool menu;
    bool voltkatt;
    int gomb_x;
    int gomb_y;
    int oszlop;

            double PI;
            double acc;
            int r;
            int ox;
            int oy;





public:
    JatekAblak( int _x, int _y, int _size_x, int _size_y);
    void draw();
//    vector<Babu> babuk;


        class Babu//: public JatekAblak
        {
        protected:
            int sor;

        public:

                Babu( int _sor )
                {
                    sor = _sor;
                    //y = yhely;
                }

        };



    void dob( int o );

    void handle(genv::event ev);
};

#endif
