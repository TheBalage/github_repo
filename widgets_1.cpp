#include "widgets.hpp"

using namespace genv;

Widget::Widget( ) {}                                            // Paraméter nélküli konstruktor
Widget::Widget( int _x, int _y ) : x(_x), y(_y) {}              // Két paraméteres konstruktor
Widget::Widget( int _x, int _y, int _size_x, int _size_y )      // Négy paraméteres konstruktor
: x(_x), y(_y), size_x(_size_x), size_y(_size_y) {
    inFocus = false;
}

void Widget::draw(){
}

void Widget::handle( event ev ) {
}

void Widget::set_focus( bool focus ){
    inFocus = focus;
}

bool Widget::set_menu( bool menu ){
}

bool Widget::is_selected( int mouse_x, int mouse_y ) const {
    return mouse_x>=x && mouse_x<=x+size_x && mouse_y>=y && mouse_y<=y+size_y;
}



