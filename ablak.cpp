#include "ablak.h"
#include "graphics.hpp"
#include <fstream>
#include <iostream>

using namespace genv;
using namespace std;

void Window::event_loop(){
event ev;
int focus=-1;
while(gin>>ev){
    if(ev.type==ev_mouse && ev.button==btn_left){
        for(size_t i=0;i<widgetek.size();i++){
            if(widgetek[i]->kivalasztott(ev.pos_x, ev.pos_y)){
                focus=i;
            }
        }
    }
    if (focus!=-1){
        widgetek[focus]->akcio(ev);
    }
    for(Widget* w: widgetek){
        w->kirajzol();
    }
    gout<<refresh;
    gout<<move_to(0,0)<<color(0,0,0)<<box(1300,650);
}




}
