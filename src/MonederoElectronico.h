//
// Created by deine on 8/26/2020.
//

#ifndef PROGRA2_PROJECT_01_DELTA_MONEDEROELECTRONICO_H
#define PROGRA2_PROJECT_01_DELTA_MONEDEROELECTRONICO_H

#include<vector>
#include"Vuelto.h"//ya aqui este archivo esta el using namespace y el #include<iostream

class MonederoElectronico {

private:
    int dinero;
    vector<MonedaBillete> coinList;
public:
    MonederoElectronico(int = 0, vector<MonedaBillete> = {});
    ~MonederoElectronico();

    void setDinero(int);
    int getDinero();

    void setCoinlist(vector<MonedaBillete>);
    vector<MonedaBillete> getCoinList();

    vector<Vuelto> desgloceVuelto(int,int);
    string toString();

};


#endif //PROGRA2_PROJECT_01_DELTA_MONEDEROELECTRONICO_H
