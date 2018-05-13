#include "nyomogomb.h"

using namespace std;
using namespace genv;

Nyomogomb::Nyomogomb(int a, int b, int c, int d, string s): Widget(a,b,c,d), _felirat(s){
}

void Nyomogomb::kirajzol(){
    gout << move_to(_helyx, _helyy) <<color(128,128,128)<< box(_meretx, _merety)
         << color(255,255,255);
    gout << move_to(_helyx+_meretx/2-gout.twidth(_felirat)/2, _helyy+_merety/2+4)
         << text(_felirat);
}

void Nyomogomb::akcio(event ev) {
    if (ev.button==btn_left) {
        bumm(ev);
    }
}

Amobatabla::Amobatabla(int a, int b, int c, int d, string s, function<void(int hol_x, int hol_y)> functor, function<int(int hol_x2, int hol_y2)> functor2, function<int()> functor3, function<void()>  functor4): Nyomogomb(a,b,c*d,c*d,s), _functor(functor), _functor2(functor2), _functor3(functor3), _functor4(functor4){
    jatekvege=false;
     _tablameret=c;
     _kockameret=d;
}

void Amobatabla::bumm(event ev){
    if(!jatekvege){
        if(((ev.pos_y-_helyy)%_kockameret>1 && (ev.pos_x-_helyx)%_kockameret>1)&&(ev.pos_x>=_helyx && ev.pos_x<=_tablameret*_kockameret+_helyx && ev.pos_y>=_helyy && ev.pos_y<=_kockameret*_tablameret+_helyy)){
            _functor((ev.pos_y-_helyy)/_kockameret,(ev.pos_x-_helyx)/_kockameret);
        }
    }else{
        if(ev.pos_x>=_tablameret*_kockameret+_helyx+31 && ev.pos_x<=_tablameret*_kockameret+_helyx+231 && ev.pos_y>=50 && ev.pos_y<=80){
            jatekvege=false;
            _functor4();
        }
    }
}

void Amobatabla::kirajzol(int XX,int YY){
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
        gout<<move_to(_tablameret*_kockameret+_helyx+31,50)<<color(255,255,255)<<box(200,30);
        gout<<move_to(_tablameret*_kockameret+_helyx+35,70)<<color(0,0,0)<<text("Katt ide az uj jatekhoz!");
    }
    if(nyert==1){
        gout<<move_to(_tablameret*_kockameret+_helyx+40,29)<<color(255,0,0)<<text("Nyert a piros játékos!");

    }else if(nyert==2){
        gout<<move_to(_tablameret*_kockameret+_helyx+41,31)<<color(0,0,255)<<text("Nyert a kék játékos!");

    }else if(nyert==3){
        gout<<move_to(_tablameret*_kockameret+_helyx+42,32)<<color(128,128,128)<<text("Döntetlen!");
    }
}
