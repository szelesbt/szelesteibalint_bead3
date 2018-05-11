
#include <sstream>

#include "graphics.hpp"
#include "widgetek.h"
#include "szambeallito.h"
#include "menu.h"
#include "szovegszerk.h"
#include "jelszo.h"
#include "ablak.h"
#include "nyomogomb.h"
#include "simaszoveg.h"

using namespace std;
using namespace genv;

const int XX(1000),YY(500);

class MyWindow : public Window{
public:




    MyWindow();


};

int main()
{

    gout.open(XX,YY);
    MyWindow *mywindow = new MyWindow;
    mywindow->event_loop();
    return 0;
}

MyWindow::MyWindow(){



  }
