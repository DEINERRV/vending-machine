//
// Created by Chris on 8/29/2020.
//

#ifndef PROYECTOS_PRODUCTOPERECEDERO_H
#define PROYECTOS_PRODUCTOPERECEDERO_H

#include<conio.h>
#include<string.h>
#include "Producto.h"
#include "IProductoGeneral.h"

struct fecha {
    int dia;
    int mes;
    int anho;
};


class ProductoPerecedero : public Producto, IProductoGeneral{
private:
    int dia;
    int mes;
    int anho;
    fecha fechaVen;
    int aplicacionDelDescuento()  const override;

public:
    ProductoPerecedero();
    ProductoPerecedero(string, int, int, int, int, int);
    virtual ~ProductoPerecedero();

    int getDia();
    void setDia(int);

    int getMes();
    void setMes(int);

    int getAnho();
    void setAnho(int);

    int fechaVencimiento(fecha, fecha);

    bool Vencimiento(fecha const&, fecha const&);

    std::string toString() const override;
};


#endif //PROYECTOS_PRODUCTOPERECEDERO_H
