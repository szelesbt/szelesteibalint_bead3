#include <iostream>

#include "jatekmester.h"

using namespace std;

Jatekmester::Jatekmester(int meret){
    vector<vector<int>> matrix(meret, vector<int>(meret));
    allapot=matrix;
    aktualisjatekos=1;
    _meret=meret;
    gyoztes=0;
//matrix ki
    for(int i=0;i<meret;i++){
        for(int j=0;j<meret;j++){
            cout<<" "<<allapot[i][j];
        }
        cout<<endl;
    }
}

void Jatekmester::lepes(int hova_i, int hova_j){
    if(allapot[hova_i][hova_j]==0){
        allapot[hova_i][hova_j]=aktualisjatekos;

        //van-e 5
        //fugg
        int fugg=1;
        int egymasmellett=1;
        for(int i=1;i<5 && hova_i-i>=0 && allapot[hova_i-i][hova_j]==aktualisjatekos;i++)
        {
            egymasmellett++;
            if(egymasmellett>fugg){
                fugg=egymasmellett;
            }
        }
        for(int i=1;i<5 && hova_i+i<_meret && allapot[hova_i+i][hova_j]==aktualisjatekos;i++)
        {
            egymasmellett++;
            if(egymasmellett>fugg){
                fugg=egymasmellett;
            }
        }
        cout<<fugg<<endl;
        //viz
        int viz=1;
        egymasmellett=1;
        for(int j=1;j<5 && hova_j-j>=0 && allapot[hova_i][hova_j-j]==aktualisjatekos;j++)
        {
            egymasmellett++;
            if(egymasmellett>viz){
                viz=egymasmellett;
            }
        }
        for(int j=1;j<5 && hova_j+j<_meret && allapot[hova_i][hova_j+j]==aktualisjatekos;j++)
        {
            egymasmellett++;
            if(egymasmellett>viz){
                viz=egymasmellett;
            }
        }
        cout<<viz<<endl;
        //atlo1
        int atlo1=1;
        egymasmellett=1;
        for(int j=1;j<5 && (hova_j-j>=0 && hova_i-j>=0) && allapot[hova_i-j][hova_j-j]==aktualisjatekos;j++)
        {
            egymasmellett++;
            if(egymasmellett>atlo1){
                atlo1=egymasmellett;
            }
        }
        for(int j=1;j<5 && (hova_j+j<_meret && hova_i+j<_meret) && allapot[hova_i+j][hova_j+j]==aktualisjatekos;j++)
        {
            egymasmellett++;
            if(egymasmellett>atlo1){
                atlo1=egymasmellett;
            }
        }
        cout<<atlo1<<endl;
        //atlo2
        int atlo2=1;
        egymasmellett=1;
        for(int j=1;j<5 && (hova_i+j<_meret && hova_j-j>=0) && allapot[hova_i+j][hova_j-j]==aktualisjatekos;j++)
        {
            egymasmellett++;
            if(egymasmellett>atlo2){
                atlo2=egymasmellett;
            }
        }
        for(int j=1;j<5 && (hova_i-j>0 && hova_j+j<_meret) && allapot[hova_i-j][hova_j+j]==aktualisjatekos;j++)
        {
            egymasmellett++;
            if(egymasmellett>atlo2){
                atlo2=egymasmellett;
            }
        }
        cout<<atlo2<<endl;
        if(fugg>=5 || viz>=5 || atlo1>=5 || atlo2>=5){
            gyoztes=aktualisjatekos;
        }

        //masik jon
        if(aktualisjatekos==1){
                aktualisjatekos=2;
        }else{aktualisjatekos=1;}


    }
    //matrix ki
    for(int i=0;i<_meret;i++){
        for(int j=0;j<_meret;j++){
            cout<<" "<<allapot[i][j];
        }
        cout<<endl;
    }
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
