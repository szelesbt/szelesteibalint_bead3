#include <iostream>

#include "jatekmester.h"

using namespace std;

const int collect(5);

Jatekmester::Jatekmester(int meret){
    vector<vector<int>> matrix(meret, vector<int>(meret));
    allapot=matrix;
    aktualisjatekos=1;
    _meret=meret;
    gyoztes=0;
}

void Jatekmester::lepes(int hova_i, int hova_j){
    if(allapot[hova_i][hova_j]==0){
        allapot[hova_i][hova_j]=aktualisjatekos;

        //fuggolegs
        int fugg=1;
        for(int i=1;i<collect && hova_i-i>=0 && allapot[hova_i-i][hova_j]==aktualisjatekos;i++){
            fugg++;
        }
        for(int i=1;i<collect && hova_i+i<_meret && allapot[hova_i+i][hova_j]==aktualisjatekos;i++){
            fugg++;
        }
        //cout<<fugg<<endl;
        //vizszintes
        int viz=1;
        for(int j=1;j<collect && hova_j-j>=0 && allapot[hova_i][hova_j-j]==aktualisjatekos;j++){
            viz++;
        }
        for(int j=1;j<collect && hova_j+j<_meret && allapot[hova_i][hova_j+j]==aktualisjatekos;j++){
            viz++;
        }
        //cout<<viz<<endl;
        //atlo1
        int atlo1=1;
        for(int j=1;j<collect && (hova_j-j>=0 && hova_i-j>=0) && allapot[hova_i-j][hova_j-j]==aktualisjatekos;j++){
            atlo1++;
        }
        for(int j=1;j<collect && (hova_j+j<_meret && hova_i+j<_meret) && allapot[hova_i+j][hova_j+j]==aktualisjatekos;j++){
            atlo1++;
        }
        //cout<<atlo1<<endl;
        //atlo2
        int atlo2=1;
        for(int j=1;j<collect && (hova_i+j<_meret && hova_j-j>=0) && allapot[hova_i+j][hova_j-j]==aktualisjatekos;j++){
            atlo2++;
        }
        for(int j=1;j<collect && (hova_i-j>=0 && hova_j+j<_meret) && allapot[hova_i-j][hova_j+j]==aktualisjatekos;j++){
            atlo2++;
        }
        //cout<<atlo2<<endl;

        if(fugg>=collect || viz>=collect || atlo1>=collect || atlo2>=collect){
            gyoztes=aktualisjatekos;
        }
        //matrix tele
        bool vanhely=false;
        for(int i=0;i<_meret && !vanhely;i++){
            for(int j=0;j<_meret && !vanhely;j++){
                if(allapot[i][j]==0){
                    vanhely=true;
                }
            }
        }
        if(!vanhely){
            gyoztes=3;
        }

        //masik jon
        if(aktualisjatekos==1){
                aktualisjatekos=2;
        }else{aktualisjatekos=1;}


    }
    /*//matrix ki
    for(int i=0;i<_meret;i++){
        for(int j=0;j<_meret;j++){
            cout<<" "<<allapot[i][j];
        }
        cout<<endl;
    }*/
}

int Jatekmester::kievagy(int kocek_i, int kocek_j){
    return allapot[kocek_i][kocek_j];
}

void::Jatekmester::reset(){
    for(int i=0;i<_meret;i++){
        for(int j=0;j<_meret;j++){
            allapot[i][j]=0;
        }
    }
    gyoztes=0;
}
