#include "ablak.h"
#include "graphics.hpp"

using namespace genv;
using namespace std;

void Window::event_loop(const int XX, const int YY){
    gout.open(XX,YY);
    event ev;
    int focus=-1;
    while(gin>>ev && ev.keycode!=key_escape){
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
            w->kirajzol(XX,YY);
        }
        gout<<refresh;
        gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY);
    }
}
