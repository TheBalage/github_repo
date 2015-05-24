#include "jatekablak.hpp"
#include "application.hpp"

#include <iostream>
#include <vector>
#include <math.h>


using namespace genv;
using namespace std;



JatekAblak::JatekAblak(int _x, int _y, int _size_x, int _size_y)
    :  Widget( _x, _y, _size_x, _size_y )
{
    // menu = true;
    voltkatt = false;
    elsokatt = true;
    gomb_x = 270;
    gomb_y = 130;
    oszlop = 0;
    menu = true;
    string tombom[6][5];
    cucc a;
    cucc b;


    PI=3.14;
    acc = 0.01;
    r=20;
    oy=40;

    P=true;
    K=false;
    sor = 0;
    sor1 = 0;

}



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


                cout << oszlop <<endl;
            }
            if( P && !K )       ///A jatekos jon (piros)
            {
                /*if( elemek[sor1][oszlop1]!="") sor1++;
                if( elemek[sor1][oszlop1]=="" ) { elemek[sor1][oszlop1].push_back("piros");}*/

                if( elemek1[sor][oszlop]!="") sor++;    ///Ha mar van valami abban a kockaban, akkor az eggyel felette levot vizsgalja
                if( elemek1[sor][oszlop]=="" )
                {
                    elemek1[sor][oszlop]="piros";    ///ha az a hely ures, belerak egy pirosat
                }
                cout << "PIROS: sor: " << sor+1 << " oszlop: " <<oszlop/*<< "   elem: " << elemek1[sor][oszlop]*/ << endl;

                a.xx=(size_x/9)*oszlop + size_x/18 - 7.5;
                a.yy=size_y-(sor+1)*(size_y/7)+size_y/14;
                a.color="piros";
                c.push_back(a);


                P=false;
                K=true;
                sor=0;
            }
            else if( !P && K)       ///B jatekos jon (kek)
            {
                while( elemek1[sor1][oszlop]!="") sor1++;    ///Ha mar van valami abban a kockaban, akkor az eggyel felette levot vizsgalja
                if( elemek1[sor1][oszlop]=="" )
                {
                    elemek1[sor1][oszlop]="kek";    ///ha az a hely ures, belerak egy pirosat
                }
                cout << "KEK:   sor: " << sor+1 << " oszlop: " <<oszlop/*<< "   elem: " << elemek1[sor][oszlop] */<< endl;
                b.xx=(size_x/9)*oszlop + size_x/18 - 7.5;
                b.yy=size_y-sor1*(size_y/7)+size_y/14;
                b.color="kek";
                c.push_back(b);


                P=true;
                K=false;
                sor1=1;
            }
        }

    }
//    if( ev.type==ev.mouse && ev.button==1 && ev.pos_x>)
}


void set_tomb( std::string tomb[6][5] )
{
    std::string tombom[6][5];
    for( int i=0; i<6; i++)
    {
        for( int j=0; i<5; j++)
        {
            tombom[i][j] = tomb[i][j];
            std::cout << "i j " << tombom[i][j] <<endl;
        }
    }
}


void JatekAblak::draw()
{
    ///Menu kirajzolasa:
    /*gout << move_to(x+5,y+5) << color(0,200,200) << box(size_x-10,size_y-10);
    gout << move_to(x+size_x/2-gomb_x/2-4, y+size_y/2-gomb_y/2-4) << color(0,255,255) << box( gomb_x+8, gomb_y+8 );
    gout << move_to(x+size_x/2-gomb_x/2, y+size_y/2-gomb_y/2) << color(255,255,255) << box( gomb_x, gomb_y );*/
    menu = false;   ///Ideiglenesen van itt, amig nem csinalom meg a menut rendesen
    if( menu == false )     ///Maga a jatek kirajzolasa
    {
        gout << move_to(x+5,y+5) << color(200,200,0) << box(size_x-10,size_y-10);
        for( int i=1; i<9; i++)
        {
            gout << move_to(i*(size_x/9),size_y-5) << color(100,100,200) << line_to(i*(size_x/9),size_y-6*size_y/7);
        }
        for( int i=1; i<7; i++)
        {
            gout << move_to(size_x/9,size_y-i*size_y/7) << color(100,100,200) << line_to(8*size_x/9,size_y-i*size_y/7);
        }

        /*for( int i=0; i<6;i++){
            for( int j=0; j<5; j++){
                    if(tombom[i][j]=="piros")
                    {b.bsor=i; b.boszlop=j; b.szin="piros";
                    cout << b.bsor << endl;                    }
            }
        }*/

        for(int i=0; i<c.size(); i++)
        {
            if(c[i].color=="piros")
                gout << move_to(c[i].xx, c[i].yy) <<color(255,0,0) << box(20,20);
                //std::cout << "x["<<i<<"]: "<<c[i].xx<<endl;
                std::cout << "y["<<i<<"]: "<<c[i].yy<<endl;
            if(c[i].color=="kek")
                gout << move_to(c[i].xx, c[i].yy) <<color(0,0,255) << box(20,20);

            //std::cout<<c[i].xx<<endl;
        }


        if ( voltkatt ) ///Akkor valami berajzolása
        {
            /*for(int i=0; i<1000; i++)
            {
            double PI=3.14;
            double acc = 0.01;
            int r =0.1+(i*0.01);
            int ox=200;
            int oy=200;
            gout << move_to(ox+r,oy) << color(255,0,0);
            for(int i=0; i<=2*PI/acc*4; i++){
            gout << line_to(cos((double)i*acc)*r + ox, -sin((double)i*acc)*r + oy);
            }
            }*/


            ox=(size_x/9)*oszlop + size_x/18;
            gout << move_to(ox+r,oy) << color(255,0,0);
            for(int i=0; i<=2*PI/acc*1.1; i++)
            {
                gout << line_to(cos((double)i*acc)*r + ox, -sin( (double)i*acc)*r + oy);
            }


        }

//        for( int i=0; i<elemek1.size(); i++){}


    }

} ///Jatekmenet zaro zarojel


