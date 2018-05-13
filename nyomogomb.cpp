#include "nyomogomb.h"
#include <sstream>
#include <iostream>
using namespace std;
using namespace genv;

Nyomogomb::Nyomogomb(int a, int b, int c, int d, string s)
    : Widget(a,b,c,d), _felirat(s)
{
    kie=0;
}

/*Nyomogomb::Nyomogomb(int a, int b, int c, int d, string s, function<void()> functor, std::function<void()> functor2)
    : Widget(a,b,c,d), _felirat(s), _functor(functor), _functor2(functor2)
{
    kie=0;
}*/

void Nyomogomb::kirajzol() /*const*/ {
  /*  if (_focused) gout << color(80,80,80);
        else gout << color(30,30,30);
    _functor2();
    std::stringstream ss;
    ss<<kie;*/
    gout << move_to(_helyx, _helyy) <<color(128,128,128)<< box(_meretx, _merety)
         << color(255,255,255);
    gout << move_to(_helyx+_meretx/2-gout.twidth(_felirat)/2, _helyy+_merety/2+4)
         << text(_felirat);
}
void Nyomogomb::akcio(genv::event ev) {
    if (ev.button==btn_left) {
        bumm(ev);
        //_functor();
    }
}
string Nyomogomb::getter(){
    return "lul";
}


Amobatabla::Amobatabla(int a, int b, int c, int d, std::string s, std::function<void(int hol_x, int hol_y)> functor, std::function<int(int hol_x2, int hol_y2)> functor2, std::function<int()> functor3, std::function<void()>  functor4): Nyomogomb(a,b,c*d,c*d,s), _functor(functor), _tablameret(c), _kockameret(d), _functor2(functor2), _functor3(functor3), _functor4(functor4)
{
    jatekvege=false;
}
void Amobatabla::bumm(genv::event ev){
    if(!jatekvege){
    if((ev.pos_y-_helyy)%_kockameret>1 && (ev.pos_x-_helyx)%_kockameret>1){
        _functor((ev.pos_y-_helyy)/_kockameret,(ev.pos_x-_helyx)/_kockameret);
    }
    }else{
        if(ev.pos_x>=700 && ev.pos_x<=900 && ev.pos_y>=50 && ev.pos_y<=80){
            jatekvege=false;
            _functor4();
        }
    }
}

void Amobatabla::kirajzol(){

   // if(!jatekvege){
     for(int i=0;i<_tablameret;i++){
        for(int j=0;j<_tablameret;j++){
            gout<<color(255,255,255)<<move_to(_helyx+j*_kockameret, _helyy+i*_kockameret)<<box(_kockameret,_kockameret);
            int kieeee=_functor2(i,j);
            if(kieeee==0){
                gout<<color(0,0,0);
            }else if(kieeee==1){
                gout<<color(255,0,0);
            }else{
                gout<<color(0,0,255);
            }
            gout<<move_to(_helyx+j*_kockameret+1, _helyy+i*_kockameret+1)<<box(_kockameret-2,_kockameret-2);
        }
    }
    int nyert=_functor3();
    if(nyert!=0 && !jatekvege){
        jatekvege=true;
    }
    if (nyert!=0){
        gout<<move_to(700,50)<<color(255,255,255)<<box(200,30);
        gout<<move_to(705,70)<<color(0,0,0)<<text("Katt ide az uj jatekhoz!");
    }
    if(nyert==1){
        gout<<move_to(700,250)<<color(255,0,0)<<text("Nyert a piros játékos!");

    }else if(nyert==2){
        gout<<move_to(700,250)<<color(0,0,255)<<text("Nyert a kék játékos!");

    }
    //}else{gout<<move_to(500,50)<<color(0,0,255)<<text("Nyomjon entert az uj jatekhoz!");}
}
