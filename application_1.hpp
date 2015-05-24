#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "widgets.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <string>

class Application { // grafikus alkalmazás
    protected:
        std::vector<Widget*> widgets;   // az alkalmazás vezérlői
        int focused;                    // megadja, hogy melyik vezérlõn van a fókusz
        bool isExiting;                 // kilépés alatt áll-e a program
        int SX, SY;                     // képernyõ méret
        std::string name;                    // az alkalmazás neve

        int sor;
        bool A;
        bool B;

        std::string elemek1[6][5];  ///1-gyel nagyobb minden iranyban!!!!!
        std::vector<std::vector<std::string> > elemek;

                        int gomb_x;
                        int gomb_y;
                        bool menu;
                        bool voltkatt;
                        bool elsokatt;
                        int oszlop;
                        int size_x;
                        int size_y;

    public:
        Application( int _SX, int _SY, std::string _name );// ablak méret és név alapján program létrehozása
        void addWidget( Widget *w );    // új vezérlõ felvétele
        void run();                     // futtatás
        void shutdown();                // leállítás
        void action();

        int width() const { return SX; }
        int height() const { return SY; }

};

#endif // APPLICATION_HPP
