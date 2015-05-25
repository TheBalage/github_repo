#ifndef JATEKABLAK_HPP
#define JATEKABLAK_HPP

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
#include <iostream>

struct Babu
{
    int xx, yy, sora, oszlopa;
    string color;
};

class JatekAblak: public Widget
{
protected:
    bool menu;
    bool voltkatt;
    bool elsokatt;
    int gomb_x;
    int gomb_y;
    int oszlop;

    std::vector<Babu> c;
    Babu a;
    int p_db;
    int k_db;

//    babu b;
    std::string elemek1 [6][5];

    int sor;
    bool P;
    bool K;

    int _sor;
    int _oszlop;

    bool pvan;
    bool kvan;
    bool p_win;
    bool k_win;

    int sor1;
    int oszlop1;



    double PI;
    double acc;
    int r;
    int ox;
    int oy;

public:
    JatekAblak( int _x, int _y, int _size_x, int _size_y);
    void draw();


    void dob( int o );

    bool menue(  );
    void vizsgalat();
    void handle(genv::event ev);
};

#endif
