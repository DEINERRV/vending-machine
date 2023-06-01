//
// Created by deine on 9/4/2020.
//

#ifndef PROGRA2_PROJECT_01_DELTA_MENUADMINISTRADOR_H
#define PROGRA2_PROJECT_01_DELTA_MENUADMINISTRADOR_H


#include"IMaquinaAdministradora.h"
#include"IMenu.h"
#include"Maquina.h"

class MenuAdministrador:public IMenu {
private:
    IMaquinaAdministradora *maquina;
public:
    MenuAdministrador(IMaquinaAdministradora * = nullptr);

    ~MenuAdministrador();

    IMaquinaAdministradora *getMaquina();

    void setMaquina(IMaquinaAdministradora *);

    void mostrar();

private:
    void ingresarDinero();

    void retirarDinero();

    void consultarDinero()const;

    void agregarProvisiones();

    void disminuirProvisiones();

    void eliminarDelTodoUnProducto();

    void informacionMaquina();
};


#endif //PROGRA2_PROJECT_01_DELTA_MENUADMINISTRADOR_H
