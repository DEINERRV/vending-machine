//
// Created by Chris on 8/26/2020.
//

#ifndef PROYECTOS_PRODUCTONOPERECEDERO_H
#define PROYECTOS_PRODUCTONOPERECEDERO_H

#include "Producto.h"
#include "IProductoGeneral.h"

class ProductoNoPerecedero : public Producto, IProductoGeneral {
private:
    int aplicacionDelDescuento() const override;

public:
    ProductoNoPerecedero(string, int, int);

    ProductoNoPerecedero();

    virtual ~ProductoNoPerecedero();

    std::string toString() const override;
};


#endif //PROYECTOS_PRODUCTONOPERECEDERO_H
