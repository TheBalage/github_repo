#include "application.hpp"
#include "jatekablak.hpp"


int main()
{
    Application app(640,480, "Potyogtatos amoba 6527.3.2.");

    JatekAblak * a = new JatekAblak(0,0,640,480);

    app.addWidget(a);

    app.run();

    return 0;
}
