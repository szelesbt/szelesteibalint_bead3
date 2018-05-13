//#include <iostream>
#include "widgetek.h"
#include "ablak.h"
#include "nyomogomb.h"
#include "jatekmester.h"

using namespace std;
using namespace genv;

const int tablameret(10), kockameret(30), XX(tablameret*kockameret+299/*1300*/), YY(tablameret*kockameret+17/*650*/);

class MyWindow : public Window{
public:
    Jatekmester* mester;
    Amobatabla* amobatabla;

    MyWindow();

    void katt(int hova_x, int hova_y){
      //  cout<<"lepes:"<<endl;
        mester->lepes(hova_x,hova_y);
    }
    int kerdes(int hol_x, int hol_y){
        return mester->kievagy(hol_x,hol_y);
    }
    int vege(){
        return mester->nyertes();
    }
    void ujra(){
        mester->reset();
    }
};

int main()
{
    MyWindow *mywindow = new MyWindow;
    mywindow->event_loop(XX,YY);
    return 0;
}

MyWindow::MyWindow(){
    mester=new Jatekmester(tablameret);

    amobatabla=new Amobatabla(11,12,tablameret,kockameret,"Amoba",[this](int a, int b){this->katt(a,b);}, [this](int c, int d)->int {return this->kerdes(c,d);}, [this]()->int {return this->vege();}, [this](){this->ujra();});

    widgetek.push_back(amobatabla);

  }
