#ifndef PROGRA2_PROJECT_01_DELTA_IMAQUINAADMINISTRADORA_H
#define PROGRA2_PROJECT_01_DELTA_IMAQUINAADMINISTRADORA_H

#include "sstream"
#include "MonederoElectronico.h"

using std::string;

class IMaquinaAdministradora {
public:
    virtual ~IMaquinaAdministradora();

    virtual int getIdentificador() = 0;

    virtual void setNombre(const string &nombre) = 0;

    virtual string getNombre() = 0;

    virtual MonederoElectronico &getMonederoElectronico() = 0;

    virtual void setMonederoElectronico(const MonederoElectronico &monederoElectronico) = 0;

    virtual bool agregarProvisiones(string idProducto, int cantidad) = 0;

    virtual bool disminuirProvisiones(string idProducto, int cantidad) = 0;

    virtual bool borrar(string id) = 0;

    virtual void ingresarDinero(int cantidad) = 0;

    virtual void retirarDinero(int cantidad) = 0;

    virtual string toString() = 0;
};

#endif //PROGRA2_PROJECT_01_DELTA_IMAQUINAADMINISTRADORA_H