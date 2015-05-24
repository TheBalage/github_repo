#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include "graphics.hpp"

class Widget {
    protected:
        int x, y, size_x, size_y;
        bool inFocus;

    public:
        Widget( );                                                  // Default konstruktor (csak létrehozza az egyedet)
        Widget( int _x, int _y );                                   // A konstruktor inicializálja a widget pozícióját
        Widget( int _x, int _y, int _size_x, int _size_y );         // A konstruktor inicializálja a widget paramétereit

        virtual void draw();                                        // A widget kirajzolása
        virtual void handle( genv::event ev );                      // A widget saját esemény kezelője
        void set_focus( bool focus );                               // A fókusz beállítása
        bool is_selected( int mouse_x, int mouse_y ) const;         // Megállapítja, hogy a kurzor a widget-et fölött van-e
        bool set_menu( bool menu ) ;


        bool is_focused() const { return inFocus;   }               // Fókuszban van-e még a widget
        int positionX() const   { return x;         }
        int positionY() const   { return y;         }
        int width() const       { return size_x;    }
        int height() const      { return size_y;    }
};

#endif // WIDGET_HPP
