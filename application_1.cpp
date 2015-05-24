#include "application.hpp"
#include "graphics.hpp"
#include "jatekablak.hpp"

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
                A=true;
                B=false;
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
            ///Bemasolt reszˇˇ
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
                                        //voltkatt = true;
                                        //cout << oszlop <<endl;      ///Kattintas oszlopanak meghatarozasa
                                    }
                                if( A && !B )       ///A jatekos jon (piros)
                                {
                                    if( elemek1[sor][oszlop]!="") sor++;    ///Ha mar van valami abban a kockaban, akkor az eggyel felette levot vizsgalja
                                    if( elemek1[sor][oszlop]=="" ) { elemek1[sor][oszlop]="piros"; }  ///ha az a hely ures, belerak egy pirosat
                                            cout << "PIROS: sor: " << sor+1 << " oszlop: " <<oszlop<< " elem: " << elemek1[sor][oszlop] << endl;
                                    A=false;
                                    B=true;
                                    //sor=0;
                                } else if( !A && B)     ///B jatekos jon (kek)
                                {
                                    if( elemek1[sor][oszlop]!="") sor++;    ///Ha mar van valami abban a kockaban, akkor az eggyel felette levot vizsgalja
                                    if( elemek1[sor][oszlop]=="" ) { elemek1[sor][oszlop]="kek"; }  ///ha az a hely ures, belerak egy pirosat
                                            cout << "KEK:   sor: " << sor+1 << " oszlop: " <<oszlop<< " elem: " << elemek1[sor][oszlop] << endl;
                                    A=true;
                                    B=false;
                                    //sor=0;
                                }
                            // babuk.push_back(oszlop);
                            // cout << babuk.size() << endl;
                            }

                    }



            ///Bemasolt resz^^

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
        for( size_t i=0; i<widgets.size(); ++i )
            widgets[i]->draw();                             // képernyő újra rajzolása
        gout << refresh;                                    // képernyő frissítése

    }
}

void Application::shutdown() {
    isExiting = true;                                       // kilépés inicializálása
}
