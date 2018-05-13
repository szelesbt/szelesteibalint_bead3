#include <iostream>
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
#include "jatekmester.h"

using namespace std;
using namespace genv;

const int XX(1300), YY(650), tablameret(20), kockameret(30);


class MyWindow : public Window{
public:
    Jatekmester* mester;

    Amobatabla* amobatabla;

    MyWindow();

    void katt(int hova_x, int hova_y){
        cout<<"lepes:"<<endl;
        mester->lepes(hova_x,hova_y);
    };

    int kerdes(int hol_x, int hol_y){
        return mester->kievagy(hol_x,hol_y);
    };
    int vege(){
        return mester->nyertes();
    };
    void ujra(){
        mester->reset();
    }
};

int main()
{

    gout.open(XX,YY);
    MyWindow *mywindow = new MyWindow;
    mywindow->event_loop();
    return 0;
}

MyWindow::MyWindow(){
    mester=new Jatekmester(tablameret);


    amobatabla=new Amobatabla(/*this,*/10,10,tablameret,kockameret,"Amoba",[this](int a, int b){this->katt(a,b);}, [this](int c, int d)->int {return this->kerdes(c,d);}, [this]()->int {return this->vege();}, [this](){this->ujra();});


    widgetek.push_back(amobatabla);

  }
