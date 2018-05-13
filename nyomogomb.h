#ifndef NYOMOGOMB_H_INCLUDED
#define NYOMOGOMB_H_INCLUDED

#include <functional>
#include "widgetek.h"
#include "ablak.h"

class Nyomogomb : public Widget{
protected:
    int kie;
    std::string _felirat;
   //  std::function<void()> _functor;//, _functor2;
public:
    Nyomogomb(int a, int b, int c, int d, std::string s);
    Nyomogomb(int a, int b, int c, int d, std::string s, std::function<void()> functor, std::function<void()> functor2);
    virtual void kirajzol() /*const*/;
    virtual void akcio(genv::event ev);
    virtual void bumm(genv::event ev)=0;
   virtual std::string getter();
   void kievagyok(int x){kie=x;}
} ;

class Amobatabla : public Nyomogomb{
protected:
    int _tablameret, _kockameret;
    bool jatekvege;
    std::function<void(int u, int v)>  _functor;
    std::function<int(int u2, int v2)>  _functor2;
    std::function<int()>  _functor3;
    std::function<void()>  _functor4;
public:
    Amobatabla(int a, int b, int c, int d, std::string s, std::function<void(int hol_x, int hol_y)> functor, std::function<int(int hol_x2, int hol_y2)> functor2, std::function<int()> functor3, std::function<void()>  functor4);
    virtual void bumm(genv::event ev);
    virtual void kirajzol();
};

#endif // NYOMOGOMB_H_INCLUDED
