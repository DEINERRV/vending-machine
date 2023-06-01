#ifndef MY_PROJECT_NAME_PRODUCTO_H
#define MY_PROJECT_NAME_PRODUCTO_H

#include <iostream>
#include <sstream>
using namespace std;

class Producto {
private:
    string nombre;
    int precio;
    int cantidad;

    virtual int aplicacionDelDescuento() const;
public:
    Producto();
    Producto(string,int,int);
    virtual ~Producto();

    string getNombre() const;
    void setNombre(string);

    int getPrecio() const;
    void setPrecio(int);

    int getCantidad() const;
    void setCantidad(int);

    string toString() const;
};

#endif //MY_PROJECT_NAME_PRODUCTO_H