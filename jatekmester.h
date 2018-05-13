#ifndef JATEKMESTER_H_INCLUDED
#define JATEKMESTER_H_INCLUDED

#include <vector>

using namespace std;

class Jatekmester {
private:
    vector<vector<int>> allapot;
    int aktualisjatekos;
    int _meret;
    int gyoztes;
public:
    Jatekmester(int meret);
    void lepes(int hova_i, int hova_j);
    int kievagy(int kocek_i, int kocek_j);
    int nyertes(){return gyoztes;}
    void reset();
};


#endif // JATEKMESTER_H_INCLUDED
