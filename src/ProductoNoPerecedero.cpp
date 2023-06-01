//
// Created by Chris on 8/26/2020.
//

#include <sstream>
#include "ProductoNoPerecedero.h"

ProductoNoPerecedero::ProductoNoPerecedero(string name,int precio,int cantidad)
     :Producto(name,precio,cantidad){}

ProductoNoPerecedero::ProductoNoPerecedero(){}

ProductoNoPerecedero::~ProductoNoPerecedero(){}

int ProductoNoPerecedero::aplicacionDelDescuento() const{
    return (getPrecio() - (getPrecio() * 0.20));
}

std::string ProductoNoPerecedero::toString() const{
    stringstream s;
    s<<"-- Producto no perecedero --"<<endl
    <<Producto::toString()<<endl;
    return s.str();
}