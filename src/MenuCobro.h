//
// Created by deine on 9/5/2020.
//

#ifndef PROGRA2_PROJECT_01_DELTA_MENUCOBRO_H
#define PROGRA2_PROJECT_01_DELTA_MENUCOBRO_H

#include"Maquina.h"
#include "IMenu.h"


class MenuCobro : public IMenu {

private:
    Maquina *maquina;

public:
    MenuCobro(Maquina * = NULL);

    ~MenuCobro();

    Maquina *getMaquina();

    void setMaquina(Maquina *);

    void mostrar();

private:
    void mostrarProductos();

    void realizarCompra();

};


#endif //PROGRA2_PROJECT_01_DELTA_MENUCOBRO_H
