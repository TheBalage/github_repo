#include "application.hpp"
#include "graphics.hpp"


using namespace genv;
using namespace std;

#include <iostream>

Application::Application( int _SX, int _SY, std::string _name ) : SX(_SX), SY(_SY), name(_name) {
    isExiting = false;
    focused = -1;               // a program indulásakor semmi nincs fókuszban
                        gomb_x = 270;
                        gomb_y = 130;
                        menu = true;
                        size_x = 640;
                        size_y = 480;
                        sor = 0;
                        sor1=0;
                P=true;
                K=false;

                _sor=0;
                _oszlop=0;
                p_db=0;
                k_db=0;


}

void Application::addWidget( Widget *w ) {
    widgets.push_back( w );
}

void Application::run() {
    gout.open( SX, SY );
    gout.set_title( name );

    event ev;
    while( gin>>ev && !isExiting ) {     // amíg fogadhat eseményeket és nincs kilépési módban

        if( ev.keycode == key_escape )   // esc hatására kilépünk
            isExiting = true;

        /// Fókusz kezelése
        if( ev.keycode == key_tab && widgets.size() > 0 )   // Tab hatására változik a fókusz
            focused = ( focused + 1 ) % widgets.size();     // körbe jár a már létező widgeteken

        if( ev.type == ev_mouse && ev.button==btn_left  ) { // Bal egér klikk a kiválasztás  (csak bal klikk-kor figyelnek az elemek)
            focused = -1;                                   // Ha semleges helyre történt a klikkelés (nincs ott semmi), akkor megszüntetjük a fókuszt
            for( size_t i=0; i<widgets.size(); i++ ) {      // Minden widget-re megvizsgáljuk, hogy ő van-e választva vagy sem
                if( widgets[i]->is_selected(ev.pos_x, ev.pos_y) ) {
                        focused = i;
                }
            }
            ///
                        /*if( menu && elsokatt && ev.type==ev_mouse && ev.button==1 && ev.pos_x>size_x/2-gomb_x/2 &&  ev.pos_x<size_x/2+gomb_x/2 && ev.pos_y>size_y/2-gomb_y/2 && ev.pos_y<size_y/2+gomb_y/2)
                        {
                            cout << "voltmenu"<<endl;
                            menu = false;
                            elsokatt = false;
                        }*/
                        int menu = false;
                        if( menu  == false )
                        {
                                if( ev.type==ev_mouse && ev.button==1 && elsokatt ) elsokatt = false;
                                if( ev.type==ev_mouse && ev.button==1 && elsokatt==false )
                                {

                                    for( int i=1; i<8; i++)
                                    {
                                        if( ev.type==ev_mouse && ev.button==1 && ev.pos_x>i*(size_x/9) && ev.pos_x<(i+1)*(size_x/9) )
                                        oszlop = i;
                                        oszlop1 = i;
                                        //voltkatt = true;
                                        //cout << oszlop <<endl;      ///Kattintas oszlopanak meghatarozasa
                                    }


                                ///Sorvizsgalas:
                                //for( int j=0; j<6; j++)
                                //{
                                    /*for( int i=0; i<7; i++)
                                    {
                                        if( elemek1[_sor][_oszlop]=="piros" || elemek1[_sor][_oszlop]=="kek" ){ p_db=1; k_db=1; _sor++; std::cout<<"+"<<endl;}
                                        if( elemek1[_sor][_oszlop]=="piros" ){ p_db=2; kvan=false; _sor++; }
                                        if( elemek1[_sor][_oszlop]=="kek"){ k_db=2; pvan=false; _sor++; }
                                        if( pvan && elemek1[_sor][_oszlop]=="piros" ){ p_db++; _sor++; }         ///3
                                        if( kvan && elemek1[_sor][_oszlop]=="kek" ){ k_db++; _sor++; }
                                        if( pvan && elemek1[_sor][_oszlop]=="piros" ){ p_db++; p_win=true; }     ///4
                                        if( kvan && elemek1[_sor][_oszlop]=="kek"){ k_db++; k_win=true; }
                                    }
                                    std::cout << "piros: " << p_db <<" "<< k_db <<endl;*/
                                //}
                                // for( int i=0; i<widgets.size(); i++) widgets[i]->set_tomb( elemek1 );
                                // babuk.push_back(oszlop);
                                // cout << babuk.size() << endl;
                                }

                    }



            ///

        }

        for( size_t i=0; i<widgets.size(); ++i )            // közöljük a widgetekkel, hogy melyikük van fókuszban
            widgets[i]->set_focus( focused == (int)i );

        /// Eseménykezelés
        if( focused != -1)                                // csak a fókuszban lévő widget kapja meg az eseményeket
            widgets[focused]->handle( ev );

       /* for( size_t i=0; i<widgets.size(); ++i )            // a vektorban található összes vezérlõ megkapja az eseményeket
            widgets[i]->handle( ev );*/                       // eseménykezelés widget szinten

        /// Vizualizálás
        gout << move_to(0, 0) << color(200,0,0) << box(SX, SY);// képernyő törlése
        for( size_t i=0; i<widgets.size(); ++i ){
            widgets[i]->draw();                         // képernyő újra rajzolása
            widgets[i]->get_tomb(    );
        }

        gout << refresh;                                    // képernyő frissítése

    }
    draw();
}

void Application::draw()
{
    gout<<move_to(10,10)<<color(220,220,220)<<box(630,470);
    for( int i=0; i<babuk.size(); i++){
        gout<<move_to(babuk[i].oszlopszam*i*(size_x/9)+size_x/18, babuk[i].sorszam+(i+1)*(size_x/9) )<<color(255,0,0)<< box(15,15);
    }
}



void Application::shutdown() {
    isExiting = true;                                       // kilépés inicializálása
}
