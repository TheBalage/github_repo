#include "application.hpp"
#include "jatekablak.hpp"


int main()
{
    Application app(640,480, "Potyogtatos amoba 0.1");

    // létrehozzuk a vezérlőket

//    MenuAblak * m = new MenuAblak
    JatekAblak * a = new JatekAblak(0,0,640,480);


    // hozzáadjuk a vezérlőket
    app.addWidget(a);


    app.run();

    return 0;
}
